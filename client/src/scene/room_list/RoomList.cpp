/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** RoomList
*/

#include "RoomList.hpp"
#include "event/ChangeSceneEvent.hpp"
#include "event/NetworkEvent.hpp"
#include "menu/Menu.hpp"
#include "room_view/RoomView.hpp"
#include "event.hpp"

namespace room_list {

RoomList::RoomList(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator): _engine(engine), _mediator(mediator)
{
}

RoomList::~RoomList()
{
    _engine->unload("config/room_list.yml");
    _mediator->remove_event_listener("button_backward_pressed", this);
    _mediator->remove_event_listener("join_button_pressed", this);
    _mediator->remove_event_listener("button_create_room_pressed", this);
    _mediator->remove_event_listener("net_room_create_ok", this);
    _mediator->remove_event_listener("net_room_list_ok", this);
    _engine->get_coord().destroy_group("join_button");
}

void RoomList::init()
{
    _engine->load("config/room_list.yml");
    std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(0, nullptr, protocol::GET_ROOMLIST);
    _mediator->add_event(event);
    _mediator->add_event_listener("button_backward_pressed", this, receive_backward_event);
    _mediator->add_event_listener("join_button_pressed", this, receive_room_click_event);
    _mediator->add_event_listener("button_create_room_pressed", this, receive_create_room_event);
    _mediator->add_event_listener("net_room_create_ok", this, receive_room_receive_event);
    _mediator->add_event_listener("net_room_list_ok", this, receive_room_receive_event);
}

void RoomList::add_room(const std::string &name, int id)
{
    std::string tmp = "{components: {sprite: {texture: \"ressources/ui/forward_button_105.png\"}, transform: {x: 1100, y: " + std::to_string(400 + 150 * _room_list.size()) + ", width: 105, height: 105}, clickable: {signal: \"join_button_pressed\"}}, group: \"join_button\"}";
    std::string lbl = "{components: {label: {font: \"ressources/font/OpenSans-Regular.ttf\", text: \"" + name + "\", font_size: 30}, transform: {x: 800, y: " + std::to_string(440 + 150 * _room_list.size()) + ", width: 105, height: 105}}, group: \"join_button\"}";
    _engine->create_entity("join_room_text_" + std::to_string(_room_list.size()), lbl);
    ecs::Entity entity = _engine->create_entity("join_room_button_" + std::to_string(_room_list.size()), tmp);
    _room_list[entity] = id;
}

void RoomList::go_to_menu()
{
    std::cout << "go to menu " << std::endl;
    std::shared_ptr<event::ChangeSceneEvent> event = std::make_shared<event::ChangeSceneEvent>();
    event->scene = std::make_unique<menu::Menu>(_engine, _mediator);
    std::shared_ptr<mediator::IEvent> mevent = event;
    _mediator->add_event(mevent);
}

void RoomList::room_click(ecs::Entity entity)
{
    std::cout << "room click " << _room_list[entity] << std::endl;
    std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(0, nullptr, protocol::JOIN_ROOM, _room_list[entity]);
    _mediator->add_event(event);
    std::shared_ptr<event::ChangeSceneEvent> cevent = std::make_shared<event::ChangeSceneEvent>();
    cevent->scene = std::make_unique<room_view::RoomView>(_engine, _mediator);
    std::shared_ptr<mediator::IEvent> mevent = cevent;
    _mediator->add_event(mevent);
}

void RoomList::create_room()
{
    std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(0, nullptr, protocol::CREATE_ROOM);
    _mediator->add_event(event);
}

}