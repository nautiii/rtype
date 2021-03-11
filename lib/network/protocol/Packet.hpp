/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Packet
*/

#ifndef PACKET_HPP_
#define PACKET_HPP_

#include <cstring>
#include <stdint.h>
#include <vector>
#include <iostream>

#include "Error.hpp"

namespace network {

    class Packet {
        public:
            Packet();
            ~Packet() = default;
        public:
            using packlen_t = uint16_t;
            static const int MAX_CMD_SIZE = sizeof(int);
        public:
            Packet &operator>>(int8_t& data);
            Packet &operator>>(uint8_t& data);
            Packet &operator>>(int16_t& data);
            Packet &operator>>(uint16_t& data);
            Packet &operator>>(int32_t& data);
            Packet &operator>>(uint32_t& data);
            Packet &operator>>(int64_t& data);
            Packet &operator>>(uint64_t& data);
            Packet &operator>>(float& data);
            Packet &operator>>(double& data);
            Packet &operator>>(std::string &data);
            Packet &operator<<(int8_t data);
            Packet &operator<<(uint8_t data);
            Packet &operator<<(int16_t data);
            Packet &operator<<(uint16_t data);
            Packet &operator<<(int32_t data);
            Packet &operator<<(uint32_t data);
            Packet &operator<<(int64_t data);
            Packet &operator<<(uint64_t data);
            Packet &operator<<(float data);
            Packet &operator<<(double data);
            Packet &operator<<(const std::string& data);
        private:
            bool check_size(size_t size) const;
            void append(const void *data, size_t size);
            void edit(const void *data, size_t pos,size_t size);
            void resize(size_t size);
            void move_cursor(int move);
            void reset_index();
            void print_raw() const;
            void print_raw_from_index() const;
            void size_changed();
            const char *get_read_pos() const;
            char *get_write_pos();
            char *get_array();
        public:
            size_t get_size() const;
            const std::vector<char> get_data() const;
            std::vector<char> _data;
        private:
            size_t _index;
    };
}

using namespace network;

#endif /* !PACKET_HPP_ */
