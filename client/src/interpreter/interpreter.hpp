/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** interpreter
*/

#ifndef INTERPRETER_CLIENT_HPP_
#define INTERPRETER_CLIENT_HPP_

#include <map>
#include <string>
#include <memory>
#include "network/protocol/Protocol.hpp"
#include "mediator/MediatorEvent.hpp"
#include "engine/Engine.hpp"
#include "Client.hpp"

class Client;

namespace interpreter {

void interpreter(network::Client *client, std::shared_ptr<engine::Engine> eng, std::shared_ptr<mediator::MediatorEvent> mediator, const protocol::UdpPacket &packet);

static std::map<protocol::PacketType, std::string> network_event_name = {
    {protocol::LAUNCH_GAME, "net_launch_ok"},
    {protocol::CREATE_ENTITY, "net_create_entity"},
    {protocol::CONNECT_OK, "net_connect_ok"},
    {protocol::CONNECT_ERR, "net_connect_err"},
    {protocol::ROOMLIST_OK, "net_room_list_ok"},
    {protocol::ROOMLIST_ERR, "net_room_list_err"},
    {protocol::ROOM_JOIN_ERR, "net_room_join_ok"},
    {protocol::ROOM_JOIN_OK, "net_room_join_err"},
    {protocol::ROOM_CREATE_OK, "net_room_create_ok"},
    {protocol::ROOM_CREATE_ERR, "net_room_create_err"},
    {protocol::ROOM_DESTROY_OK, "net_room_destroy_ok"},
    {protocol::ROOM_DESTROY_ERR, "net_room_destroy_err"},
    {protocol::SEND_TO_ROOM_OK, "net_send_to_room_ok"},
    {protocol::SEND_TO_ROOM_ERR, "net_send_to_room_err"},
    {protocol::STATUS_UPDATED, "net_status_updated_ok"},
    {protocol::STATUS_UPDATE_ERR, "net_status_updated_err"},
    {protocol::LAUNCH_OK, "net_launch_ok"},
    {protocol::LAUNCH_ERR, "net_launch_err"},
    {protocol::PLAYER_KILL_MOB, "net_player_kill_mob"},
    {protocol::PLAYER_DEAD, "net_player_dead"},
    {protocol::PLAYER_SHOOT, "net_player_shot"},
    {protocol::PLAYER_MOVE, "net_player_move"},
    {protocol::PLAYER_DAMAGED, "net_player_damaged"},
    {protocol::PLAYER_SCORE_UPDATE, "net_player_score_update"},
    {protocol::PLAYER_TOUCH_MOB, "net_player_touch_mob"},
};

}

#endif /* !INTERPRETER_HPP_ */
