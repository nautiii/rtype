/*
** EPITECH PROJECT, 2020
** src
** File description:
** Gateway
*/

#include "Gateway.hpp"

#include "Room.hpp"

namespace network {

Gateway::Gateway():
_nbRoomsCreated(0)
{
}

Gateway::~Gateway()
{
}

std::string Gateway::createRoom(const std::string &name)
{
    _nbRoomsCreated++;
    std::string tmp = name;
    if (name == "default")
        tmp = "Room: " + std::to_string(_nbRoomsCreated);
    _rooms.insert(std::make_shared<Room>(_nbRoomsCreated, tmp));
    return (tmp);
}

std::string Gateway::createRoom(int &id)
{
    _nbRoomsCreated++;
    std::string tmp = "Room: " + std::to_string(_nbRoomsCreated);
    _rooms.insert(std::make_shared<Room>(_nbRoomsCreated, tmp));
    id = _nbRoomsCreated;
    return (tmp);
}

roomShared_t Gateway::getRoom(const std::string &name)
{
    for (roomShared_t room : _rooms) {
        if (room->getName() == name)
            return room;
    }
    return NULL;
}

roomShared_t Gateway::getRoom(const uint16_t &id)
{
    for (roomShared_t room : _rooms) {
        if (room->getId() == id)
            return room;
    }
    return NULL;
}

std::vector<std::string> Gateway::getRoomListNames()
{
    std::vector<std::string> roomList;

    for (roomShared_t room : _rooms) {
        roomList.push_back(room->getName());
    }
    return roomList;
}

std::vector<uint16_t> Gateway::getRoomListIds()
{
    std::vector<uint16_t> roomList;

    for (roomShared_t room : _rooms) {
        roomList.push_back(room->getId());
    }
    return roomList;
}

}