/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Movable
*/

#include "Movable.hpp"
#include "component/transform.hpp"
#include "component/movable.hpp"
#include "component/window.hpp"
#include "component/networked.hpp"
#include "network/protocol/Protocol.hpp"
#include "event/NetworkEvent.hpp"
#include <iostream>

namespace ecssystem {

Movable::Movable()
{
}

Movable::~Movable()
{
}

void Movable::update(ecs::Coordinator &coord, float delta)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::window>());
    const std::vector<ecs::Entity> &elements = coord.get_entity_with_signature(signature);
    if (elements.size() > 0) {
        component::window &window = coord.get_component<component::window>(elements[0]);
        if (!window.window->hasFocus())
            return;
    }
    for (auto entity: entities) {
        component::transform &transform = coord.get_component<component::transform>(entity);
        const component::movable &key = coord.get_component<component::movable>(entity);
        const component::networked &net = coord.get_component<component::networked>(entity);
        sf::Vector2f move = sf::Vector2f(0, 0);

        if (sf::Keyboard::isKeyPressed(key.move_up))
            move.y -= 1;
        if (sf::Keyboard::isKeyPressed(key.move_down))
            move.y += 1;
        if (sf::Keyboard::isKeyPressed(key.move_left))
            move.x -= 1;
        if (sf::Keyboard::isKeyPressed(key.move_right))
            move.x += 1;
        move = sf::Vector2f(move.x * key.speed * delta, move.y * key.speed * delta);
        transform.pos += move;
        transform.pos += transform.dir;
        if (_clock.getElapsedTime().asSeconds() > .05) {
            structureProtocol::posUpdate_t *raw = new structureProtocol::posUpdate_t;
            std::memset(raw, '\0', sizeof(structureProtocol::posUpdate_t));
            std::memcpy(raw->uuid, net.uuid, protocol::UUID_SIZE);
            raw->pos = transform.pos;
            raw->dir = move;
            std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(sizeof(structureProtocol::posUpdate_t), raw, protocol::PLAYER_MOVE);
            _mediator->add_event(event);
            _clock.restart();
        }
    }
}

void Movable::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::transform>());
    signature.set(coord.get_component_type<component::movable>());
    signature.set(coord.get_component_type<component::networked>());
    coord.set_system_signature<Movable>(signature);
}

void Movable::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &mediator)
{
    _mediator = mediator;
}

void Movable::receive_evt(const mediator::IEvent &evt)
{
}

}