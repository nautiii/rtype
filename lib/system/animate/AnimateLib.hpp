/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** AnimateLib
*/

#ifndef ANIMATELIB_HPP_
#define ANIMATELIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Animate.hpp"

/** @brief The AnimateLib class */
class AnimateLib : public engine::ILibCreator {
    public:
        
        /// The Class constructor
        AnimateLib() {};

        /// The Class destructor
        ~AnimateLib() {};

        /** @brief The member function that will add the ecssystem::Animate system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Animate>();
        }

    protected:
    private:
};

#endif /* !ANIMATELIB_HPP_ */
