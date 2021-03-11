/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Collision
*/

#ifndef COLLISIONSYS_HPP_
#define COLLISIONSYS_HPP_

#include "ecs/Coordinator.hpp"

namespace ecssystem {

class Collision: public ecs::System {
    public:
        Collision();
        ~Collision();

        void update(ecs::Coordinator &coord, float delta);
        void register_component(ecs::Coordinator &coord);
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);

    protected:
    private:
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !COLLISION_HPP_ */
