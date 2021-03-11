/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include <memory>
#include <SFML/Graphics.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The drawable component
 * 
 *  @details
 *   Contains every variable necessary to draw your entity.
 *   Just add this component to your entity to draw it.
*/
struct drawable {
    std::shared_ptr<sf::Drawable> draw;             /*!< A pointer to a drawable element on a window */
};

};

#endif /* !DRAWABLE_HPP_ */
