/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#include "event.hpp"
#include "Clickable.hpp"

namespace ecssystem {

void receive_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    Clickable *system = reinterpret_cast<Clickable*>(obj);
    system->receive_click_evt(evt, coord);
}

}