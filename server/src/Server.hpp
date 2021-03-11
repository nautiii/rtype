/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <boost/asio.hpp>
#include <thread>
#include <mutex>
#include <set>

#include "network/protocol/Protocol.hpp"
#include "Interpreter.hpp"

using namespace boost::asio;
using namespace boost::system;

namespace network {

class Exchange;
typedef std::shared_ptr<Exchange> exchangeShared_t;
typedef std::weak_ptr<Exchange> exchangeWeak_t;

class Session;
typedef std::shared_ptr<Session> sessionShared_t;
typedef std::weak_ptr<Session> sessionWeak_t;
typedef std::shared_ptr<std::set<sessionShared_t>> sessionsShared_t;
typedef std::weak_ptr<std::set<sessionShared_t>> sessionsWeak_t;

class Gateway;
typedef std::shared_ptr<Gateway> gatewayShared_t;
typedef std::weak_ptr<Gateway> gatewayWeak_t;

class Server
{

    public:
        Server(io_context &ioContext, const uint32_t port);
        ~Server();

        bool isExistingUser(const ip::udp::endpoint &endpoint);

    private:
        void _startRecv();
        void _handleRecv(ip::udp::endpoint endpoint, std::shared_ptr<protocol::UdpPacket> packet);
        void _createUser(const ip::udp::endpoint &endpoint, const std::string &name);
        
        exchangeShared_t _exchange;
        gatewayShared_t _gateway;
        sessionsShared_t _sessions;
        protocol::Interpreter _interpreter;
        std::mutex _mutex;
};

}

#endif /* !SERVER_HPP_ */