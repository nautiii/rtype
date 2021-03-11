/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Text
*/

#include "component/transform.hpp"
#include "component/label.hpp"
#include "Text.hpp"

namespace ecssystem {

Text::Text()
{
}

Text::~Text()
{
}

void Text::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {;
        component::label &clabel = coord.get_component<component::label>(entity);
        component::transform &ctransform = coord.get_component<component::transform>(entity);

        clabel.text->setPosition(ctransform.pos);
        clabel.text->setRotation(ctransform.rot);
    }
}

void Text::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::label>());
    signature.set(coord.get_component_type<component::transform>());
    coord.set_system_signature<Text>(signature);
}

}