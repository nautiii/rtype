/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Session
*/

#include "Session.hpp"
#include "network/Exchange.hpp"

namespace network {

Session::Session(const ip::udp::endpoint &endpoint, exchangeWeak_t exchange):
_endpoint(endpoint),
_exchange(exchange)
{
}

Session::~Session()
{
}

void Session::send(protocol::UdpPacket &packet)
{
    exchangeShared_t exchange = _exchange.lock();
    if (exchange) {
        exchange->send(_endpoint, packet);
    }
}

}