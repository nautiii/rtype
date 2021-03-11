/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** main
*/

#include <boost/asio.hpp>
#include <iostream>
#include <csignal>
#include "Server.hpp"
#include "Getopt.hpp"

void signalHandler(int signum)
{
    exit(0);
}

int main(int argc, char *argv[])
{
    Getopt getopt(argc, argv);

    if (!getopt.getIsValid())
        return 0;

    try {
        boost::asio::io_context ioContext;
        signal(SIGINT, signalHandler);
        network::Server server(ioContext, getopt.getPort());
        ioContext.run();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
        return 0;
    }
    return 0;
}