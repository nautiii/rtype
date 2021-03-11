/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ILibCreator
*/

#ifndef ILIBCREATOR_HPP_
#define ILIBCREATOR_HPP_

#include "Engine.hpp"

/** @brief Contains all the objects that make the engine */
namespace engine {

class Engine;

/** @brief The lib interfaces
 * 
 *  @details
 *   Every libraries must be inherited from this interface to be load correctly
*/
class ILibCreator {
    public:
        virtual ~ILibCreator() = default;

        virtual void register_lib(engine::Engine &engine) = 0;

    protected:
    private:
};

}

#endif /* !ILIBCREATOR_HPP_ */
