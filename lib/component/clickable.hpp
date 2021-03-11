/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** clickable
*/

#ifndef CLICKABLE_HPP_
#define CLICKABLE_HPP_

#include <SFML/Audio.hpp>
#include <string>
/** @brief Contains the components for the Entity Component System */

namespace component {

/** @brief The clickable component
 * 
 *  @details 
 *   Contains every variable necessary to make an entity clickable.
 *   Just add this component to your entity to make it clickable
*/
struct clickable {
    std::string event_name;
    std::shared_ptr<sf::Music> music;
};

};

#endif /* !CLICKABLE_HPP_ */
