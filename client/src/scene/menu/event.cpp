/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#include "Menu.hpp"
#include "event.hpp"

namespace menu {

void receive_event_start(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    Menu *menu = reinterpret_cast<Menu*>(obj);
    menu->start_game_evt();
}

void receive_event_quit(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    Menu *menu = reinterpret_cast<Menu*>(obj);
    menu->quit_game_evt();
    coord.quit();
}

}