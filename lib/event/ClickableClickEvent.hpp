/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ClickableClickEvent
*/

#ifndef CLICKABLECLICKEVENT_HPP_
#define CLICKABLECLICKEVENT_HPP_

#include <string>
#include "mediator/IEvent.hpp"
#include "ecs/Coordinator.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

/** @brief The class that handle clickable entity */
class ClickableClickEvent: public mediator::IEvent {
    public:
        ClickableClickEvent(std::string name, ecs::Entity mentity) : _name(name), entity(mentity) {};
        ~ClickableClickEvent() {};

        const std::string &get_type() const
        {
            return (_name);
        }
        ecs::Entity entity;             /*!< The Entity where the result of the input will be seen */
    protected:
    private:
        std::string _name = "";
};

}

#endif /* !CLICKABLECLICKEVENT_HPP_ */
