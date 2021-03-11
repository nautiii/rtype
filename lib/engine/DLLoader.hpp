/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <functional>
#include <string>
#include "Engine.hpp"
#include "ILibCreator.hpp"

/** @brief Contains all the objects that make the engine */
namespace engine {

class Engine;
class ILibCreator;

using init_dll_func = ILibCreator*(*)();

/** @brief The class that will load Dynamic libraries */
class DLLoader {
    public:
        DLLoader(const std::string &path);
        ~DLLoader();

        /** @brief The member function that will register the new library 
         * 
         *  @note This function use the ILibCreator::register_lib member function
        */
        void register_lib(engine::Engine &engine);
    protected:
    private:
        init_dll_func _register_lib;
        void *_open_lib;
        ILibCreator *_lib;
};

}

#endif /* !DLLOADER_HPP_ */
