/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Session
*/

#ifndef SESSION_HPP_
#define SESSION_HPP_

#include <boost/asio.hpp>
#include "protocol/Protocol.hpp"

using namespace boost::asio;
using namespace boost::system;

/** @brief Contains every objects for the network */
namespace network {

class Exchange;
typedef std::shared_ptr<Exchange> exchangeShared_t;
typedef std::weak_ptr<Exchange> exchangeWeak_t;

/** @brief The Session class */
class Session {
    public:
        Session(const ip::udp::endpoint &endpoint, exchangeWeak_t exchange);
        ~Session();

        /** @brief Send a packet to an endpoint */
        void send(protocol::UdpPacket &packet);

        /** @brief Retrieve the endpoint */
        ip::udp::endpoint getEndpoint() { return _endpoint; };

    private:
        ip::udp::endpoint _endpoint;
        exchangeWeak_t _exchange;
};

}

#endif /* !SESSION_HPP_ */
