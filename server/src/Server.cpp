/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Server
*/

#include "Server.hpp"
#include "network/Exchange.hpp"
#include "Session.hpp"
#include "Gateway.hpp"

namespace network {

Server::Server(io_context &ioContext, const uint32_t port):
_exchange(std::make_shared<Exchange>(ioContext, port)),
_gateway(std::make_shared<Gateway>()),
_sessions(std::make_shared<std::set<sessionShared_t>>()),
_interpreter(_gateway, _sessions)
{
    _startRecv();
}

Server::~Server()
{
}

bool Server::isExistingUser(const ip::udp::endpoint &endpoint)
{
    if (_sessions->empty())
        return false;
    for (sessionShared_t session : *_sessions)
        if (session->getEndpoint() == endpoint)
            return true;
    return false;
}

void Server::_startRecv()
{
    ip::udp::endpoint endpoint;

    while (true)
    {
        try {
            _exchange->recv(endpoint);
        } catch (std::exception) {
            continue;
        }
        std::thread thread(&Server::_handleRecv, this, endpoint, _exchange->getPacket());
        thread.detach();
    }
}

void Server::_handleRecv(ip::udp::endpoint endpoint, std::shared_ptr<protocol::UdpPacket> packet)
{
    _mutex.lock();
    if (!isExistingUser(endpoint))
        _createUser(endpoint, "User");
    _interpreter.process(*packet, endpoint);
    std::cout << packet->dst << std::endl;
    
    _mutex.unlock();
}

void Server::_createUser(const ip::udp::endpoint &endpoint, const std::string &name)
{
    _sessions->insert(std::make_shared<Session>(endpoint, _exchange));
}

}