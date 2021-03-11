/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** MouseButtonPressedEvent
*/

#ifndef MOUSEBUTTONPRESSEDEVENT_HPP_
#define MOUSEBUTTONPRESSEDEVENT_HPP_

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include "mediator/IEvent.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

/** @brief The Class to handle the event when the user click on the mouse */
class MouseButtonPressedEvent: public mediator::IEvent {
    public:
        /** @brief The Class constructor 
         *  
         *  @param mpos     The position of the mouse
         *  @param mbutton  The button of the mouse
        */
        MouseButtonPressedEvent(sf::Vector2f mpos, sf::Mouse::Button mbutton): pos(mpos), button(mbutton) {};
        ~MouseButtonPressedEvent() {};

        const std::string &get_type() const
        {
            return (name);
        }
        sf::Vector2f pos;               /*!< The position of the mouse */
        sf::Mouse::Button button;       /*!< The button of the mouse */

    protected:
    private:
        std::string name = "mouse_button_pressed";
};

}

#endif /* !MOUSEBUTTONPRESSEDEVENT_HPP_ */
