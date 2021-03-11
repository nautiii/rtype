/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Moving
*/

#include <cstdlib>
#include "component/moving.hpp"
#include "component/transform.hpp"
#include "Moving.hpp"

namespace ecssystem {

Moving::Moving()
{
}

Moving::~Moving()
{
}

void Moving::update(ecs::Coordinator &coord, float delta)
{
    std::vector<ecs::Entity> for_deletion;

    for (auto entity: entities) {
        component::moving &cmove = coord.get_component<component::moving>(entity);
        component::transform &ctransform = coord.get_component<component::transform>(entity);

        if (ctransform.pos.x - cmove.dest.x == 0) {
            if (cmove.loop)
                ctransform.pos = cmove.start;
            else if (cmove.free_on_completion)
                for_deletion.push_back(entity);
            continue;
        }
        if (std::abs(ctransform.pos.x - cmove.dest.x) < std::abs(cmove.move.x * delta)) {
            ctransform.pos = cmove.dest;
            continue;
        }
        sf::Vector2f movement(cmove.move.x * delta, cmove.move.y * delta);
        ctransform.pos += movement;
    }
    for (auto entity: for_deletion)
        coord.destroy_entity(entity);

}

void Moving::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::moving>());
    signature.set(coord.get_component_type<component::transform>());
    coord.set_system_signature<Moving>(signature);
}

}