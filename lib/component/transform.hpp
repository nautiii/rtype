/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include <SFML/System/Vector2.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The transform component 
 * 
 *  @details 
 *   Contains informations about your entity.
*/
struct transform {
    sf::Vector2f pos;               /*!< The position of your entity */
    int rot;                        /*!< The rotation of your entity */
    sf::Vector2f size;              /*!< The size of your entity */
    sf::Vector2f dir;
};

}

#endif /* !TRANSFORM_HPP_ */
