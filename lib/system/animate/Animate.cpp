/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Animate
*/

#include "component/animate.hpp"
#include "component/sprite.hpp"
#include "Animate.hpp"

namespace ecssystem {

Animate::Animate()
{
}

Animate::~Animate()
{
}

void Animate::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {
        component::animate &animate = coord.get_component<component::animate>(entity);
        component::sprite &sprite = coord.get_component<component::sprite>(entity);
        animate.time = animate.clock.getElapsedTime();
        if ((animate.time.asMicroseconds() / 1000000.0) > animate.frame_time) {
            sf::IntRect rect(sprite.rect.left + sprite.rect.width * animate.current_frame, sprite.rect.top, sprite.rect.width, sprite.rect.height);
            sprite.sprite->setTextureRect(rect);
            animate.clock.restart();
            animate.current_frame++;
            if (animate.current_frame >= animate.max_frames)
                animate.current_frame = 0;
        }
    }
}

void Animate::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::sprite>());
    signature.set(coord.get_component_type<component::animate>());
    coord.set_system_signature<Animate>(signature);
}

}