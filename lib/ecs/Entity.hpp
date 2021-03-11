/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <cstdint>

/** @brief The Entity Component System namespace */
namespace ecs {

using Entity = uint32_t;

const Entity MAX_ENTITIES = 5000;

}

#endif /* !ENTITY_HPP_ */
