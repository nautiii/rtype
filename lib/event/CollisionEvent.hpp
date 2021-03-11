/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** CollisionEvent
*/

#ifndef COLLISIONEVENT_HPP_
#define COLLISIONEVENT_HPP_

#include <string>
#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

class CollisionEvent: public mediator::IEvent {
    public:
        CollisionEvent(ecs::Entity mbody1, ecs::Entity mbody2): body1(mbody1), body2(mbody2) {};
        ~CollisionEvent() {};

        const std::string &get_type() const
        {
            return (_name);
        }
        ecs::Entity body1;
        ecs::Entity body2;

    protected:
    private:
        std::string _name = "collision_event";
};

}

#endif /* !COLLISIONEVENT_HPP_ */
