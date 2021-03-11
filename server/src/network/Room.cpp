/*
** EPITECH PROJECT, 2020
** src
** File description:
** Room
*/

#include "Room.hpp"

#include "Session.hpp"

namespace network {

Room::Room(const uint16_t &id, const std::string &name):
_id(id),
_name(name),
_nbUser(0)
{
}

Room::~Room()
{
}

bool Room::addSession(sessionShared_t session)
{
    if (_nbUser < 4) {
        _rooms.insert(session);
        _nbUser++;
        return true;
    }
    return false;
}

void Room::sendAll(protocol::UdpPacket &packet)
{
    for (sessionWeak_t sessionWeak : _rooms) {
        sessionShared_t session = sessionWeak.lock();
        if (session)
            session->send(packet);
    }
}

void Room::sendOther(protocol::UdpPacket &packet, const ip::udp::endpoint &endpoint)
{
        for (sessionWeak_t sessionWeak : _rooms) {
        sessionShared_t session = sessionWeak.lock();
        if (session && session->getEndpoint() != endpoint)
            session->send(packet);
    }
}

}