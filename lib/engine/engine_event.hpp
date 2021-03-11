/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** engine_event
*/

#ifndef ENGINE_EVENT_HPP_
#define ENGINE_EVENT_HPP_

#include "ecs/Coordinator.hpp"
#include "mediator/IEvent.hpp"

/** @brief Contains all the objects that make the engine */
namespace engine {


/** @brief The function that will change scene
 * 
 *  @details 
 *   This function is called everytime you want to change the actual scene
 * 
 *  @param obj A pointer to a Class
 *  @param coord The coordinator of the ECS
 *  @param evt The received event
*/
void receive_change_scene_event(void *obj, ecs::Coordinator &coord, mediator::IEvent &evt);

}


#endif /* !ENGINE_EVENT_HPP_ */
