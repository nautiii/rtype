/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** NetworkEvent
*/

#ifndef NETWORKEVENT_HPP_
#define NETWORKEVENT_HPP_

#include <string>
#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"
#include "network/protocol/Protocol.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

class NetworkEvent: public mediator::IEvent {
    public:
        NetworkEvent(int msize, void *mdata, protocol::PacketType mtype, int mdest = -1): size(msize), data(mdata), type(mtype), dest(mdest) {};
        ~NetworkEvent() {};

        int dest;
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

#endif /* !NETWORKEVENT_HPP_ */
