/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Shooter
*/

#ifndef SHOOTER_HPP_
#define SHOOTER_HPP_

#include "ecs/Coordinator.hpp"
#include "engine/Engine.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Shooter System
 * 
 *  @details
 *   This Class inehrits from class ecs::System
*/
class Shooter: public ecs::System {
    public:
        Shooter();
        ~Shooter();

        /** @brief Update the Shooter System
         * 
         *  @details
         *   Make the shoot everytime the spacebar is pressed
         * 
         *  @param coord The ecs::Coordinator of the ECS
         *  @param delta unused variable
         * 
         *  @note The delta variable is useless here but this function is inherited of ecs::System
        */
        void update(ecs::Coordinator &coord, float delta);
        void register_component(ecs::Coordinator &coord);
        
        /** @brief Add the Components to the System
         * 
         *  @details
         *   This member function add the needed Components by
         *   the Shooter System to work
         * 
         *  @param coord The ecs::Coordinator of the ECS
        */
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);
        void set_engine(engine::Engine *eng);
    protected:
    private:
        engine::Engine *_engine;
};

}

#endif /* !SHOOTER_HPP_ */
