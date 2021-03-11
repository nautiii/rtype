/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Spawner
*/

#ifndef SPAWNERSYS_HPP_
#define SPAWNERSYS_HPP_

#include "ecs/Coordinator.hpp"
#include "engine/Engine.hpp"

namespace ecssystem {

class Spawner: public ecs::System {
    public:
        Spawner();
        ~Spawner();

        void update(ecs::Coordinator &coord, float delta);
        void register_component(ecs::Coordinator &coord);
        void set_engine(engine::Engine *eng);

    protected:
    private:
        engine::Engine *_engine;
};

}

#endif /* !SPAWNER_HPP_ */
