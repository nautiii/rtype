/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Collision
*/

#include "Collision.hpp"
#include "component/transform.hpp"
#include "component/collision.hpp"
#include "event/CollisionEvent.hpp"

namespace ecssystem {

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {
        const component::transform transform = coord.get_component<component::transform>(entity);
        const component::collision collision = coord.get_component<component::collision>(entity);
        sf::IntRect rect = collision.shape;
        rect.left += transform.pos.x;
        rect.top += transform.pos.y;

        for (auto compaison: entities) {
            const component::transform transform2 = coord.get_component<component::transform>(compaison);
            const component::collision collision2 = coord.get_component<component::collision>(compaison);
            if (collision.bitmask & collision2.layer == collision.bitmask && entity != compaison) {
                sf::IntRect other = collision2.shape;
                other.left += transform2.pos.x;
                other.top += transform2.pos.y;
                if (rect.intersects(other)) {
                    std::shared_ptr<mediator::IEvent> event = std::make_shared<event::CollisionEvent>(entity, compaison);
                    _mediator->add_event(event);
                }
            }
        }
    }
}

void Collision::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::transform>());
    signature.set(coord.get_component_type<component::collision>());
    coord.set_system_signature<Collision>(signature);
}

void Collision::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &mediator)
{
    _mediator = mediator;
}

}