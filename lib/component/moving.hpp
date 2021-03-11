/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** moving
*/

#ifndef MOVING_HPP_
#define MOVING_HPP_

#include <SFML/System/Vector2.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The moving component 
 * 
 *  @details 
 *   Contains every variable necessary to move an entity.
 *   It's different of the movable component, this component 
 *   will make the entity move automatically.
 *   Just add this component to your entity to move it.
*/
struct moving {
    sf::Vector2f start;             /*!< The position where the entity start */
    sf::Vector2f dest;              /*!< The destination position of the entity */
    sf::Vector2f move;              /*!< The actual position of the entity */
    bool loop;                      /*!< If set to true, make the entity move continuously (come back to the starting position and go again to the destination) */
    bool free_on_completion;        /*!< If set to true, the entity will be delete at the end of the animation */
};

}


#endif /* !MOVING_HPP_ */
