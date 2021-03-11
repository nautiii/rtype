/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "DrawableLib.hpp"

/** @brief The entry point to the Drawable Dynamic library
 * 
 *  @details
 *   Create the DrawableLib Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new DrawableLib);
}

/** @brief The destroy function of the Drawable Dynamic library
 * 
 *  @details
 *   Destroy an existing DrawableLib Class
*/
extern "C" void destroy(DrawableLib *ptr)
{
    delete ptr;
}
