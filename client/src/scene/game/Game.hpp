/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include "engine/IScene.hpp"
#include "engine/Engine.hpp"
#include "mediator/MediatorEvent.hpp"
#include "ecs/Coordinator.hpp"
#include "event/CollisionEvent.hpp"

/** @brief Contains every object for the game */
namespace game {

/** @brief The game scene*/
class Game: public engine::IScene {
    public:
        Game(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator);
        ~Game();

        /** @brief The function that will load the game configuration file*/
        void init();

    protected:
    private:
        engine::Engine *_engine;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !GAME_HPP_ */
