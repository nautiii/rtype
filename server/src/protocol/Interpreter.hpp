/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Interpreter
*/

#ifndef INTERPRETER_HPP_
#define INTERPRETER_HPP_

#include <boost/asio.hpp>
#include <functional>
#include <map>
#include <set>

#include "network/protocol/Protocol.hpp"

using namespace boost::asio;

namespace network {

class Session;
typedef std::shared_ptr<Session> sessionShared_t;
typedef std::weak_ptr<Session> sessionWeak_t;
typedef std::shared_ptr<std::set<sessionShared_t>> sessionsShared_t;
typedef std::weak_ptr<std::set<sessionShared_t>> sessionsWeak_t;

class Gateway;
typedef std::shared_ptr<Gateway> gatewayShared_t;
typedef std::weak_ptr<Gateway> gatewayWeak_t;

class Room;
typedef std::shared_ptr<Room> roomShared_t;
typedef std::weak_ptr<Room> roomWeak_t;
}

/** @brief Contain every objects for the protocol */
namespace protocol {

/** @brief The interpreter class */
class Interpreter {

    public:
        Interpreter(gatewayWeak_t gateway, sessionsWeak_t sessions);
        ~Interpreter();

        /** @brief Call the right function depending of the packet type */
        void process(UdpPacket &packet, ip::udp::endpoint &endpoint);

    private:
        gatewayWeak_t _gateway;
        sessionsWeak_t _sessions;
        typedef std::function<void(Interpreter*, UdpPacket&, ip::udp::endpoint&)> callBack;
        std::map <PacketType, callBack> _interpreter;

        sessionShared_t _findSessions(ip::udp::endpoint &endpoint);

        void _tryConnect(UdpPacket &packet, ip::udp::endpoint &endpoint);
        void _getRoomList(UdpPacket &packet, ip::udp::endpoint &endpoint);
        void _joinRoom(UdpPacket &packet, ip::udp::endpoint &endpoint);
        void _createRoom(UdpPacket &packet, ip::udp::endpoint &endpoint);
        void _sendToRoom(UdpPacket &packey, ip::udp::endpoint &endpoint);

};

}

#endif /* !INTERPRETER_HPP_ */
