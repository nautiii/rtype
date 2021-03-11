/*
** EPITECH PROJECT, 2020
** src
** File description:
** Room
*/

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <boost/asio.hpp>
#include <memory>
#include <set>
#include <string>

#include "network/protocol/Protocol.hpp"

using namespace boost::asio;

/** @brief Contains every objects for the network */
namespace network {

class Session;
typedef std::shared_ptr<Session> sessionShared_t;
typedef std::weak_ptr<Session> sessionWeak_t;

/** @brief The Room class */
class Room {
    public:
        Room(const uint16_t &id, const std::string &name);
        ~Room();

        /** @brief Add a session to a room */
        bool addSession(sessionShared_t session);

        /** @brief Send a packet to the clients */
        void sendAll(protocol::UdpPacket &packet);

        /** @brief Send a packet */
        void sendOther(protocol::UdpPacket &packet, const ip::udp::endpoint &endpoint);

        /** @brief retrieve the id of the room */
        uint16_t getId() { return _id; };

        /** @brief retrieve the name of the room */
        std::string getName() { return _name; };

    private:
        std::set<sessionShared_t> _rooms;
        uint16_t _id;
        std::string _name;
        short _nbUser;
};

}

#endif /* !ROOM_HPP_ */
