/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Sprite
*/

#ifndef SPRITESYS_HPP_
#define SPRITESYS_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Sprite System
 * 
 *  @details
 *   This Class inherits from class ecs::System
*/
class Sprite: public ecs::System {
    public:
        
        /// The Class constructor
        Sprite();
        
        /// The Class destructor
        ~Sprite();

        /** @brief Update the Sprite System
         * 
         *  @details
         *   Updating the position, the scale and the rotation of the sprite
        */
        void update(ecs::Coordinator &coord, float delta);
        
        /** @brief Add the Components needed by the sprite system to work */
        void register_component(ecs::Coordinator &coord);
    protected:
    private:
};

}

#endif /* !Sprite_HPP_ */
