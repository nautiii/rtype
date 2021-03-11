/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Getopt
*/

#include "Getopt.hpp"

#include <iostream>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

Getopt::Getopt(int argc, char *argv[])
{
    _port = 8000;
    _isValid = _runGetopt(argc, argv);
}

Getopt::~Getopt()
{
}

void Getopt::help()
{
    std::string message(
        "NAME\n"
        "\tr-type_server - start the server\n"
        "\n"
        "SYNOPSIS\n"
        "\tr-type_server [option]\n"
        "\n"
        "DESCRIPTION\n"
        "\t-h, --help\n"
        "\t\tDisplay this help\n"
        "\t-p, --port\n"
        "\t\tChange the port\n"
    );

    std::cout << message << std::endl;
}

bool Getopt::_runGetopt(int argc, char *argv[])
{
    int opt = 0;
    int i = 0;
    struct option options[] = {
        {"port", required_argument, 0, 'p' },
        {"help", no_argument, 0, 'h' },
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv,"p:h", options, &i )) != -1) {
        switch (opt) {
             case 'p' : _port = atoi(optarg);
                 break;
             case 'h' : help();
                 break;
             default: help(); 
                 return false;
        }
    }
    return true;
}
