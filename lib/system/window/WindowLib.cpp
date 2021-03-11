/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** WindowLib
*/

#include "engine/Engine.hpp"
#include "Window.hpp"
#include "WindowEvent.hpp"
#include "WindowLib.hpp"

namespace ecssystem {

WindowLib::WindowLib()
{
}

WindowLib::~WindowLib()
{
}

void WindowLib::register_lib(engine::Engine &engine)
{
    engine.add_system<ecssystem::Window>();
    engine.add_system<ecssystem::WindowEvent>();
}

}