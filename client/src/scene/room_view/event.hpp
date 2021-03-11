/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#ifndef EVENTROOM_VIEW_HPP_
#define EVENTROOM_VIEW_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"


namespace room_view {

void receive_room_start_click_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);
void receive_room_start_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

}

#endif /* !EVENT_HPP_ */
