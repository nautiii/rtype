/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#ifndef EVENTCLICKABLE_HPP_
#define EVENTCLICKABLE_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** The function that will call the Clickable::receive_click_evt */
void receive_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

}

#endif /* !EVENT_HPP_ */
