/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Interpreter
*/

#include <cstring>
#include "Interpreter.hpp"

#include "Gateway.hpp"
#include "Session.hpp"
#include "Room.hpp"

namespace protocol {

Interpreter::Interpreter(gatewayWeak_t gateway, sessionsWeak_t sessions):
_gateway(gateway),
_sessions(sessions)
{
    _interpreter[TRY_CONNECT] = &Interpreter::_tryConnect;
    _interpreter[GET_ROOMLIST] = &Interpreter::_getRoomList;
    _interpreter[JOIN_ROOM] = &Interpreter::_joinRoom;
    _interpreter[CREATE_ROOM] = &Interpreter::_createRoom;
    _interpreter[UPDATE_STATUS] = &Interpreter::_sendToRoom;
    _interpreter[LAUNCH_GAME] = &Interpreter::_sendToRoom;
    _interpreter[KILL_MOB] = &Interpreter::_sendToRoom;
    _interpreter[DEAD] = &Interpreter::_sendToRoom;
    _interpreter[SHOOT] = &Interpreter::_sendToRoom;
    _interpreter[MOVE] = &Interpreter::_sendToRoom;
    _interpreter[DAMAGE_TAKEN] = &Interpreter::_sendToRoom;
    _interpreter[SCORE] = &Interpreter::_sendToRoom;
    _interpreter[TOUCH_MOB] = &Interpreter::_sendToRoom;
    _interpreter[CREATE_ENTITY] = &Interpreter::_sendToRoom;
    _interpreter[PLAYER_MOVE] = &Interpreter::_sendToRoom;
}

Interpreter::~Interpreter()
{
}

void Interpreter::process(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    int pid = packet.type;
    PacketType castEnum = static_cast<PacketType>(pid);
    auto pos = _interpreter.find(castEnum);

    if (pos != _interpreter.end())
        (pos->second)(this, packet, endpoint);
}

sessionShared_t Interpreter::_findSessions(ip::udp::endpoint &endpoint)
{
    sessionsShared_t sessions = _sessions.lock();
    if (!sessions)
        return NULL;

    if (sessions->empty())
        return NULL;
    for (sessionShared_t session : *sessions)
        if (session->getEndpoint() == endpoint)
            return session;
    return NULL;
}

void Interpreter::_tryConnect(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    sessionShared_t session = _findSessions(endpoint);

    if (session) {
        protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::CONNECT_OK);
        session->send(sendPacket);

        std::cout << "Test: TRY_CONNECT: OK" << std::endl;
        return;
    }

    protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::CONNECT_ERR);
    session->send(sendPacket);
    std::cout << "Test: TRY_CONNECT: K0" << std::endl;
}


void Interpreter::_getRoomList(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    sessionShared_t session = _findSessions(endpoint);
    gatewayShared_t gateway = _gateway.lock();

    if (session && gateway) {
        std::vector<std::string> room_names = gateway->getRoomListNames();
        std::vector<uint16_t> room_ids = gateway->getRoomListIds();

        for (int i = 0; i < room_names.size(); i++) {
            structureProtocol::roomList_t roomList;
            std::memset(&roomList.name, '\0', protocol::MAX_NAME_LENGTH);
            std::memcpy(&roomList.name, room_names[i].c_str(), room_names[i].size());
            roomList.id = room_ids[i];
            protocol::UdpPacket sendPacket(0, sizeof(roomList), reinterpret_cast<void*>(&roomList), protocol::PacketType::ROOMLIST_OK);
            session->send(sendPacket);
        }

        std::cout << "Test: GET_ROOM: OK" << std::endl;
        return;
    }

    protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::ROOMLIST_ERR);
    session->send(sendPacket);
    std::cout << "Test: GET_ROOM: KO" << std::endl;
}

void Interpreter::_joinRoom(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    sessionShared_t session = _findSessions(endpoint);
    gatewayShared_t gateway = _gateway.lock();

    if (session && gateway) {
        roomShared_t room = gateway->getRoom(packet.dst);
        if (room && room->addSession(session)) {
            protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::ROOM_JOIN_OK);
            room->sendAll(sendPacket);

            std::cout << "Test: JOIN_ROOM: OK" << std::endl;
            return;
        }
    }

    protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::ROOM_JOIN_ERR);
    session->send(sendPacket);
    std::cout << "Test: JOIN_ROOM: KO" << std::endl;
}

void Interpreter::_createRoom(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    sessionShared_t session = _findSessions(endpoint);
    gatewayShared_t gateway = _gateway.lock();
    sessionsShared_t sessions = _sessions.lock();

    if (session && gateway && sessions) {
        int id = 0;
        std::string name = gateway->createRoom(id);
        structureProtocol::roomList_t roomList;
        std::memset(&roomList.name, '\0', protocol::MAX_NAME_LENGTH);
        std::memcpy(&roomList.name, name.c_str(), name.size());
        roomList.id = id;
        protocol::UdpPacket sendPacket(0, sizeof(roomList), &roomList, protocol::PacketType::ROOM_CREATE_OK);
        for (sessionShared_t sessionTmp : *sessions)
            sessionTmp->send(sendPacket);

        std::cout << "Test: CREATE_ROOM: OK" << std::endl;
        return;
    }

    protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::ROOM_CREATE_ERR);
    session->send(sendPacket);
    std::cout << "Test: CREATE_ROOM: KO" << std::endl;
}

void Interpreter::_sendToRoom(UdpPacket &packet, ip::udp::endpoint &endpoint)
{
    sessionShared_t session = _findSessions(endpoint);
    gatewayShared_t gateway = _gateway.lock();

    if (session && gateway) {
        roomShared_t room = gateway->getRoom(packet.dst);
        if (room) {
            room->sendOther(packet, endpoint);
            protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::SEND_TO_ROOM_OK);
            session->send(sendPacket);

            std::cout << "Test: SEND_TO_ROOM: OK" << std::endl;
            return;
        }
    }

    protocol::UdpPacket sendPacket(0, 0, NULL, protocol::PacketType::SEND_TO_ROOM_ERR);
    session->send(sendPacket);
    std::cout << "Test: CREATE_ROOM: KO" << std::endl;
}

}