/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <string>

/** @brief Contains all the objects that make the engine */
namespace engine {

/** @brief The Scene interfaces
 * 
 *  @details
 *   Every scenes must be inherited from this interface to work correctly
*/
class IScene {
    public:
        virtual ~IScene() = default;

        virtual void init() = 0;

    protected:
    private:
};

}

#endif /* !ISCENE_HPP_ */
