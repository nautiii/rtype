/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ClickableLib
*/

#ifndef CLICKABLELIB_HPP_
#define CLICKABLELIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Clickable.hpp"

/** @brief The ClickableLib class */
class ClickableLib: public engine::ILibCreator {
    public:

        /// The Class constructor
        ClickableLib() {};
    
        /// The Class destructor
        ~ClickableLib() {};

        /** @brief The member function that will add the ecssystem::Clickable system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Clickable>();
        }

    protected:
    private:
};

#endif /* !CLICKABLELIB_HPP_ */
