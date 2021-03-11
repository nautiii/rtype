/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** spawner
*/

#ifndef SPAWNER_HPP_
#define SPAWNER_HPP_

#include <vector>
#include <string>
#include <SFML/System/Clock.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The shoot component 
 * 
 *  @details
 *   Contains everything needed to make the shoot
*/
struct spawner {
    std::vector<std::string> wave_file;
    std::vector<float> wave_time;
    int index;                              /*!< An index */
    sf::Clock clock;                        /*!< The clock of the component */
};

}

#endif