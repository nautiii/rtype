/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** IcomponentArray
*/

#ifndef IcomponentARRAY_HPP_
#define IcomponentARRAY_HPP_

#include "Entity.hpp"

/** @brief The Entity Component System namespace */
namespace ecs {

/** @brief The Interface of the array of component */
class IComponentArray
{
public:
    /** @brief The Class destructor */
    virtual ~IComponentArray() = default;
    /** @brief A pure virtual member function to destroy entity 
     * 
     *  @param entity The entity to destroy
    */
    virtual void entity_destroyed(Entity entity) = 0;
};

}

#endif /* !IcomponentARRAY_HPP_ */
