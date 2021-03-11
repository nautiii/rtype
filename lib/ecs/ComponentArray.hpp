/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** ComponentArray
*/

#ifndef COMPONENTARRAY_HPP_
#define COMPONENTARRAY_HPP_

#include "Entity.hpp"
#include "IComponentArray.hpp"

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The Component Array class
 * 
 *  @details
 *   A template Class that will manage an array of components
 *   of a same type.
*/ 
template<typename T>
class ComponentArray : public IComponentArray
{
public:

    /** @brief The member function that will add a component to an entity 
     * 
     *  @param entity The entity that will contain the new component
     *  @param component The new component that will be add to the entity
    */
    void insert_data(Entity entity, T component)
    {
        assert(_entity_to_index_map.find(entity) == _entity_to_index_map.end() && "Component added to same entity more than once.");
        size_t newIndex = _size;
        _entity_to_index_map[entity] = newIndex;
        _index_to_entity_map[newIndex] = entity;
        _component_array[newIndex] = component;
        _size++;
    }

    /** @brief The member function that will remove an entity
     *
     *  @param entity The entity to remove
    */ 
    void remove_data(Entity entity)
    {
        assert(_entity_to_index_map.find(entity) != _entity_to_index_map.end() && "Removing non-existent component.");
        size_t indexOfRemovedEntity = _entity_to_index_map[entity];
        size_t indexOfLastElement = _size - 1;
        _component_array[indexOfRemovedEntity] = _component_array[indexOfLastElement];
        Entity entityOfLastElement = _index_to_entity_map[indexOfLastElement];
        _entity_to_index_map[entityOfLastElement] = indexOfRemovedEntity;
        _index_to_entity_map[indexOfRemovedEntity] = entityOfLastElement;

        _entity_to_index_map.erase(entity);
        _index_to_entity_map.erase(indexOfLastElement);

        _size--;
    }

    /** @brief The member function to retrieve information about an entity
     * 
     *  @param entity The entity to retrieve information from
     * 
     *  @note return a component from the array of components
    */ 
    T& get_data(Entity entity)
    {
        assert(_entity_to_index_map.find(entity) != _entity_to_index_map.end() && "Retrieving non-existent component.");
        return (_component_array[_entity_to_index_map[entity]]);
    }

    /** @brief The member function to retrieve information ??
     * 
     *  @param size The number of elements to read
     * 
     *  @note return the first component of the array of components
    */
    const T*get_data(size_t &size)
    {
        size = _size;
        return (_component_array.cbegin());
    }

    /** @brief The member function to remove an entity
     * 
     *  @param entity The entity to remove
     * 
     *  @note This member function call the other member function : ComponentArray::remove_data
    */
    void entity_destroyed(Entity entity) override
    {
        if (_entity_to_index_map.find(entity) != _entity_to_index_map.end())
        {
            remove_data(entity);
        }
    }

private:
    std::array<T, MAX_ENTITIES> _component_array;               /*!< The array of components */
    std::unordered_map<Entity, size_t> _entity_to_index_map;    /*!< The map to store an index with the Entity key */
    std::unordered_map<size_t, Entity> _index_to_entity_map;    /*!< The map to store an Entity with the index key */
    size_t _size;                                               /*!< The size of the ComponentArray::_entity_to_index_map and ComponentArray::_index_to_entity_map maps */
};

}

#endif /* !COMPONENTARRAY_HPP_ */
