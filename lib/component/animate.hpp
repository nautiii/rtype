/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** animate
*/

#ifndef ANIMATE_HPP_
#define ANIMATE_HPP_

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The animate component 
 * 
 *  @details 
 *   Contains every variable necessary to animate an entity.
 *   Just add this component to your entity to animate it.
*/
struct animate {
    int current_frame;                  /*!< Current frame of the animation animation */
    int max_frames;                     /*!< The total numbers of frames for your animation */
    sf::Clock clock;                    /*!< A clock needed to don't run your animation with the speed of your computer */
    sf::Time time;                      /*!< A timer needed to update your frame every frame_time */
    float frame_time;                   /*!< The frame time to update your animation (Ex: frame_time = 0.1 means that the frame will be updated every 0.1s)*/
};

}

#endif /* !ANIMATE_HPP_ */
