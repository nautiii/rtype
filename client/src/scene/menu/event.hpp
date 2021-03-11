/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#ifndef EVENTMENU_HPP_
#define EVENTMENU_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

/** @brief Contain every objects for the menu*/
namespace menu {

/** @brief The callback of the start event */
void receive_event_start(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);

/** @brief The callback of the quit event */
void receive_event_quit(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);

}


#endif /* !EVENT_HPP_ */
