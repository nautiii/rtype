/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Shooter
*/

#include <SFML/Window/Keyboard.hpp>
#include "Shooter.hpp"
#include "component/transform.hpp"
#include "component/shoot.hpp"
#include "component/moving.hpp"
#include "component/window.hpp"

namespace ecssystem {

Shooter::Shooter()
{
}

Shooter::~Shooter()
{
}

void Shooter::update(ecs::Coordinator &coord, float delta)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::window>());
    const std::vector<ecs::Entity> &elements = coord.get_entity_with_signature(signature);
    if (elements.size() > 0) {
        component::window &window = coord.get_component<component::window>(elements[0]);
        if (!window.window->hasFocus())
            return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        for (auto entity: entities) {
            component::shoot &shoot = coord.get_component<component::shoot>(entity);
            if (shoot.clock.getElapsedTime().asSeconds() > shoot.delay) {
                const component::transform &transform = coord.get_component<component::transform>(entity);
                YAML::Node entity_node = shoot.entity_template;
                entity_node["components"]["transform"]["x"] = transform.pos.x + 100;
                entity_node["components"]["transform"]["y"] = transform.pos.y + 20;
                entity_node["components"]["moving"]["start_x"] = transform.pos.x;
                entity_node["components"]["moving"]["start_y"] = transform.pos.y;
                entity_node["components"]["moving"]["dest_x"] = 1920;
                entity_node["components"]["moving"]["dest_y"] = transform.pos.y;
                entity_node["components"]["moving"]["move_x"] = 500;
                entity_node["components"]["moving"]["free_on_completion"] = true;
                ecs::Entity ent = _engine->create_entity("shoot_" + std::to_string(entity) + "_" + std::to_string(shoot.index), entity_node);
                shoot.index++;
                if (shoot.index > 1000)
                    shoot.index = 0;
                shoot.clock.restart();
            }
        }
    }

}

void Shooter::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::transform>());
    signature.set(coord.get_component_type<component::shoot>());
    coord.set_system_signature<Shooter>(signature);
}

void Shooter::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor)
{}

void Shooter::set_engine(engine::Engine *eng)
{
    _engine = eng;
}

}