/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** shoot
*/

#ifndef SHOOT_HPP_
#define SHOOT_HPP_

#include <yaml-cpp/yaml.h>
#include <string>
#include <SFML/System/Clock.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The shoot component 
 * 
 *  @details
 *   Contains everything needed to make the shoot
*/
struct shoot {
    YAML::Node entity_template;             /*!< The node of the entity_template in the configuration files */
    float delay;                            /*!< The delay that will make the attack speed */
    int index;                              /*!< An index */
    sf::Clock clock;                        /*!< The clock of the component */
};

}

#endif /* !SHOOT_HPP_ */
