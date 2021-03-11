/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** SpawnLib
*/

#ifndef SPAWNLIB_HPP_
#define SPAWNLIB_HPP_

#include "Spawner.hpp"
#include "engine/ILibCreator.hpp"

namespace ecssystem {

class SpawnLib: public engine::ILibCreator {
    public:
        SpawnLib() {};
        ~SpawnLib() {};

        void register_lib(engine::Engine &engine)
        {
            std::shared_ptr<ecs::System> sys = engine.add_system<ecssystem::Spawner>();
            ecssystem::Spawner *spawner = reinterpret_cast<ecssystem::Spawner*>(sys.get());
            spawner->set_engine(&engine);
        }

    protected:
    private:
};

}

#endif /* !SPAWNLIB_HPP_ */
