/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Window
*/

#ifndef WINDOWSYS_HPP_
#define WINDOWSYS_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Window System
 * 
 *  @details
 *   This Class inehrits from class ecs::System
*/
class Window: public ecs::System {
    public:

        /** @brief Update the Window System
         * 
         *  @details
         *   Get every drawable entity and draw them in the window, then display the window.
         * 
         *  @param coord The ecs::Coordinator of the ECS
         *  @param delta unused variable
         * 
         *  @note The delta variable is useless here but this function is inherited of ecs::System
        */
        void update(ecs::Coordinator &coord, float delta);

        /** @brief Add the Components to the System
         * 
         *  @details
         *   This member function add the needed Components by
         *   the Window System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
        void register_component(ecs::Coordinator &coord);
};

}

#endif /* !WINDOW_HPP_ */