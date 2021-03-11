/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <unordered_map>
#include <yaml-cpp/node/node.h>
#include "ecs/Coordinator.hpp"
#include "DLLoader.hpp"
#include "debug.hpp"
#include "mediator/MediatorEvent.hpp"
#include "IScene.hpp"

/** @brief Contains all the objects that make the engine */
namespace engine {

class DLLoader;

static const int UPDATE_PER_SECOND = 60;

using create_componant = std::function<void(ecs::Coordinator &, const ecs::Entity, const YAML::Node &)>;

/** @brief The Engine of the game */
class Engine {
    public:
        Engine();
        ~Engine();

        /** @brief The member function to load entities and systems
         * 
         *  @details
         *   This function will parse a configuration file to load every systems and entities
         *   needed by the game.
         * 
         *  @param path The path to the configuration file
         * 
         *  @note Throw an engine::Error if something went wrong
        */
        void load(const std::string &path);

        /** @brief The member function to unload entities and systems
         * 
         *  @details
         *   This function will destroy every entities and systems precedently load by Engine::load
         * 
         *  @param path The path to the configuration file
         * 
         *  @note Throw an engine::Error if something went wrong
        */
        void unload(const std::string &path);

        /** @brief Add a System to the Engine */
        template<typename T>
        std::shared_ptr<ecs::System> add_system()
        {
            std::shared_ptr<ecs::System> sys = _coord.register_system<T>();

            if (sys) {
                sys->register_component(_coord);
                sys->register_event_listener(_mediator);
                _systems.emplace_back(sys);
            }
            return (sys);
        }

        /** @brief Add a component to the Engine */
        template<typename T>
        void add_component(const std::string &name, create_componant func)
        {
            _coord.register_component<T>();
            auto elem = _comp_factory.find(name);

            if (elem != _comp_factory.end())
                return;
            MINFO("Register entity creator: " << name)
            _comp_factory[name] = func;
        }

        /** @brief Create an entity
         * 
         *  @details
         *   The function that will create an entity and loads the components needed by each entities
         * 
         *  @param name The name of the entity
         *  @param node A node of a configuration file
        */
        ecs::Entity create_entity(const std::string &name, const YAML::Node &node);

        /** @brief Create an entity
         * 
         *  @details
         *   The function that will create an entity and loads the components needed by each entities
         * 
         *  @param name The name of the entity
         *  @param node The path to a node in the configuration file
        */
        ecs::Entity create_entity(const std::string &name, const std::string &node);

        /** @brief Run the engine
         * 
         *  @details
         *   - Call every updates to all systems
         *   - Run all events received
         *   - Change scenes if needed
         *   This function is the core that make every systems running correctly
        */
        void run();

        /** @brief Change the actual scene */
        template<typename T>
        void change_scene()
        {
            _current_scene = std::make_unique<T>(this, _mediator);
            _init = false;
        }

        /** @brief Change the actual scene */
        void change_scene(std::unique_ptr<IScene> &new_scene);

        /** @brief Retrieve the coordinator of the engine */
        ecs::Coordinator &get_coord();
        std::shared_ptr<mediator::MediatorEvent> get_mediator();

    protected:
    private:
        void load_systems(YAML::Node &config);
        void load_component();
        void create_network_entity( const YAML::Node &node, ecs::Entity entity);
        std::vector<std::shared_ptr<ecs::System>> _systems;
        std::map<std::string, std::unique_ptr<DLLoader>> _loaders;
        ecs::Coordinator _coord;
        std::unordered_map<std::string, create_componant> _comp_factory;
        std::shared_ptr<mediator::MediatorEvent> _mediator;
        bool _quit;
        std::unique_ptr<IScene> _current_scene;
        bool _init;
};

}

#endif /* !ENGINE_HPP_ */
