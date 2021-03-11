/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** entry
*/

#include "ShooterLib.hpp"

/** @brief The entry point to the Shooter Dynamic library
 * 
 *  @details
 *   Create the ShooterLib Class and return it
*/
extern "C" engine::ILibCreator *create()
{
    return (new ShooterLib);
}

/** @brief The destroy function of the Shooter Dynamic library
 * 
 *  @details
 *   Destroy an existing ShooterLib Class
*/
extern "C" void destroy(ShooterLib *ptr)
{
    delete ptr;
}
