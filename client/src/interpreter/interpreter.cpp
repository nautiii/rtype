/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** interpreter
*/

#include <yaml-cpp/yaml.h>
#include "engine/debug.hpp"
#include "interpreter.hpp"
#include "event/NetworkReceiveEvent.hpp"
#include "event/NetworkEntityUpdate.hpp"

namespace interpreter {

void interpreter(network::Client *client, std::shared_ptr<engine::Engine> eng, std::shared_ptr<mediator::MediatorEvent> mediator, const protocol::UdpPacket &packet)
{
    auto elem = network_event_name.find(packet.type);

    if (elem == network_event_name.end()) {
        MERROR("Unknow network id: " << packet.type);
        return;
    }
    if (packet.type == protocol::CREATE_ENTITY) {
        structureProtocol::createEntity_t *data = static_cast<structureProtocol::createEntity_t*>(packet.data);
        YAML::Node node = YAML::Load(data->node);

        std::cout << "create net entity" << std::endl;
        YAML::Node entity;
        entity["components"] = node;
        ecs::Entity entityid = eng->create_entity(data->uuid, entity);
        client->add_entity(data->uuid, entityid);
    } else if (packet.type == protocol::PLAYER_MOVE) {
        structureProtocol::posUpdate_t *data = static_cast<structureProtocol::posUpdate_t*>(packet.data);
        ecs::Entity entity;
        if (!client->get_entity(data->uuid, entity)) {
            std::cerr << "Not net entity with given id" << std::endl;
            return;
        }
        std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEntityUpdate>(elem->second, 0, packet.data, protocol::PLAYER_MOVE, entity);
        mediator->add_event(event);
    } else {
        std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkReceiveEvent>(elem->second, 0, packet.data, protocol::CREATE_ROOM);
        mediator->add_event(event);
    }
}

}