/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** client_network_event
*/

#ifndef CLIENT_NETWORK_EVENT_HPP_
#define CLIENT_NETWORK_EVENT_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

/** @brief The callback function to send an event in the network */
void receive_client_network_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);

#endif /* !CLIENT_NETWORK_EVENT_HPP_ */
