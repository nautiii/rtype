/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The sprite component 
 * 
 *  @details 
 *   Contains every variable necessary to draw a sprite.
*/
struct sprite {
    sf::Texture texture;                        /*!< The texture of your sprite */
    std::shared_ptr<sf::Sprite> sprite;         /*!< The pointer to the sprite to draw */
    sf::Vector2f scale;                         /*!< The scale of your sprite */
    sf::IntRect rect;                           /*!< The rectangle that will split the spritesheet */
    bool as_texture_rect;
    std::shared_ptr<sf::Music> music;           /*!< The music of your sprite */
};

};

#endif /* !SPRITE_HPP_ */
