/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** MediatorEvent
*/

#include <algorithm>
#include "MediatorEvent.hpp"

namespace mediator {

MediatorEvent::MediatorEvent()
{
}

MediatorEvent::~MediatorEvent()
{
}

void MediatorEvent::add_event(std::shared_ptr<IEvent> &new_event)
{
    _events.push_back(new_event);
}

void MediatorEvent::add_event_listener(const std::string &event_name, void *obj, event_func func)
{
    _listeners.insert({event_name, event_callback{obj, func}});
}

void MediatorEvent::remove_event_listener(const std::string &event_name, void *obj)
{
    auto listener = _listeners.equal_range(event_name);

    for (auto elem = listener.first; elem != listener.second; elem++) {
        if (elem->second.obj == obj) {
            _listeners.erase(elem);
            return;
        }
    }
}

void MediatorEvent::run_events(ecs::Coordinator &coord)
{
    for (int i = 0; i < _events.size(); i++) {
        auto &event = _events[i];
        auto listeners = _listeners.equal_range(event->get_type());

        std::for_each(listeners.first, listeners.second, [&event, &coord](std::unordered_multimap<std::string, event_callback>::value_type elem){
            elem.second.func(elem.second.obj, coord, *event);
        });
    }
    _events.clear();
}


}