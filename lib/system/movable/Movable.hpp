/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Movable
*/

#ifndef MOVABLESYS_HPP_
#define MOVABLESYS_HPP_

#include <SFML/System.hpp>
#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Movable System
 * 
 *  @details
 *   This Class inherits from class ecs::System
*/
class Movable: public ecs::System {
    public:
        
        /// The Class constructor
        Movable();
        
        /// The Class destructor
        ~Movable();

        /** @brief Update the Movable System
         * 
         *  @details
         *   Change the position of the entity depending of the key pressed by user
         * 
         *  @param coord The ecs::Coordinator of the ECS
         *  @param delta The difference between two times used to move the entity
        */
        void update(ecs::Coordinator &coord, float delta);
        
        /** @brief Add the Components to the System
         * 
         *  @details
         *   This member function add the needed Components by
         *   the Movable System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
        void register_component(ecs::Coordinator &coord);
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);
        void receive_evt(const mediator::IEvent &evt);
    protected:
    private:
        std::shared_ptr<mediator::MediatorEvent> _mediator;
        sf::Clock _clock;
};

}

#endif /* !MOVABLE_HPP_ */
