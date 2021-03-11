/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** NetworkEntityUpdate
*/

#ifndef NETWORKENTITYUPDATE_HPP_
#define NETWORKENTITYUPDATE_HPP_

#include <string>
#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"
#include "network/protocol/Protocol.hpp"

/** @brief Contains the objects to manage the event */
namespace event {

class NetworkEntityUpdate: public mediator::IEvent {
    public:
        NetworkEntityUpdate(std::string &name, int msize, void *mdata, protocol::PacketType mtype, ecs::Entity mentity): _name(name), size(msize), data(mdata), type(mtype), entity(mentity) {};
        ~NetworkEntityUpdate() {};

        int size;
        void *data;
        protocol::PacketType type;
        ecs::Entity entity;

        const std::string &get_type() const
        {
            return (_name);
        }
        std::string _name = "send_network_event";
    protected:
    private:
};

}

#endif /* !NetworkEntityUpdate_HPP_ */
