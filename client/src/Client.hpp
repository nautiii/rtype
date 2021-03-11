/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <vector>
#include <boost/asio.hpp>
#include <future>
#include <set>
#include "engine/Engine.hpp"
#include "network/protocol/Protocol.hpp"

using namespace boost::asio;
using namespace boost::system;

/** @brief Contains every objects for the network */
namespace network {

class Exchange;
typedef std::shared_ptr<Exchange> exchangeShared_t;

/** @brief The client class */
class Client {
    public:
        Client(io_context &ioContext, const std::string &ip, const std::string &port, std::shared_ptr<engine::Engine> eng);
        ~Client();

        /** @brief The function that will receive data from the server */
        void startRecv();

        /** @brief Retrieve the exchange */
        std::weak_ptr<Exchange> getExchange();

        /** @brief The function to send data to server */
        void send(int dest, int size, void *data, protocol::PacketType type);
        void add_entity(char *uuid, ecs::Entity entity);
        bool get_entity(char *uuid, ecs::Entity &entity);

    private:
        void _handleRecv(ip::udp::endpoint endpoint, const protocol::UdpPacket &packet);
        struct networked_entity {
            char uuid[protocol::UUID_SIZE];
            ecs::Entity entity;
        };

        exchangeShared_t _exchange;
        ip::udp::endpoint _endpoint;
        std::mutex _mutex;
        int room_id;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
        std::shared_ptr<engine::Engine> _eng;
        std::vector<networked_entity> _map;
};

}

#endif /* !CLIENT_HPP_ */
