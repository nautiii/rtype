/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Menu
*/

#include "Menu.hpp"
#include "component/clickable.hpp"
#include "event.hpp"
#include "event/ChangeSceneEvent.hpp"
#include "room_list/RoomList.hpp"

namespace menu {

Menu::Menu(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator) : _engine(engine), _mediator(mediator)
{
}

Menu::~Menu()
{
    _engine->unload("config/menu.yml");
    _mediator->remove_event_listener("button_play_pressed", this);
    _mediator->remove_event_listener("button_quit_pressed", this);
}

void Menu::init()
{
    _engine->load("config/menu.yml");
    _mediator->add_event_listener("button_play_pressed", this, receive_event_start);
    _mediator->add_event_listener("button_quit_pressed", this, receive_event_quit);
}

void Menu::start_game_evt()
{
    std::cout << "start game" << std::endl;
    std::shared_ptr<event::ChangeSceneEvent> event = std::make_shared<event::ChangeSceneEvent>();
    event->scene = std::make_unique<room_list::RoomList>(_engine, _mediator);
    std::shared_ptr<mediator::IEvent> mevent = event;
    _mediator->add_event(mevent);
}

void Menu::quit_game_evt()
{
    std::cout << "quit game" << std::endl;
}

}