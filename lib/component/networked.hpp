/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** networked
*/

#ifndef NETWORKED_HPP_
#define NETWORKED_HPP_

#include "network/protocol/Protocol.hpp"

/** @brief Contains the components for the Entity Component System */
namespace component {

/** @brief The shoot component 
 * 
 *  @details
 *   Contains everything needed to make the shoot
*/
struct networked {
    char uuid[protocol::UUID_SIZE];
};

}

#endif /* !NETWORKED_HPP_ */
