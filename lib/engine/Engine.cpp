/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Engine
*/

#include <iostream>
#include <chrono>
#include <yaml-cpp/yaml.h>
#include <sstream>
#include "Engine.hpp"
#include "component/Factory.hpp"
#include "Error.hpp"
#include "engine_event.hpp"
#include "event/NetworkEvent.hpp"
#include "network/protocol/Protocol.hpp"
#include "component/networked.hpp"
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

namespace engine {

Engine::Engine() : _quit(false)
{
    MINFO("Starting engine")
    _coord.init();
    load_component();
    _mediator = std::make_shared<mediator::MediatorEvent>();
    _mediator->add_event_listener("change_scene", this, engine::receive_change_scene_event);
}

Engine::~Engine()
{
    _systems.clear();
}

void Engine::load_component()
{
    add_component<component::window>("window", component::Factory::create_window);
    add_component<component::sprite>("sprite", component::Factory::create_sprite);
    add_component<component::transform>("transform", component::Factory::create_transform);
    add_component<component::movable>("movable", component::Factory::create_movable);
    add_component<component::clickable>("clickable", component::Factory::create_clickable);
    add_component<component::animate>("animate", component::Factory::create_animate);
    add_component<component::label>("label", component::Factory::create_label);
    add_component<component::moving>("moving", component::Factory::create_moving);
    add_component<component::shoot>("shoot", component::Factory::create_shoot);
    add_component<component::collision>("collision", component::Factory::create_collision);
    add_component<component::spawner>("spawner", component::Factory::create_spawner);
    _coord.register_component<component::drawable>();
    _coord.register_component<component::networked>();
}

void Engine::load(const std::string &path)
{
    MINFO("Loading file: " << path)
    try {
        YAML::Node config = YAML::LoadFile(path);
        if (config["systems"])
            load_systems(config);
        YAML::Node entities = config["entities"];
        for (YAML::const_iterator it = entities.begin(); it != entities.end(); it++) {
            try {
                const YAML::Node &entity = it->second;
                create_entity(it->first.as<std::string>(), entity);
            } catch (const Error &error) {
                MERROR(error.what())
            }
        }
    } catch (const std::exception &error) {
        MERROR("Failed to load " << path << " " << error.what())
        return;
    }
}

void Engine::unload(const std::string &path)
{
    MINFO("Unloading file: " << path)
    try {
        YAML::Node config = YAML::LoadFile(path);
        YAML::Node entities = config["entities"];
        for (YAML::const_iterator it = entities.begin(); it != entities.end(); it++) {
            _coord.destroy_entity(it->first.as<std::string>());
        }
    } catch (const std::exception &error) {
        MERROR("Failed to load " << path << " " << error.what())
        return;
    }
}

ecs::Entity Engine::create_entity(const std::string &name, const YAML::Node &node)
{
    std::string group;

    if (node["group"])
        group = node["group"].as<std::string>();
    ecs::Entity entity = _coord.create_entity(name, group);
    YAML::Node components = node["components"];
    for (YAML::const_iterator it = components.begin(); it != components.end(); it++) {
        std::string comp_name = it->first.as<std::string>();
        MINFO("Entity: " << name << " add component: " << comp_name)
        auto func = _comp_factory.find(comp_name);

        if (func == _comp_factory.end()) {
            MERROR("No function to create component: " << comp_name)
            continue;
        }
        func->second(_coord, entity, it->second);
    }
    if (node["network"] && node["network"].as<bool>())
        create_network_entity(node, entity);
    return (entity);
}

ecs::Entity Engine::create_entity(const std::string &name, const std::string &node)
{
    return (create_entity(name, YAML::Load(node)));
}

void Engine::load_systems(YAML::Node &config)
{
    for (auto &libname: config["systems"].as<std::vector<std::string>>()) {
        std::string libpath = "lib/" + libname + ".so";
        MINFO("Loading lib: " << libpath)
        try {
            auto libexist = _loaders.find(libpath);
            if (libexist != _loaders.end()) {
                MINFO("Lib " << libpath << " already loaded")
                continue;
            }
            _loaders[libpath] = std::make_unique<DLLoader>(libpath);
            _loaders[libpath]->register_lib(*this);
        } catch (const Error &error) {
            MERROR(error.what())
        }
    }
}

void Engine::run()
{
    MINFO("Running with " << _systems.size() << " systems")
    int frame = 0;
    auto frame_start = std::chrono::high_resolution_clock::now();
    float delta = 1.0 / static_cast<float>(UPDATE_PER_SECOND);

    while (_coord.get_entity_nb() != 0) {
        auto start = std::chrono::high_resolution_clock::now();
        for (auto &system: _systems) {
            system->update(_coord, delta);
        }
        _mediator->run_events(_coord);
        if (!_init) {
            _current_scene->init();
            _init = true;
        }
        frame++;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff_fps = end - frame_start;
        if (diff_fps.count() > 5) {
            MINFO(frame << " frames in 5s = " << (static_cast<float>(frame) / 5) << "FPS, entities: "  << _coord.get_entity_nb())
            frame = 0;
            frame_start = std::chrono::high_resolution_clock::now();
        }
        std::chrono::duration<float, std::micro> diff = end - start;
        int sleep_time = (1000000 / UPDATE_PER_SECOND) - diff.count();
        if (sleep_time > 0)
            usleep(sleep_time);
        auto endframe = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> sdiff = endframe - start;
        delta = sdiff.count();
    }
}

void Engine::change_scene(std::unique_ptr<IScene> &new_scene)
{
    _current_scene = std::move(new_scene);
    _init = false;
}

ecs::Coordinator &Engine::get_coord()
{
    return (_coord);
}

std::shared_ptr<mediator::MediatorEvent> Engine::get_mediator()
{
    return (_mediator);
}

void Engine::create_network_entity(const YAML::Node &node, ecs::Entity entity)
{
    YAML::Node components = node["components"];
    YAML::Node output;
    for (YAML::const_iterator it = components.begin(); it != components.end(); it++) {
        std::string comp_name = it->first.as<std::string>();

        if (it->second["network"] && it->second["network"].as<bool>() == false)
            continue;
        output[comp_name] = it->second;
    }
    std::ostringstream oss;
    oss << output;
    std::string data = oss.str();
    if (data.size() > 460) {
        MERROR("Create network entity with to big component max size 460, size: " << data.size())
        return;
    }
    if (output.size() != 0) {
        std::cout << data << std::endl;
        auto boost_uid = boost::uuids::random_generator()();
        structureProtocol::createEntity_t *raw = new structureProtocol::createEntity_t;
        std::memset(raw, '\0', sizeof(structureProtocol::createEntity_t));
        std::memcpy(raw->node, data.c_str(), data.size());
        std::memcpy(raw->uuid, boost_uid.data, protocol::UUID_SIZE);
        std::shared_ptr<mediator::IEvent> event = std::make_shared<event::NetworkEvent>(sizeof(structureProtocol::createEntity_t), raw, protocol::CREATE_ENTITY);
        _mediator->add_event(event);
        component::networked &cnetworked = _coord.add_component<component::networked>(entity);
        std::memcpy(cnetworked.uuid, boost_uid.data, protocol::UUID_SIZE);
    }
}

}