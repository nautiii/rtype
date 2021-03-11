/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** MovableLib
*/

#ifndef MOVABLELIB_HPP_
#define MOVABLELIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Movable.hpp"

/** @brief The Movable System lib */
class MovableLib: public engine::ILibCreator {
    public:
        
        /// The Class constructor
        MovableLib() {};
        
        /// The Class destructor
        ~MovableLib() {};

        /** @brief The member function that will add the ecssystem::Movable system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Movable>();
        }

    protected:
    private:
};

#endif /* !MOVABLELIB_HPP_ */
