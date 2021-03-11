/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <exception>

/** @brief Contains all the objects that make the engine */
namespace engine {

/** @brief The Error class 
 * 
 *  @details
 *   The Error class that inherit from std::exception in order to 
 *   throw a custom error message and catch it correctly
*/
class Error: public std::exception {
    public:
        Error(std::string const &message = "Default error message.") throw():
        _message(message) {};

        /** @brief Return the content of _message which is the custom error message 
         * 
         *  @details
         *   An override of std::exception::what that will return a custom error message
        */
        const char *what() const noexcept override { return _message.c_str(); };
        virtual ~Error() throw() {};

    private:
        std::string _message;
};

/** @brief The Error class when a lib is not found */
class ErrorLibNotFound: public Error {
    public:
        ErrorLibNotFound(std::string const message = "Default error.") : Error(message) {};
};

/** @brief The Error class when an entity could not have been created */
class ErrorFailedToCreateEntity: public Error {
    public:
        ErrorFailedToCreateEntity(std::string const name = "Default error.") : Error("Entity with the name: " + name + " already register") {};
};


}

#endif /* !ERROR_HPP_ */
