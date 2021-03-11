/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The window component 
 * 
 *  @details 
 *   Contains every variable necessary to create a window.
*/
struct window {
    std::shared_ptr<sf::RenderWindow> window;           /*!< A pointer to the window to create */
    sf::Image icon;                                     /*!< The icon of the game */
    std::shared_ptr<sf::Music> music;                   /*!< The main music loop */
};

};

#endif /* !WINDOW_HPP_ */
