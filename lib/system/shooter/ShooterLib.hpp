/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ShooterLib
*/

#ifndef SHOOTERLIB_HPP_
#define SHOOTERLIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Shooter.hpp"

/** @brief The Shooter System lib */
class ShooterLib: public engine::ILibCreator {
    public:
        ShooterLib() {};
        ~ShooterLib() {};

        /** @brief The member function that will add the ecssystem::Shooter system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            std::shared_ptr<ecs::System> sys = engine.add_system<ecssystem::Shooter>();
            ecssystem::Shooter *shooter = reinterpret_cast<ecssystem::Shooter*>(sys.get());
            shooter->set_engine(&engine);
        }

    protected:
    private:
};

#endif /* !SHOOTERLIB_HPP_ */
