/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** MediatorEvent
*/

#ifndef MEDIATOREVENT_HPP_
#define MEDIATOREVENT_HPP_

#include <vector>
#include <functional>
#include <unordered_map>
#include "IEvent.hpp"
#include "ecs/Coordinator.hpp"

namespace ecs {
    class System;
    class Coordinator;
}

/** @brief Contains every objects that make the mediator work */
namespace mediator {


using event_func = std::function<void(void*, ecs::Coordinator &, mediator::IEvent &)>;

/** @brief A Structure to make the event listeners */
struct event_callback {
    void *obj;
    event_func func;
};

/** @brief The Mediator of events 
 * 
 *  @details
 *   Every events will be handle by this Class
*/
class MediatorEvent {
    public:
        MediatorEvent();
        ~MediatorEvent();

        /** @brief Add the received events
         * 
         *  @param new_event The received event
        */
        void add_event(std::shared_ptr<IEvent> &new_event);

        /** @brief Add the received events to an event listener
         * 
         *  @param event_name The name of the event
         *  @param obj A pointer to a Class
         *  @param func The callback function
        */
        void add_event_listener(const std::string &event_name, void *obj, event_func func);

        /** @brief Remove an event of the event listener map
         * 
         *  @param event_name The name of the event
         *  @param obj A pointer to a Class
        */
        void remove_event_listener(const std::string &event_name, void *obj);

        /** @brief Run the events in the event listener map
         * 
         *  @param coord The coordinator of the ECS
        */
        void run_events(ecs::Coordinator &coord);

    protected:
    private:
        std::unordered_multimap<std::string, event_callback> _listeners;
        std::shared_ptr<std::vector<std::string>> _test;
        std::vector<std::shared_ptr<IEvent>> _events;
};

}

#endif /* !MEDIATOREVENT_HPP_ */
