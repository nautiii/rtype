/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** NetworkReceiveEvent
*/

#ifndef NETWORKRECEIVEEVENT_HPP_
#define NETWORKRECEIVEEVENT_HPP_

#include <string>
#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"
#include "network/protocol/Protocol.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

class NetworkReceiveEvent: public mediator::IEvent {
    public:
        NetworkReceiveEvent(std::string &name, int msize, void *mdata, protocol::PacketType mtype): _name(name), size(msize), data(mdata), type(mtype) {};
        ~NetworkReceiveEvent() {};

        int size;
        void *data;
        protocol::PacketType type;

        const std::string &get_type() const
        {
            return (_name);
        }
        std::string _name = "send_network_event";
    protected:
    private:
};

}

#endif /* !NetworkReceiveEvent_HPP_ */
