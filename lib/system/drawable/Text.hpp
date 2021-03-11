/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "ecs/Coordinator.hpp"

/** @brief Contains the systems for the Entity Component System */
namespace ecssystem {

/** @brief The Text System
 * 
 *  @details
 *   This Class inehrits from class ecs::System
*/
class Text: public ecs::System {
    public:
        
        /// The Class constructor
        Text();
        
        /// The Class destructor
        ~Text();

        /** @brief Update the Text System
         * 
         *  @details
         *   Updating the position and the rotation of the Text
        */
        void update(ecs::Coordinator &coord, float delta);

        /** @brief Add the Components needed by the text system to work */
        void register_component(ecs::Coordinator &coord);
    protected:
    private:
};

}

#endif /* !TEXT_HPP_ */
