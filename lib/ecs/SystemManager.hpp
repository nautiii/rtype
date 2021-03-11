/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** SystemManager
*/

#ifndef SYSTEMMANAGER_HPP_
#define SYSTEMMANAGER_HPP_

#include <memory>
#include <unordered_map>
#include "Entity.hpp"
#include "Component.hpp"
#include "System.hpp"

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The class that will manage the systems */
class SystemManager
{
public:
    
    /** @brief The member function to register a system */
    template<typename T>
    std::shared_ptr<T> register_system()
    {
        std::string typeName = std::string(typeid(T).name());

        if (_systems.find(typeName) != _systems.end())
            return (NULL);

        auto sys = std::make_shared<T>();
        _systems[typeName] = sys;
        return (sys);
    }
    
    /** @brief Set a signature to a system 
     * 
     *  @param signature The signature to set
    */
    template<typename T>
    void set_signature(Signature signature)
    {
        std::string typeName = typeid(T).name();

        assert(_systems.find(typeName) != _systems.end() && "System used before registered.");

        _signatures[typeName] = signature;
    }

    /** @brief destroy an entity from all systems 
     * 
     *  @param entity The entity to remove
    */
    void entity_destroyed(Entity entity)
    {
        for (auto const& pair : _systems) {
            auto const& sys = pair.second;

            sys->entities.erase(entity);
        }
    }

    /** @brief The member function to handle changed signature
     * 
     * 
     *  @details
     *   This function will check if the signature of the entity and the signature of the system
     *   are the same. If they are, this member function will add the entity to the system.
     *   Otherwise it will remove the entity of the system.
     * 
     *  @param entity The entity to add or remove from the system
     *  @param entitySignature The signature of the entity
     */
    void entity_signature_changed(Entity entity, Signature entitySignature)
    {
        for (auto const& pair : _systems) {
            auto const& type = pair.first;
            auto const& sys = pair.second;
            auto const& sys_signature = _signatures[type];

            if ((entitySignature & sys_signature) == sys_signature) {
                sys->entities.insert(entity);
            } else {
                sys->entities.erase(entity);
            }
        }
    }

private:
    std::unordered_map<std::string, Signature> _signatures;
    std::unordered_map<std::string, std::shared_ptr<System>> _systems;
};

}

#endif /* !SYSTEMMANAGER_HPP_ */
