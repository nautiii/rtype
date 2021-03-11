/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Game
*/

#include "Game.hpp"
#include "event_game.hpp"

namespace game {

Game::Game(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator): _engine(engine), _mediator(mediator)
{
}

Game::~Game()
{
    _engine->unload("config/game.yml");
    _mediator->remove_event_listener("collision_event", this);
}

void Game::init()
{
    _engine->load("config/game.yml");
    _mediator->add_event_listener("collision_event", this, receive_collision_event);
}

}