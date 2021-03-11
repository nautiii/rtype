/*
** EPITECH PROJECT, 2020
** R-Type
** File description:
** unit_tests.cpp
*/

#define BOOST_TEST_MODULE RtypeTests
#include <boost/test/unit_test.hpp>

// BOOST_AUTO_TEST_CASE( my_test )
// {
//     BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
//     BOOST_REQUIRE( add( 2,2 ) == 4 );      // #2 throws on error
//     if( add( 2,2 ) != 4 )
//       BOOST_ERROR( "Ouch..." );            // #3 continues on error
//     if( add( 2,2 ) != 4 )
//       BOOST_FAIL( "Ouch..." );             // #4 throws on error
//     if( add( 2,2 ) != 4 ) throw "Ouch..."; // #5 throws on error
//     BOOST_CHECK_MESSAGE( add( 2,2 ) == 4,  // #6 continues on error
//                          "add(..) result: " << add( 2,2 ) );
//     BOOST_CHECK_EQUAL( add( 2,2 ), 4 );	  // #7 continues on error
// }

#include "network/protocol/Protocol.hpp"

struct DataTest
{
    int value1;
    int value2;
};

BOOST_AUTO_TEST_CASE( network_protocol )
{
    DataTest data = {1234, 5678};
    protocol::UdpPacket pkt(1212, sizeof(DataTest), static_cast<void *>(&data));
    protocol::SerializedUdpPacket hdr = pkt.serialize();

    BOOST_CHECK(hdr.size == sizeof(protocol::UdpHeader) - sizeof(char) + pkt.len);
    BOOST_CHECK(hdr.data->dst == pkt.dst);
    BOOST_CHECK(hdr.data->len == pkt.len);
    BOOST_CHECK(hdr.data->type == pkt.type);

    DataTest *d = reinterpret_cast<DataTest *>(&hdr.data->data);

    BOOST_CHECK_EQUAL(data.value1, d->value1);
    BOOST_CHECK_EQUAL(data.value2, d->value2);
}

#include "network/Exchange.hpp"

BOOST_AUTO_TEST_CASE( network_exchange )
{
    io_context c;
    Exchange ex(c);
    Exchange exg(c, 8080);

    if (ex.getPacket() != nullptr)
        BOOST_FAIL("not null");
    BOOST_CHECK(!exg.getPacket());
}

BOOST_AUTO_TEST_CASE( component )
{
    BOOST_CHECK(true);
}

#include "ecs/EntityManager.hpp"

BOOST_AUTO_TEST_CASE( ecs_entity_manager )
{
    ecs::EntityManager manager;
    std::bitset<ecs::MAX_COMPONENTS> set;
    auto entity = manager.create_entity();

    BOOST_CHECK(manager.create_entity() == 1);
    auto signature = manager.get_signature(entity);
    BOOST_CHECK(signature == set);
    manager.destroy_entity(entity);
    BOOST_CHECK_EQUAL(manager.get_entity_nb(), 1);
}

BOOST_AUTO_TEST_CASE( engine_ )
{
    BOOST_CHECK(true);
}

// BOOST_AUTO_TEST_CASE( network_exchange )
// {
//     BOOST_CHECK(true);
// }

// BOOST_AUTO_TEST_CASE( network_exchange )
// {
//     BOOST_CHECK(true);
// }

// BOOST_AUTO_TEST_CASE( network_exchange )
// {
//     BOOST_CHECK(true);
// }
