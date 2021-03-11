/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "CollisionLib.hpp"

extern "C" engine::ILibCreator *create()
{
    return (new CollisionLib);
}

/** @brief The destroy function of the Collision Dynamic library
 * 
 *  @details
 *   Destroy an existing CollisionLib Class
*/
extern "C" void destroy(CollisionLib *ptr)
{
    delete ptr;
}
