/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <bitset>
#include <cstdint>

/** @brief The Entity Component System namespace */
namespace ecs {

using ComponentType = uint8_t;
const ComponentType MAX_COMPONENTS = 64;

using Signature = std::bitset<MAX_COMPONENTS>;

}

#endif /* !COMPONENT_HPP_ */
