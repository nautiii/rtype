/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** event
*/

#include "event.hpp"
#include "RoomList.hpp"
#include "event/ClickableClickEvent.hpp"
#include "event/NetworkEvent.hpp"
#include "network/protocol/Protocol.hpp"

namespace room_list {

void receive_backward_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    RoomList *room = reinterpret_cast<RoomList*>(obj);
    room->go_to_menu();
}

void receive_room_click_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    RoomList *room = reinterpret_cast<RoomList*>(obj);
    event::ClickableClickEvent &event = reinterpret_cast<event::ClickableClickEvent&>(evt);
    room->room_click(event.entity);
}

void receive_create_room_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    RoomList *room = reinterpret_cast<RoomList*>(obj);
    room->create_room();
}

void receive_room_receive_event(void *obj, ecs::Coordinator &coord, const mediator::IEvent &evt)
{
    RoomList *room = reinterpret_cast<RoomList*>(obj);
    const event::NetworkEvent &event = reinterpret_cast<const event::NetworkEvent&>(evt);
    structureProtocol::roomList_t *data = static_cast<structureProtocol::roomList_t*>(event.data);
    room->add_room(data->name, data->id);
}

}