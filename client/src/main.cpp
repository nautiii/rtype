/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** main
*/

#include <iostream>
#include <thread>
#include "engine/Engine.hpp"
#include "Client.hpp"
#include "Getopt.hpp"
#include "menu/Menu.hpp"
#include "game/Game.hpp"

void startClientThread(Getopt getopt, std::shared_ptr<engine::Engine> eng)
{
    try {
        boost::asio::io_context ioContext;
        network::Client client(ioContext, getopt.getIp(), getopt.getPort(), eng);
        // eng->get_mediator()->add_event_listener("send_network_event", &client, receive_client_network_event);
        std::cout << "ici" << std::endl;
        ioContext.run();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
    }
}

int main(int argc, char **argv, char **envp)
{
    Getopt getopt(argc, argv);

    if (!getopt.getIsValid())
        return 0;
    std::shared_ptr<engine::Engine> eng = std::make_shared<engine::Engine>();
    std::thread network_thread(startClientThread, getopt, eng);
    network_thread.detach();

    eng->load("config/main.yml");
    eng->change_scene<menu::Menu>();
    eng->run();
    return (0);
}