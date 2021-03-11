/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** RoomView
*/

#ifndef ROOMVIEW_HPP_
#define ROOMVIEW_HPP_

#include <memory>
#include <unordered_map>
#include "engine/IScene.hpp"
#include "engine/Engine.hpp"
#include "mediator/MediatorEvent.hpp"
#include "ecs/Coordinator.hpp"

namespace room_view {

class RoomView: public engine::IScene {
    public:
        RoomView(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator);
        ~RoomView();

        /** @brief The intialization of the room list */
        void init();
        void start();
        void go_to_game();

    protected:
    private:
        engine::Engine *_engine;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !ROOMVIEW_HPP_ */
