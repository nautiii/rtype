/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Exchange
*/

#include <iostream>
#include <boost/array.hpp>
#include <chrono>
#include <cstring>
#include "Exchange.hpp"

namespace network
{

Exchange::Exchange(io_context &ioContext, const uint32_t &port):
_socket(ioContext, ip::udp::endpoint(ip::udp::v4(), port))
{
}

Exchange::Exchange(io_context &ioContext):
_socket(ioContext)
{
    _socket.open(ip::udp::v4());
}

Exchange::~Exchange()
{
}

void Exchange::send(ip::udp::endpoint const &endpoint, protocol::UdpPacket &packet)
{
    protocol::SerializedUdpPacket data = packet.serialize();
    _socket.async_send_to(
        boost::asio::buffer(data.data, data.size),
        endpoint,
        boost::bind(
            &Exchange::_handleSend,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
}

void Exchange::recv(ip::udp::endpoint &endpoint)
{
    boost::system::error_code error;
    void *buff = new char[DEFAULT_LENGTH];
    _packet = std::make_shared<protocol::UdpPacket>();

    _socket.receive_from(
        boost::asio::buffer(buff, DEFAULT_LENGTH),
        endpoint, 0, error);
    if (error) {
        std::cerr << error.message() << std::endl;
        throw std::exception();
    }
    _packet->deserialize(buff);
}

void Exchange::_handleSend(const error_code &error, std::size_t size)
{
    if (error)
    {
        std::cerr << error.message() << std::endl;
    }
}

}