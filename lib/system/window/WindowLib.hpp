/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** WindowLib
*/

#ifndef WINDOWLIB_HPP_
#define WINDOWLIB_HPP_

#include "engine/ILibCreator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The WindowLib class*/
class WindowLib: public engine::ILibCreator {
    public:
        WindowLib();
        ~WindowLib();

        /** @brief The member function that will add the ecssystem::Window system to the engine
         * 
         *  @param engine The engine that will contain the new system
        */
        void register_lib(engine::Engine &engine);

    protected:
    private:
};

}

#endif /* !WINDOWLIB_HPP_ */
