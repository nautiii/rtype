/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** NetworkedLib
*/

#ifndef NETWORKEDLIB_HPP_
#define NETWORKEDLIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Networked.hpp"

class NetworkedLib: public engine::ILibCreator {
    public:
        NetworkedLib() {};
        ~NetworkedLib() {};

        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Networked>();
        }

    protected:
    private:
};

#endif /* !NETWORKEDLIB_HPP_ */
