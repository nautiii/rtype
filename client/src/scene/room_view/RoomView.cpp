/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** RoomView
*/

#include "RoomView.hpp"
#include "event.hpp"
#include "network/protocol/Protocol.hpp"
#include "event/NetworkEvent.hpp"
#include "event/ChangeSceneEvent.hpp"
#include "game/Game.hpp"

namespace room_view {

RoomView::RoomView(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator): _engine(engine), _mediator(mediator)
{
}

RoomView::~RoomView()
{
    _engine->unload("config/room_view.yml");
    _mediator->remove_event_listener("button_start_game", this);
    _mediator->remove_event_listener("net_send_to_room_ok", this);
    _mediator->remove_event_listener("net_launch_ok", this);
}

void RoomView::init()
{
    _engine->load("config/room_view.yml");
    _mediator->add_event_listener("button_start_game", this, receive_room_start_click_event);
    _mediator->add_event_listener("net_send_to_room_ok", this, receive_room_start_event);
    _mediator->add_event_listener("net_launch_ok", this, receive_room_start_event);
}

void RoomView::start()
{
    std::cout << "start" << std::endl;
    std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(0, nullptr, protocol::LAUNCH_GAME);
    _mediator->add_event(event);
    _engine->load("config/wave.yml");
}

void RoomView::go_to_game()
{
    std::shared_ptr<event::ChangeSceneEvent> cevent = std::make_shared<event::ChangeSceneEvent>();
    cevent->scene = std::make_unique<game::Game>(_engine, _mediator);
    std::shared_ptr<mediator::IEvent> mevent = cevent;
    _mediator->add_event(mevent);
}

}