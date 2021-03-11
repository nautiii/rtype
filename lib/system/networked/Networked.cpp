/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Networked
*/

#include "Networked.hpp"
#include <cstdlib>
#include "component/networked.hpp"
#include "component/transform.hpp"
#include "net_event.hpp"

namespace ecssystem {

Networked::Networked()
{
}

Networked::~Networked()
{
}

void Networked::update(ecs::Coordinator &coord, float delta)
{}

void Networked::register_component(ecs::Coordinator &coord)
{}

void Networked::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &mediator)
{
    mediator->add_event_listener("net_player_move", this, receive_pos_event);
}

void Networked::update_pos(ecs::Coordinator &coord, ecs::Entity entity, sf::Vector2f &pos, sf::Vector2f &dir)
{
    ecs::Signature transform_sign;
    transform_sign.set(coord.get_component_type<component::transform>());
    ecs::Signature sign = coord.get_entity_signature(entity);
    if ((sign & transform_sign) == transform_sign) {
        component::transform &trans = coord.get_component<component::transform>(entity);
        trans.pos = pos;
        trans.dir = dir;
    }
}

}