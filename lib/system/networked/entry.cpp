/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "NetworkedLib.hpp"


/** @brief The entry point to the Networked Dynamic library
 * 
 *  @details
 *   Create the Networked Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new NetworkedLib);
}

/** @brief The destroy function of the Networked Dynamic library
 * 
 *  @details
 *   Destroy an existing NetworkedLib Class
*/
extern "C" void destroy(NetworkedLib *ptr)
{
    delete ptr;
}
