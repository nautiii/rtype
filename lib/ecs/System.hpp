/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <set>
#include "Entity.hpp"
#include "ecs/Coordinator.hpp"
#include "mediator/MediatorEvent.hpp"
#include "mediator/IEvent.hpp"

namespace mediator {
    class MediatorEvent;
}

/** @brief The Entity Component System namespace */
namespace ecs {

class Coordinator;

/** @brief The parent class of all the Systems */
class System {
    public:
        std::set<Entity> entities;
        virtual void register_component(ecs::Coordinator &coord) {};
        virtual void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor) {};
        virtual void update(ecs::Coordinator &coord, float delta) = 0;
    protected:
    private:
};

}

#endif /* !SYSTEM_HPP_ */
