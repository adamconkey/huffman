#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
// #include <modern/huffman.hpp>



TEST_CASE( "Sanity", "[main]" ) {
    int a = 1 + 2;

    REQUIRE(a == 3);
}
