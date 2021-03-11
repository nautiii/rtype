/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <unordered_map>
#include <memory>
#include "Component.hpp"
#include "ComponentArray.hpp"
#include "IComponentArray.hpp"
#include <iostream>

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The class that will manage the components */
class ComponentManager
{
public:

    /** @brief The member function to register a T component to a map of components */
    template<typename T>
    void register_component()
    {
        std::string typeName = std::string(typeid(T).name());

        if (_component_types.find(typeName) != _component_types.end())
            return;
        _component_types.insert({typeName, _next_component_type});
        _component_arrays.insert({typeName, std::make_shared<ComponentArray<T>>()});
        _next_component_type++;
    }

    /** @brief The member function to retrieve the type of the T component 
     * 
     *  @note Return the type of the template component
    */
    template<typename T>
    ComponentType get_component_type()
    {
        std::string typeName = typeid(T).name();

        assert(_component_types.find(typeName) != _component_types.end() && "Component not registered before use.");
        return (_component_types[typeName]);
    }

    /** @brief The member function to add a component to an entity 
     * 
     *  @param entity The entity that will contain the new component
     *  @param component The new component
     * 
     *  @note This member function use the member function ComponentArray::insert_data
    */
    template<typename T>
    void add_component(Entity entity, T component)
    {
        get_component_array<T>()->insert_data(entity, component);
    }

    /** @brief The member function to remove an entity 
     * 
     *  @param entity The entity to remove
     * 
     *  @note This member function use the member function ComponentArray::remove_data
    */
    template<typename T>
    void remove_component(Entity entity)
    {
        get_component_array<T>()->remove_data(entity);
    }

    /** @brief The member function to retrieve information about a component 
     * 
     *  @param entity The entity to retrieve information from
     * 
     *  @note This member function use the member function ComponentArray::get_data
    */
    template<typename T>
    T& get_component(Entity entity)
    {
        return (get_component_array<T>()->get_data(entity));
    }

    /** @brief The member function to retrieve information about all components
     * 
     *  @note This member function use the member function ComponentArray::get_data
    */
    template<typename T>
    T *get_components(size_t &size)
    {
        return (get_component_array<T>()->get_data(size));
    }

    /** @brief The member function that will remove all components of an entity 
     * 
     *  @param entity The entity to remove
     * 
     *  @note This member function use the member function ComponentArray::entity_destroyed
    */
    void entity_destroyed(Entity entity)
    {
        for (auto const& pair : _component_arrays) {
            auto const& component = pair.second;

            component->entity_destroyed(entity);
        }
    }

private:
    std::unordered_map<std::string, ComponentType> _component_types;
    std::unordered_map<std::string, std::shared_ptr<IComponentArray>> _component_arrays;
    ComponentType _next_component_type;

    template<typename T>
    std::shared_ptr<ComponentArray<T>> get_component_array()
    {
        std::string typeName = std::string(typeid(T).name());

        assert(_component_types.find(typeName) != _component_types.end() && "Component not registered before use.");

        return std::static_pointer_cast<ComponentArray<T>>(_component_arrays[typeName]);
    }
};

}

#endif /* !COMPONENTMANAGER_HPP_ */
