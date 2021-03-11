/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "MovableLib.hpp"

/** @brief The entry point to the Movable Dynamic library
 * 
 *  @details
 *   Create the Movable Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new MovableLib);
}

/** @brief The destroy function of the Movable Dynamic library
 * 
 *  @details
 *   Destroy an existing MovableLib Class
*/
extern "C" void destroy(MovableLib *ptr)
{
    delete ptr;
}
