/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** DrawableLib
*/

#ifndef DRAWABLELIB_HPP_
#define DRAWABLELIB_HPP_

#include "engine/Engine.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "engine/ILibCreator.hpp"

/** @brief The Drawable System lib */
class DrawableLib: public engine::ILibCreator {
    public:
        
        /// The Class constructor
        DrawableLib() {};
        
        /// The Class destructor
        ~DrawableLib() {};

        /** @brief The member function that will add the ecssystem::Sprite and ecssystem::Text systems to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Sprite>();
            engine.add_system<ecssystem::Text>();
        }

    protected:
    private:
};

#endif /* !DRAWABLELIB_HPP_ */
