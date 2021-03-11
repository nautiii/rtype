/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Clickable
*/

#include <SFML/Graphics/Rect.hpp>
#include "Clickable.hpp"
#include "component/transform.hpp"
#include "component/clickable.hpp"
#include "event/MouseButtonPressedEvent.hpp"
#include "event.hpp"
#include "event/ClickableClickEvent.hpp"
#include <iostream>

namespace ecssystem {

Clickable::Clickable()
{
}

Clickable::~Clickable()
{
}

void Clickable::update(ecs::Coordinator &coord, float delta)
{}

void Clickable::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::transform>());
    signature.set(coord.get_component_type<component::clickable>());
    coord.set_system_signature<Clickable>(signature);
}

void Clickable::register_event_listener(std::shared_ptr<mediator::MediatorEvent> &meditor)
{
    _meditor = meditor;
    meditor->add_event_listener("mouse_button_pressed", this, receive_event);
}

void Clickable::receive_click_evt(const mediator::IEvent &evt, ecs::Coordinator &coord)
{
    const event::MouseButtonPressedEvent &data = reinterpret_cast<const event::MouseButtonPressedEvent&>(evt);
    if (data.button == sf::Mouse::Left) {
        for (auto entity: entities) {
            const component::transform transform = coord.get_component<component::transform>(entity);
            component::clickable &clickable = coord.get_component<component::clickable>(entity);
            sf::FloatRect rect(transform.pos, transform.size);

            if (rect.contains(data.pos)) {
                auto name = clickable.event_name;
                std::thread([](component::clickable c) {
                    c.music->play();
                    std::this_thread::sleep_for(std::chrono::milliseconds(c.music->getDuration().asMilliseconds()));
                }, std::move(clickable)).detach();
                std::shared_ptr<mediator::IEvent> sevent = std::make_shared<event::ClickableClickEvent>(name, entity);
                _meditor->add_event(sevent);
            }
        }
    }
}

}