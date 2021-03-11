/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** movable
*/

#ifndef MOVABLE_HPP_
#define MOVABLE_HPP_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The movable component 
 * 
 *  @details 
 *   Contains every variable necessary to move an entity.
 *   Just add this component to your entity to be able to move it.
*/
struct movable {
    sf::Keyboard::Key move_up;              /*!< The key to move up your entity */
    sf::Keyboard::Key move_down;            /*!< The key to move down your entity */
    sf::Keyboard::Key move_left;            /*!< The key to move left your entity */
    sf::Keyboard::Key move_right;           /*!< The key to move right your entity */
    float speed;                            /*!< The speed at which your entity will move */
};

}

#endif /* !MOVABLE_HPP_ */
