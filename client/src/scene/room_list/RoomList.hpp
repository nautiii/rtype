/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** RoomList
*/

#ifndef ROOMLIST_HPP_
#define ROOMLIST_HPP_

#include <memory>
#include <unordered_map>
#include "engine/IScene.hpp"
#include "engine/Engine.hpp"
#include "mediator/MediatorEvent.hpp"
#include "ecs/Coordinator.hpp"

/** @brief Contain every objects of the room_list */
namespace room_list {

/** @brief The Room list scene*/
class RoomList: public engine::IScene {
    public:
        RoomList(engine::Engine *engine, std::shared_ptr<mediator::MediatorEvent> mediator);
        ~RoomList();

        /** @brief The intialization of the room list */
        void init();

        /** @brief The function to add a room */
        void add_room(const std::string &name, int id);

        /** @brief The function to come back to the menu */
        void go_to_menu();

        /** @brief The function to handle when the user clicked on a room */
        void room_click(ecs::Entity entity);

        /** @brief The function to create a room*/
        void create_room();

    protected:
    private:
        std::unordered_map<ecs::Entity, int> _room_list;
        engine::Engine *_engine;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
};

}

#endif /* !ROOMLIST_HPP_ */
