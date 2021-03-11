/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Networked
*/

#ifndef NETWORKEDSYS_HPP_
#define NETWORKEDSYS_HPP_

#include <SFML/System/Vector2.hpp>
#include "ecs/Coordinator.hpp"

namespace ecssystem {

class Networked: public ecs::System {
    public:
        Networked();
        ~Networked();

        void update(ecs::Coordinator &coord, float delta);
        void register_component(ecs::Coordinator &coord);
        void register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor);
        void receive_evt(const mediator::IEvent &evt);
        void update_pos(ecs::Coordinator &coord, ecs::Entity entity, sf::Vector2f &pos, sf::Vector2f &dir);

    protected:
    private:
};

}

#endif /* !NETWORKED_HPP_ */
