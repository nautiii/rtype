/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Coordinator
*/

#ifndef COORDINATOR_HPP_
#define COORDINATOR_HPP_

#include <unordered_map>
#include <algorithm>
#include "engine/debug.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "SystemManager.hpp"

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The class that will handle the Entities, the Components and the Systems */
class Coordinator
{
public:

    /** @brief The Initialization member function
     * 
     *  @details
     *   This function will initialize your Coordinator and more precisely the component_manager,
     *   the entity_manager and the system_manager. 
    */
    void init()
    {
        _component_manager = std::make_unique<ComponentManager>();
        _entity_manager = std::make_unique<EntityManager>();
        _system_manager = std::make_unique<SystemManager>();
    }

    /** @brief Create an entity
     * 
     *  @param name The name of the entity
     *  @param group The group of the entity
     * 
     *  @note return the newly create entity
    */
    Entity create_entity(const std::string &name, const std::string &group = "")
    {
        auto elem = _map_entity.find(name);

        if (elem != _map_entity.end())
            MERROR("Entity with name: " << name << " alredy exist")
        ecs::Entity entity = _entity_manager->create_entity();
        _map_entity[name] = entity;
        if (group != "")
            _map_group[entity] = group;
        return (entity);
    }

    /** @brief Remove of the ECS an entity
     * 
     *  @param entity The entity to destroy
    */
    void destroy_entity(Entity entity)
    {
        _entity_manager->destroy_entity(entity);
        _component_manager->entity_destroyed(entity);
        _system_manager->entity_destroyed(entity);
        for (auto &elem: _map_entity) {
            if (elem.second == entity) {
                _map_entity.erase(elem.first);
                break;
            }
        }
        auto group = _map_group.find(entity);
        if (group != _map_group.end())
            _map_group.erase(group);
    }

    /** @brief Remove of the ECS an entity
     * 
     *  @param name The name of the entity to destroy
    */
    void destroy_entity(const std::string &name)
    {
        auto entity = _map_entity.find(name);

        if (entity == _map_entity.end()) {
            MERROR("Failed to destroy entity with name: " << name)
            return;
        }
        destroy_entity(entity->second);
    }

    /** @brief Remove of the ECS a group
     * 
     *  @param group_name The name of the group to destroy
    */
    void destroy_group(const std::string &group_name)
    {
        std::vector<ecs::Entity> to_delete;

        to_delete.reserve(10);
        for (auto elem: _map_group) {
            if (elem.second == group_name)
                to_delete.push_back(elem.first);
        }
        for (auto entity: to_delete)
            destroy_entity(entity);
    }

    /** @brief Get the number of entities */
    int get_entity_nb()
    {
        return (_entity_manager->get_entity_nb());
    }

    /** @brief Register a component in the ecs::ComponentManager class
     * 
     *  @note This member function use ecs::ComponentManager::register_component member function
    */
    template<typename T>
    void register_component()
    {
        _component_manager->register_component<T>();
    }

    /** @brief Add a component to an entity
     * 
     *  @param entity The entity that will contain the new component
     *  @param component The new component
     * 
     *  @note This member function uses the ecs::ComponentManager::add_component member function
    */
    template<typename T>
    void add_component(Entity entity, T component)
    {
        _component_manager->add_component<T>(entity, component);

        auto signature = _entity_manager->get_signature(entity);
        signature.set(_component_manager->get_component_type<T>(), true);
        _entity_manager->set_signature(entity, signature);

        _system_manager->entity_signature_changed(entity, signature);
    }

    /** @brief Add a new empty component to an entity
     * 
     *  @param entity The entity that will contain the new component
    */
    template<typename T>
    T &add_component(Entity entity)
    {
        T component;
        add_component<T>(entity, component);
        return (get_component<T>(entity));
    }

    /** @brief Remove a component */
    template<typename T>
    void remove_component(Entity entity)
    {
        _component_manager->remove_component<T>(entity);

        auto signature = _entity_manager->get_signature(entity);
        signature.set(_component_manager->get_component_type<T>(), false);
        _entity_manager->set_signature(entity, signature);

        _system_manager->entity_signature_changed(entity, signature);
    }

    /** @brief retrieve a component */
    template<typename T>
    T& get_component(Entity entity)
    {
        return (_component_manager->get_component<T>(entity));
    }

    /** @brief retrieve all components */
    template<typename T>
    T*get_components(size_t &size)
    {
        return (_component_manager->get_components<T>(size));
    }

    /** @brief retrieve the type of the components */
    template<typename T>
    ComponentType get_component_type()
    {
        return (_component_manager->get_component_type<T>());
    }

    /** @brief register a system to the system Manager*/
    template<typename T>
    std::shared_ptr<T> register_system()
    {
        return (_system_manager->register_system<T>());
    }

    /** @brief Set the signature of the system to assure it unicity */
    template<typename T>
    void set_system_signature(Signature signature)
    {
        _system_manager->set_signature<T>(signature);
    }

    /** @brief destroy all entities */
    void quit()
    {
        for (int i = 0; i < MAX_ENTITIES; i++)
            destroy_entity(i);
    }

    /** @brief Retrieve an entity with a specific signature
     * 
     *  @param sign The signature of the entity to retrieve
    */
    const std::vector<Entity> &get_entity_with_signature(Signature sign)
    {
        return (_entity_manager->get_entity_with_signature(sign));
    }

    Signature get_entity_signature(ecs::Entity entity)
    {
        return (_entity_manager->get_signature(entity));
    }

private:
    std::unique_ptr<ComponentManager> _component_manager;
    std::unique_ptr<EntityManager> _entity_manager;
    std::unique_ptr<SystemManager> _system_manager;
    std::unordered_map<std::string, ecs::Entity> _map_entity;
    std::unordered_map<ecs::Entity, std::string> _map_group;
};

}

#endif /* !COORDINATOR_HPP_ */
