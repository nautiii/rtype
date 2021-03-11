/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "ClickableLib.hpp"

/** @brief The entry point to the Clickable Dynamic library
 * 
 *  @details
 *   Create the ClickableLib Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new ClickableLib);
}

/** @brief The destroy function of the Clickable Dynamic library
 * 
 *  @details
 *   Destroy an existing ClickableLib Class
*/
extern "C" void destroy(ClickableLib *ptr)
{
    delete ptr;
}
