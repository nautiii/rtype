/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "SpawnLib.hpp"

/** @brief The entry point to the Window Dynamic library
 * 
 *  @details
 *   Create the WindowLib Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new ecssystem::SpawnLib);
}

/** @brief The destroy function of the Window Dynamic library
 * 
 *  @details
 *   Destroy an existing WindowLib Class
*/
extern "C" void destroy(ecssystem::SpawnLib *ptr)
{
    delete ptr;
}
