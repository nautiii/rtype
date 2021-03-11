/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** CollisionLib
*/

#ifndef COLLISIONLIB_HPP_
#define COLLISIONLIB_HPP_

#include "engine/Engine.hpp"
#include "engine/ILibCreator.hpp"
#include "Collision.hpp"

class CollisionLib: public engine::ILibCreator {
    public:
        CollisionLib() {};
        ~CollisionLib() {};

        void register_lib(engine::Engine &engine)
        {
            engine.add_system<ecssystem::Collision>();
        }
    protected:
    private:
};

#endif /* !COLLISIONLIB_HPP_ */
