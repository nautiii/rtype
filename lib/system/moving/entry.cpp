/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "MovingLib.hpp"

/** @brief The entry point to the Miving Dynamic library
 * 
 *  @details
 *   Create the MovingLib Class and return it
*/extern "C" engine::ILibCreator *create()
{
    return (new MovingLib);
}

/** @brief The destroy function of the Moving Dynamic library
 * 
 *  @details
 *   Destroy an existing MovingLib Class
*/
extern "C" void destroy(MovingLib *ptr)
{
    delete ptr;
}
