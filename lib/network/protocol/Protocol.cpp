/*
** EPITECH PROJECT, 2020
** R-Type
** File description:
** pp
*/

#include <stdlib.h>
#include "Protocol.hpp"

namespace protocol {

UdpPacket::UdpPacket()
{
    // auto boost_uid = boost::uuids::random_generator();
    // std::memcopy
}

UdpPacket::UdpPacket(int16_t mdst, int mlen, void *mdata, const PacketType &mtype):
dst(mdst), len(mlen), data(mdata), type(mtype)
{
    /*auto boost_uid = boost::uuids::random_generator()();
    std::memcpy(uuid, boost_uid.data, UUID_SIZE);*/

}

UdpPacket::~UdpPacket()
{
    // if (serialized)
    //     delete[] serialized;
}

bool UdpPacket::operator==(const UdpPacket& other)
{
    return (other.dst == dst && other.len == len && other.type == type) ? true : false;
}

SerializedUdpPacket UdpPacket::serialize()
{
    SerializedUdpPacket packet;
    serialized = reinterpret_cast<UdpHeader*>(new char[sizeof(UdpHeader) - sizeof(char) + len]);
    std::memset(serialized, 0, sizeof(UdpHeader) - sizeof(char) + len);
    packet.data = serialized;
    packet.data->dst = dst;
    packet.data->len = len;
    packet.data->type = type;
    // std::memcpy(&packet.data->dst, &dst, sizeof(UdpHeader));
    std::memcpy(&packet.data->data, data, len);
    packet.size = sizeof(UdpHeader) - sizeof(char) + len;

    return (packet);
}

void UdpPacket::deserialize(void *packet)
{
    serialized = static_cast<UdpHeader*>(packet);
    dst = serialized->dst;
    len = serialized->len;
    type = serialized->type;
    //reliable = serialized->reliable;
    data = &serialized->data;
}

}
