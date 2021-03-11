/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event_game
*/

#ifndef EVENT_GAME_HPP_
#define EVENT_GAME_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"


namespace game {

void receive_collision_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

}

#endif