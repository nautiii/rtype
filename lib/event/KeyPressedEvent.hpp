/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** KeyPressedEvent
*/

#ifndef KEYPRESSEDEVENT_HPP_
#define KEYPRESSEDEVENT_HPP_

#include <SFML/Window/Keyboard.hpp>
#include "mediator/IEvent.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

/** @brief The Class that will handle when a key is pressed */
class KeyPressedEvent: public mediator::IEvent {
    public:

        /** @brief The Class constructor */
        KeyPressedEvent(sf::Keyboard::Key mkey): key(mkey) {};
        
        /** @brief The Class destructor */
        ~KeyPressedEvent() {};

        const std::string &get_type() const
        {
            return (name);
        }

        sf::Keyboard::Key key;      /*!< The key pressed */

    protected:
    private:
        std::string name = "key_pressed";
};

}

#endif /* !KEYPRESSEDEVENT_HPP_ */
