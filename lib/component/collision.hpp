/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** collision
*/

#ifndef COLLISION_HPP_
#define COLLISION_HPP_

#include <SFML/Graphics/Rect.hpp>

namespace component {

struct collision {
    sf::IntRect shape;
    int layer;
    int bitmask;
};

}

#endif /* !COLLISION_HPP_ */
