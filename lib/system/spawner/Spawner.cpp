/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Spawner
*/

#include "Spawner.hpp"
#include "component/spawner.hpp"

namespace ecssystem {

Spawner::Spawner()
{
}

Spawner::~Spawner()
{
}

void Spawner::update(ecs::Coordinator &coord, float delta)
{
    for (auto entity: entities) {
        component::spawner &spawner = coord.get_component<component::spawner>(entity);

        if (spawner.index < spawner.wave_file.size() && spawner.wave_time[spawner.index] < spawner.clock.getElapsedTime().asSeconds()) {
            _engine->load(spawner.wave_file[spawner.index]);
            spawner.clock.restart();
            spawner.index++;
        }
    }
}

void Spawner::register_component(ecs::Coordinator &coord)
{
    ecs::Signature signature;
    signature.set(coord.get_component_type<component::spawner>());
    coord.set_system_signature<Spawner>(signature);
}

void Spawner::set_engine(engine::Engine *eng)
{
    _engine = eng;
}

}