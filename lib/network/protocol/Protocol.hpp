/*
** EPITECH PROJECT, 2020
** R-Type
** File description:
** Protocol.hpp
*/

#ifndef PROTOCOL_HPP_
#define PROTOCOL_HPP_

#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/interprocess/streams/bufferstream.hpp>
#include <boost/asio.hpp>
#include <SFML/System/Vector2.hpp>

#include "Packet.hpp"

using namespace boost::interprocess;

const uint16_t DEFAULT_LENGTH = 512;

namespace protocol
{
    const int UUID_SIZE = 16;
    const uint32_t MAX_NAME_LENGTH = 16;
    const int MAX_DATA_SIZE = 460;

    enum PacketType
    {
        /*    Client      */
        UNDEFINED,
        TRY_CONNECT,
        GET_ROOMLIST,
        JOIN_ROOM,
        CREATE_ROOM,
        DESTROY_ROOM,
        UPDATE_STATUS,
        LAUNCH_GAME,
        KILL_MOB,
        DEAD,
        SHOOT,
        MOVE,
        DAMAGE_TAKEN,
        SCORE,
        TOUCH_MOB,
        CREATE_ENTITY,

        /*   Server      */
        CONNECT_OK,
        CONNECT_ERR,
        ROOMLIST_OK,
        ROOMLIST_ERR,
        ROOM_JOIN_ERR,
        ROOM_JOIN_OK,
        ROOM_CREATE_OK,
        ROOM_CREATE_ERR,
        ROOM_DESTROY_OK,
        ROOM_DESTROY_ERR,
        SEND_TO_ROOM_OK,
        SEND_TO_ROOM_ERR,
        STATUS_UPDATED,
        STATUS_UPDATE_ERR,
        LAUNCH_OK,
        LAUNCH_ERR,
        PLAYER_KILL_MOB,
        PLAYER_DEAD,
        PLAYER_SHOOT,
        PLAYER_MOVE,
        PLAYER_DAMAGED,
        PLAYER_SCORE_UPDATE,
        PLAYER_TOUCH_MOB
    };

    struct UdpHeader
    {
        int16_t dst;
        uint16_t len;
        PacketType type;
        //bool reliable;
        //char uuid[UUID_SIZE];
        char data;
    };

    struct SerializedUdpPacket
    {
        UdpHeader *data;
        size_t size;
    };

    struct UdpPacket
    {
        int16_t dst;
        uint16_t len;
        PacketType type;
        //bool reliable;
        //char uuid[UUID_SIZE];
        void *data;

        public:
            UdpPacket();
            UdpPacket(int16_t mdst, int mlen, void *mdata, const PacketType &mtype=PacketType::UNDEFINED);
            ~UdpPacket();
            SerializedUdpPacket serialize();
            void deserialize(void *packet);
            UdpPacket &operator=(const UdpPacket&) = delete;
            bool operator==(const UdpPacket& other);
        private:
            UdpHeader *serialized = NULL;
    };
}

namespace structureProtocol {

typedef struct roomList_s {
    char name[protocol::MAX_NAME_LENGTH];
    uint16_t id;
} roomList_t;

typedef struct createEntity_s {
    char uuid[protocol::UUID_SIZE];
    char node[protocol::MAX_DATA_SIZE];
} createEntity_t;

typedef struct posUpdate_s {
    char uuid[protocol::UUID_SIZE];
    sf::Vector2f pos;
    sf::Vector2f dir;
} posUpdate_t;

}

#endif
