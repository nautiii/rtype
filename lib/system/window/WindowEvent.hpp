/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** WindowEvent
*/

#ifndef WINDOWEVENT_HPP_
#define WINDOWEVENT_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The WindowEvent System
 * 
 *  @details
 *   This Class inehrits from class ecs::System
*/
class WindowEvent: public ecs::System {
    public:
        WindowEvent();
        ~WindowEvent();

        /** @brief Update the WindowEvent System 
         * 
         *  @details 
         *   Manage The poll Event
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

        /** @brief Register an event listener 
         * 
         *  @param meditor The mediator of events
        */
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);

    protected:
    private:
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !WINDOWEVENT_HPP_ */
