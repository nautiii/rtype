/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "AnimateLib.hpp"

/** @brief The entry point to the Animate Dynamic library
 * 
 *  @details
 *   Create the AnimateLib Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new AnimateLib);
}

/** @brief The destroy function of the Animate Dynamic library
 * 
 *  @details
 *   Destroy an existing AnimateLib Class
*/
extern "C" void destroy(AnimateLib *ptr)
{
    delete ptr;
}
