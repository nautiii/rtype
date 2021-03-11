/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** client_network_event
*/

#include "client_network_event.hpp"
#include "event/NetworkEvent.hpp"
#include "Client.hpp"

void receive_client_network_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    const event::NetworkEvent &nevent = reinterpret_cast<const event::NetworkEvent&>(evt);
    Client *client = reinterpret_cast<Client*>(obj);

    client->send(nevent.dest, nevent.size, nevent.data, nevent.type);
}