/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#ifndef EVENTROOMLIST_HPP_
#define EVENTROOMLIST_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

namespace room_list {

/** @brief The callback function to go back to menu */
void receive_backward_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);

/** @brief The callback function when clicking on a room */
void receive_room_click_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

/** @brief The callback function to create a room */
void receive_create_room_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);
void receive_room_receive_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt);

}

#endif /* !EVENT_HPP_ */
