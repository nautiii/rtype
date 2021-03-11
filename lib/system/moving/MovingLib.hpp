/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** MovingLib
*/

#ifndef MOVINGLIB_HPP_
#define MOVINGLIB_HPP_

#include "engine/Engine.hpp"
#include "Moving.hpp"
#include "engine/ILibCreator.hpp"

/** @brief The Moving System lib */
class MovingLib: public engine::ILibCreator {
    public:
        
        /// The Class constructor
        MovingLib() {};
        
        /// The Class destructor
        ~MovingLib() {};

        /** @brief The member function that will add the ecssystem::Moving system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Moving>();
        }

    protected:
    private:
};

#endif /* !MOVINGLIB_HPP_ */
