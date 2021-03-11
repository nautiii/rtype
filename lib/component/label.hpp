/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** label
*/

#ifndef LABEL_HPP_
#define LABEL_HPP_

#include <memory>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The label component
 * 
 *  @details
 *   Contains every variable necessary to write text
*/
struct label {
    std::shared_ptr<sf::Text> text;             /*!< A pointer to the text to write */
    sf::Font font;                              /*!< The font of your text, it will holds various information about your font. */
};

}

#endif /* !LABEL_HPP_ */
