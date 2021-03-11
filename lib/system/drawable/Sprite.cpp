/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Sprite
*/

#include "component/sprite.hpp"
#include "component/transform.hpp"
#include "Sprite.hpp"

namespace ecssystem {

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {
        component::sprite &csprite = coord.get_component<component::sprite>(entity);
        component::transform &ctransform = coord.get_component<component::transform>(entity);

        csprite.sprite->setPosition(ctransform.pos);
        csprite.sprite->setRotation(ctransform.rot);
        csprite.sprite->setScale(csprite.scale);
    }
}

void Sprite::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::sprite>());
    signature.set(coord.get_component_type<component::transform>());
    coord.set_system_signature<Sprite>(signature);
}

}