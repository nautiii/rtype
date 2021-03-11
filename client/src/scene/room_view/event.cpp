/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#include "event.hpp"
#include "RoomView.hpp"

namespace room_view {

void receive_room_start_click_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    RoomView *room = reinterpret_cast<RoomView*>(obj);
    room->start();
}

void receive_room_start_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    RoomView *room = reinterpret_cast<RoomView*>(obj);
    room->go_to_game();
}

}