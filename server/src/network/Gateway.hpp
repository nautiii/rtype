/*
** EPITECH PROJECT, 2020
** src
** File description:
** Gateway
*/

#ifndef GATEWAY_HPP_
#define GATEWAY_HPP_

#include <string>
#include <memory>
#include <set>
#include <vector>

/** @brief Contains every objects for the network */
namespace network {

class Room;
typedef std::shared_ptr<Room> roomShared_t;
typedef std::weak_ptr<Room> roomWeak_t;

/** @brief The Gateway class */
class Gateway {
    public:
        Gateway();
        ~Gateway();

        /** @brief The function to create a room with it name */
        std::string createRoom(const std::string &name = std::string("default"));

        /** @brief The function to create a room with it id */
        std::string createRoom(int &id);
        
        /** @brief Retrieve a room with it name */
        roomShared_t getRoom(const std::string &name);

        /** @brief Retrieve a room with it id*/
        roomShared_t getRoom(const uint16_t &id);

        /** @brief Retrieve the name of all rooms */
        std::vector<std::string> getRoomListNames();

        /** @brief Retrieve the id of all rooms */
        std::vector<uint16_t> getRoomListIds();

    private:
        std::set<roomShared_t> _rooms;
        uint16_t _nbRoomsCreated;
};

}

#endif /* !GATEWAY_HPP_ */
