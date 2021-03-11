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

namespace network {

class Error: public std::exception {
    public:
        Error(std::string const &message = "Default error message.") throw():
        _message(message) {};
        const char *what() const noexcept override { return _message.c_str(); };
        virtual ~Error() throw() {};

    private:
        std::string _message;
};

class PacketTooSmallError: Error {
    public:
        PacketTooSmallError(std::string const message = "Packet too small") : Error(message) {};
};

}

#endif /* !ERROR_HPP_ */
