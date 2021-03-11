/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <cassert>
#include <queue>
#include <array>
#include <set>
#include "Entity.hpp"
#include "Component.hpp"

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The class that will manage the entities */
class EntityManager {
public:

    /** @brief The class Constructor */
    EntityManager()
    {
        for (Entity entity = 0; entity < MAX_ENTITIES; ++entity) {
            _available_entities.push(entity);
        }
    }

    /** @brief Create an entity */
    Entity create_entity()
    {
        assert(_living_entity_count < MAX_ENTITIES && "Too many entities in existence.");
        Entity id = _available_entities.front();
        _available_entities.pop();
        _used_id.insert(id);
        _living_entity_count++;

        return (id);
    }

    /** @brief Destroy an entity
     * 
     *  @param entity The entity to destroy
     */
    void destroy_entity(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        _signatures[entity].reset();
        _available_entities.push(entity);
        _used_id.erase(entity);
        if (_living_entity_count > 0)
            _living_entity_count--;
    }

    /** @brief Set a specific signature to an entity
     * 
     *  @param entity The entity to assign the signature
     *  @param signature The specific signature to set
     */
    void set_signature(Entity entity, Signature signature)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        _signatures[entity] = signature;
    }

    /** @brief Retrieve the signature of an entity
     * 
     *  @param entity The entity to get the signature from
     * 
     *  @note This member function return a signature
     */
    Signature get_signature(Entity entity)
    {
        assert(entity < MAX_ENTITIES && "Entity out of range.");
        return _signatures[entity];
    }

    /** @brief Retrieve the number of living entities */
    int get_entity_nb() const
    {
        return (_living_entity_count);
    }

    /** @brief Retrieve all entities with the signature given as parameter
     * 
     *  @param sign The signature of the entities we want to get
     */
    const std::vector<Entity> &get_entity_with_signature(Signature sign)
    {
        _vec.clear();
        for (auto id: _used_id) {
            if ((get_signature(id) & sign) == sign)
                _vec.push_back(id);
        }
        return (_vec);
    }

private:
    std::set<Entity> _used_id;
    std::queue<Entity> _available_entities;
    std::array<Signature, MAX_ENTITIES> _signatures;
    uint32_t _living_entity_count = 0;
    std::vector<Entity> _vec;
};

}

#endif /* !ENTITYMANAGER_HPP_ */
