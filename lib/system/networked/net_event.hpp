/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** net_event
*/

#ifndef NET_EVENT_HPP_
#define NET_EVENT_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

namespace ecssystem {

void receive_pos_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

}

#endif /* !NET_EVENT_HPP_ */
