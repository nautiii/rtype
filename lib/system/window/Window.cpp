/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Window
*/

#include "component/window.hpp"
#include "component/drawable.hpp"
#include "component/transform.hpp"
#include "Window.hpp"
#include <iostream>

namespace ecssystem {

void Window::update(ecs::Coordinator &coord, float delta)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::drawable>());

    for (auto entity: entities) {
        component::window &w = coord.get_component<component::window>(entity);
        const std::vector<ecs::Entity> &elements = coord.get_entity_with_signature(signature);

        w.window->clear();
        for (auto element: elements) {
            component::drawable &draw = coord.get_component<component::drawable>(element);
            w.window->draw(*draw.draw);
        }
        w.window->display();
    }
}

void Window::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::window>());
    coord.set_system_signature<Window>(signature);
}

}