/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ChangeSceneEvent
*/

#ifndef CHANGESCENEEVENT_HPP_
#define CHANGESCENEEVENT_HPP_

#include <string>
#include <memory>
#include "mediator/IEvent.hpp"
#include "engine/IScene.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

/** @brief The Class that will change scenes */
class ChangeSceneEvent: public mediator::IEvent {
    public:
        ChangeSceneEvent() {};
        ~ChangeSceneEvent() {};

        const std::string &get_type() const
        {
            return (_name);
        }

        std::unique_ptr<engine::IScene> scene;          /*!< A pointer to a scene */

    protected:
    private:
        std::string _name = "change_scene";
};

}

#endif /* !CHANGESCENEEVENT_HPP_ */
