/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Exchange
*/

#ifndef EXCHANGE_HPP_
#define EXCHANGE_HPP_

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <thread>
#include <iostream>
#include "protocol/Protocol.hpp"

using namespace boost::asio;
using namespace boost::system;

namespace network {

typedef struct reliableData_s {
    ip::udp::endpoint endpoint;
    protocol::UdpPacket packet;
} reliableData_t;

class Exchange
{
    public:
        Exchange(io_context &ioContext, const uint32_t &port);
        Exchange(io_context &ioContext);
        ~Exchange();

        void send(const ip::udp::endpoint &endpoint, protocol::UdpPacket &packet);
        void recv(ip::udp::endpoint &endpoint);

        std::shared_ptr<protocol::UdpPacket> getPacket() { return _packet; };

    private:
        void _handleSend(const error_code& error, std::size_t size);

        ip::udp::socket _socket;
        std::shared_ptr<protocol::UdpPacket> _packet;
};

}

#endif /* !EXCHANGE_HPP_ */
