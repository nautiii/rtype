/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Packet
*/

#ifdef __linux__
    #include <arpa/inet.h>
#else
    #include <winsock2.h>
#endif

#include "Packet.hpp"

Packet::Packet()
{
    packlen_t packet_size = 0;

    _data.reserve(512);
    *this << packet_size;
    _index = sizeof(packlen_t);
}

bool Packet::check_size(size_t size) const
{
    if (size > _data.size() + _index) {
        throw(PacketTooSmallError());
        return (false);
    }
    return (true);
}

void Packet::append(const void *data, std::size_t size)
{
    if (size <= 0)
        return;
    std::size_t start = _data.size();
    _data.resize(_data.size() + size);
    std::memcpy(&_data[start], data, size);
    size_changed();
}

void Packet::edit(const void *data, std::size_t pos,std::size_t size)
{
    if (size <= 0)
        return;
    std::memcpy(&_data[pos], data, size);
}

void Packet::resize(size_t size)
{
    _data.resize(_data.size() + size);
    size_changed();
}

Packet &Packet::operator>>(int8_t &data)
{
    if (check_size(sizeof(data))) {
        data = *reinterpret_cast<const int8_t*>(&_data[_index]);
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(uint8_t &data)
{
    if (check_size(sizeof(data))) {
        data = *reinterpret_cast<const uint8_t*>(&_data[_index]);
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(int16_t &data)
{
    if (check_size(sizeof(data))) {
        data = ntohs(*reinterpret_cast<const int16_t*>(&_data[_index]));
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(uint16_t &data)
{
    if (check_size(sizeof(data))) {
        data = ntohs(*reinterpret_cast<const uint16_t*>(&_data[_index]));
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(int32_t &data)
{
    if (check_size(sizeof(data))) {
        data = ntohl(*reinterpret_cast<const int32_t*>(&_data[_index]));
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(uint32_t &data)
{
    if (check_size(sizeof(data))) {
        data = ntohl(*reinterpret_cast<const uint32_t*>(&_data[_index]));
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(int64_t &data)
{
    if (check_size(sizeof(data))) {
        const int8_t *bytes = reinterpret_cast<const int8_t*>(&_data[_index]);
        data = (static_cast<int64_t>(bytes[0]) << 56) |
               (static_cast<int64_t>(bytes[1]) << 48) |
               (static_cast<int64_t>(bytes[2]) << 40) |
               (static_cast<int64_t>(bytes[3]) << 32) |
               (static_cast<int64_t>(bytes[4]) << 24) |
               (static_cast<int64_t>(bytes[5]) << 16) |
               (static_cast<int64_t>(bytes[6]) <<  8) |
               (static_cast<int64_t>(bytes[7])      );
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(uint64_t &data)
{
    if (check_size(sizeof(data))) {
        const uint8_t *bytes = reinterpret_cast<const uint8_t*>(&_data[_index]);
        data = (static_cast<uint64_t>(bytes[0]) << 56) |
               (static_cast<uint64_t>(bytes[1]) << 48) |
               (static_cast<uint64_t>(bytes[2]) << 40) |
               (static_cast<uint64_t>(bytes[3]) << 32) |
               (static_cast<uint64_t>(bytes[4]) << 24) |
               (static_cast<uint64_t>(bytes[5]) << 16) |
               (static_cast<uint64_t>(bytes[6]) <<  8) |
               (static_cast<uint64_t>(bytes[7])      );
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(float &data)
{
    if (check_size(sizeof(data))) {
        data = *reinterpret_cast<const float*>(&_data[_index]);
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(double &data)
{
    if (check_size(sizeof(data))) {
        data = *reinterpret_cast<const double*>(&_data[_index]);
        _index += sizeof(data);
    }
    return (*this);
}

Packet &Packet::operator>>(std::string &data)
{
    uint32_t len = 0;

    *this >> len;
    data.clear();
    if (check_size(len)) {
        data.assign(static_cast<char*>(&_data[_index]), len);
        _index += len;
    }
    return (*this);
}

Packet &Packet::operator<<(int8_t data)
{
    append(&data, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(uint8_t data)
{
    append(&data, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(int16_t data)
{
    int16_t wdata = htons(data);
    append(&wdata, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(uint16_t data)
{
    uint16_t wdata = htons(data);
    append(&wdata, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(int32_t data)
{
    int32_t wdata = htonl(data);
    append(&wdata, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(uint32_t data)
{
    uint32_t wdata = htonl(data);
    append(&wdata, sizeof(data));
    return (*this);
}

Packet& Packet::operator <<(int64_t data) {
    int8_t toWrite[] =
    {
        static_cast<int8_t>((data >> 56) & 0xFF),
        static_cast<int8_t>((data >> 48) & 0xFF),
        static_cast<int8_t>((data >> 40) & 0xFF),
        static_cast<int8_t>((data >> 32) & 0xFF),
        static_cast<int8_t>((data >> 24) & 0xFF),
        static_cast<int8_t>((data >> 16) & 0xFF),
        static_cast<int8_t>((data >>  8) & 0xFF),
        static_cast<int8_t>((data      ) & 0xFF)
    };
    append(&toWrite, sizeof(toWrite));
    return *this;
}

Packet& Packet::operator <<(uint64_t data) {
    uint8_t toWrite[] =
    {
        static_cast<uint8_t>((data >> 56) & 0xFF),
        static_cast<uint8_t>((data >> 48) & 0xFF),
        static_cast<uint8_t>((data >> 40) & 0xFF),
        static_cast<uint8_t>((data >> 32) & 0xFF),
        static_cast<uint8_t>((data >> 24) & 0xFF),
        static_cast<uint8_t>((data >> 16) & 0xFF),
        static_cast<uint8_t>((data >>  8) & 0xFF),
        static_cast<uint8_t>((data      ) & 0xFF)
    };
    append(&toWrite, sizeof(toWrite));
    return *this;
}

Packet &Packet::operator<<(float data)
{
    append(&data, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(double data)
{
    append(&data, sizeof(data));
    return (*this);
}

Packet &Packet::operator<<(const std::string& data)
{
    *this << static_cast<uint32_t>(data.size());
    if (data.size() > 0)
        append(data.c_str(), data.size() * sizeof(std::string::value_type));
    return (*this);
}

const char *Packet::get_read_pos() const
{
    return (&_data[_index]);
}

char *Packet::get_write_pos()
{
    return (&_data[_index]);
}

char *Packet::get_array()
{
    return (&_data[0]);
}

void Packet::move_cursor(int move)
{
    _index += move;
}

void Packet::reset_index()
{
    _index = sizeof(packlen_t);
}

std::size_t Packet::get_size() const
{
    return (_data.size());
}

const std::vector<char> Packet::get_data() const
{
    return _data;
}

void Packet::size_changed()
{
    uint16_t wdata = htons(_data.size());
    edit(&wdata, 0, sizeof(wdata));
}

void Packet::print_raw() const
{
    for (auto c : _data)
        std::cout << static_cast<int>(c) << " ";
    std::cout << std::endl;
}

void Packet::print_raw_from_index() const
{
    for (int i = _index; i < _data.size(); i++)
        std::cout << static_cast<int>(_data[i]) << " ";
    std::cout << std::endl;
}
