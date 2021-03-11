/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Client
*/

#include <cstring>
#include "Client.hpp"
#include "network/Exchange.hpp"
#include "client_network_event.hpp"
#include "network/protocol/Protocol.hpp"
#include "interpreter/interpreter.hpp"

namespace network {

Client::Client(io_context &ioContext, const std::string &ip, const std::string &port, std::shared_ptr<engine::Engine> eng): room_id(-1), _eng(eng)
{
    _mediator = eng->get_mediator();
    ip::udp::resolver resolver(ioContext);
    ip::udp::resolver::query query(ip::udp::v4(), ip, port);
    _endpoint = *resolver.resolve(query);
    _exchange = std::make_shared<Exchange>(ioContext);
    protocol::UdpPacket packet(0, 0, NULL, protocol::PacketType::TRY_CONNECT);
    _exchange->send(_endpoint, packet);
    eng->get_mediator()->add_event_listener("send_network_event", this, receive_client_network_event);
    startRecv();
}

Client::~Client()
{
}

void Client::startRecv()
{
    while (true)
    {
        try {
            _exchange->recv(_endpoint);
        } catch (std::exception) {
            continue;
        }
        std::thread thread(&Client::_handleRecv, this, _endpoint, *_exchange->getPacket());
        thread.detach();
    }
}

void Client::_handleRecv(ip::udp::endpoint endpoint, const protocol::UdpPacket &packet)
{
    _mutex.lock();
    interpreter::interpreter(this, _eng, _mediator, packet);
    _mutex.unlock();
}

std::weak_ptr<Exchange> Client::getExchange()
{
    return (_exchange);
}

void Client::send(int dest, int size, void *data, protocol::PacketType type)
{
    if (dest != -1)
        room_id = dest;
    protocol::UdpPacket packet(room_id, size, data, type);
    _exchange->send(_endpoint, packet);
}

void Client::add_entity(char *uuid, ecs::Entity entity)
{
    networked_entity ent;
    std::memcpy(ent.uuid, uuid, protocol::UUID_SIZE);
    ent.entity = entity;
    _map.push_back(ent);
}

bool Client::get_entity(char *uuid, ecs::Entity &entity)
{
    for (auto &elem: _map) {
        if (std::strncmp(elem.uuid, uuid, protocol::UUID_SIZE) == 0) {
            entity = elem.entity;
            return (true);
        }
    }
    return (false);
}

}