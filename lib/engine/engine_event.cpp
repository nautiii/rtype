/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** engine_event
*/

#include <yaml-cpp/yaml.h>
#include "engine_event.hpp"
#include "Engine.hpp"
#include "event/ChangeSceneEvent.hpp"
#include "event/NetworkReceiveEvent.hpp"
#include "network/protocol/Protocol.hpp"

namespace engine {

void receive_change_scene_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt)
{
    Engine *engine = reinterpret_cast<Engine*>(obj);
    event::ChangeSceneEvent &scn_event = reinterpret_cast<event::ChangeSceneEvent&>(evt);

    engine->change_scene(scn_event.scene);
}

}