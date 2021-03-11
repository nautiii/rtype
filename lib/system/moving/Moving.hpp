/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Moving
*/

#ifndef MOVINGSYS_HPP_
#define MOVINGSYS_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Moving System
 * 
 *  @details
 *   This Class inehrits from class ecs::System
*/
class Moving: public ecs::System {
    public:
        Moving();
        ~Moving();

        /** @brief Update the Moving System
         * 
         *  @details
         *   Moving automatically the entity from a source position to
         *   a dest position
         * 
         *  @param coord The ecs::Coordinator of the ECS
         *  @param delta The difference between two times used to move the entity
        */
        void update(ecs::Coordinator &coord, float delta);
       
        /** @brief Add the Components to the System
         * 
         *  @details
         *   This member function add the needed Components by
         *   the Moving System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
       void register_component(ecs::Coordinator &coord);

    protected:
    private:
};

}

#endif /* !MOVING_HPP_ */
