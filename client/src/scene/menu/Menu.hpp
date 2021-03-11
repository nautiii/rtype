/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <memory>
#include "engine/IScene.hpp"
#include "engine/Engine.hpp"
#include "mediator/MediatorEvent.hpp"
#include "ecs/Coordinator.hpp"

/** @brief Contain every objects for the menu*/
namespace menu {


/** @brief The menu scene */
class Menu: public engine::IScene {
    public:
        Menu(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator);
        ~Menu();

        /** @brief The init function
         * 
         *  @details
         *   The function that will load the menu configuration file
         *   and add the possible events to the event listener that the mediatior will handle
        */
        void init();

        /** @brief The function that handle the event to start game */
        void start_game_evt();

        /** @brief The function that handle the event to quit the game */
        void quit_game_evt();

    protected:
    private:
        engine::Engine *_engine;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !MENU_HPP_ */
