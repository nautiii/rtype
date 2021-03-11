/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** net_event
*/

#include "net_event.hpp"
#include "event/NetworkEntityUpdate.hpp"
#include "Networked.hpp"
#include "network/protocol/Protocol.hpp"

namespace ecssystem {

void receive_pos_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    event::NetworkEntityUpdate &event = reinterpret_cast<event::NetworkEntityUpdate&>(evt);
    Networked *net = reinterpret_cast<Networked*>(obj);
    structureProtocol::posUpdate_t *pos = reinterpret_cast<structureProtocol::posUpdate_t*>(event.data);
    net->update_pos(coord, event.entity, pos->pos, pos->dir);
}

}