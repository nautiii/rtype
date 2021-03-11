/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event_game
*/

#include "event_game.hpp"
#include "event/CollisionEvent.hpp"
#include "Game.hpp"

namespace game {

void receive_collision_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    event::CollisionEvent &event = reinterpret_cast<event::CollisionEvent&>(evt);
    game::Game *game = reinterpret_cast<game::Game*>(obj);
    coord.destroy_entity(event.body1);
    coord.destroy_entity(event.body2);
}

}