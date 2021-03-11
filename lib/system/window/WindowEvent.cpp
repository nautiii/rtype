/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** WindowEvent
*/

#include "component/window.hpp"
#include "WindowEvent.hpp"
#include "ecs/Coordinator.hpp"
#include "event/MouseButtonPressedEvent.hpp"
#include "event/KeyPressedEvent.hpp"

namespace ecssystem {

WindowEvent::WindowEvent()
{
}

WindowEvent::~WindowEvent()
{
}

void WindowEvent::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {
        sf::Event event;
        component::window &w = coord.get_component<component::window>(entity);
        while (w.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                coord.quit();
                return;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                std::shared_ptr<mediator::IEvent> nevent = std::make_shared<event::MouseButtonPressedEvent>(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), event.mouseButton.button);
                _mediator->add_event(nevent);
            } else if (event.type == sf::Event::KeyPressed) {
                std::shared_ptr<mediator::IEvent> nevent = std::make_shared<event::KeyPressedEvent>(event.key.code);
                _mediator->add_event(nevent);
            }
        }
    }
}

void WindowEvent::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::window>());
    coord.set_system_signature<WindowEvent>(signature);
}

void WindowEvent::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &mediator)
{
    _mediator = mediator;
}

}