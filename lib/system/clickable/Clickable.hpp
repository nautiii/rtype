/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Clickable
*/

#ifndef CLICKABLESYS_HPP_
#define CLICKABLESYS_HPP_

#include "ecs/Coordinator.hpp"
#include <thread>
#include <chrono>

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Clickable System
 * 
 *  @details
 *   This Class inherits from class ecs::System
*/
class Clickable: public ecs::System {
    public:
        
        /// The Class constructor
        Clickable();
        
        /// The Class destructor
        ~Clickable();

        /** @brief Update the Clicable System
         * 
         *  @details
         *   Because this system handles events, the function update don't do anything
        */
        void update(ecs::Coordinator &coord, float delta);

        /** @brief Add the Components to the System
         * 
         *  @details
         *   This member function add the needed Components by
         *   the Clickable System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
        void register_component(ecs::Coordinator &coord);
        
        /** @brief Register an event listener 
         * 
         *  @param meditor The mediator of events
        */
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);
        
        /** @brief Handle the click event
         * 
         *  @details
         *   The member function that will handle the click of event
         * 
         *  @param evt The receive event
         *  @param coord The coordinator of the ecs
        */
        void receive_click_evt(const mediator::IEvent &evt, ecs::Coordinator &coord);
    protected:
    private:
        std::shared_ptr<mediator::MediatorEvent> _meditor;
};

}

#endif /* !CLICKABLE_HPP_ */
