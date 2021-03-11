/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** DLLoader
*/

#include <dlfcn.h>
#include <iostream>
#include "DLLoader.hpp"
#include "debug.hpp"
#include "Error.hpp"

namespace engine {

DLLoader::DLLoader(const std::string &path)
{
    _open_lib = dlopen(path.c_str(), RTLD_LAZY);
    if (!_open_lib) {
        throw(ErrorLibNotFound(dlerror()));
    }
    _register_lib = reinterpret_cast<init_dll_func>(dlsym(_open_lib, "create"));
    if (!_register_lib) {
        throw(ErrorLibNotFound(dlerror()));
    }
    _lib = _register_lib();
    MINFO("Lib init " << path)
}

DLLoader::~DLLoader()
{
    dlclose(_open_lib);
}

void DLLoader::register_lib(engine::Engine &engine)
{
    _lib->register_lib(engine);
}

}