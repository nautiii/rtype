/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Animate
*/

#ifndef ANIMATESYS_HPP_
#define ANIMATESYS_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Animate System
 * 
 *  @details
 *   This Class inherits from class ecs::System
*/
class Animate: public ecs::System {
    public:
        
        /// The Class constructor
        Animate();
        
        /// The Class destructor
        ~Animate();

        /** @brief Update the Animate System
         * 
         *  @details
         *   Change the frame of an entity everytime this member function
         *   is called in order to Animate the entity.
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
         *   the Animate System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
        void register_component(ecs::Coordinator &coord);

    protected:
    private:
};

}

#endif /* !ANIMATE_HPP_ */
