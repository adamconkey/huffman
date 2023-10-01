#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <huffman/huffman.hpp>


TEST_CASE("Validate char frequency computation", "[huffman]") {

    Huffman huffman;


    SECTION("Empty string") {
	CHECK(huffman.computeFrequencies("").empty());
    }

    SECTION("Single letter") {
	std::string input("a");
	FrequencyMap expected = {{'a', 1}};
	
	CHECK(huffman.computeFrequencies(input) == expected);
    }
    
    SECTION("Single word unique letters") {
	std::string input("computer");
	FrequencyMap expected;
	for (char c : input)
	    expected.insert({c, 1});

	CHECK(huffman.computeFrequencies(input) == expected);
    }

    SECTION("Single word duplicate letters") {
	std::string input("blueberry");
	FrequencyMap expected = {
	    {'b', 2},
	    {'l', 1},
	    {'u', 1},
	    {'e', 2},
	    {'r', 2},
	    {'y', 1}
	};

	CHECK(huffman.computeFrequencies(input) == expected);
    }

    SECTION("Lowercase and capital are counted as different") {
	std::string input("Aa");
	FrequencyMap expected = {{'A', 1}, {'a', 1}};

	CHECK(huffman.computeFrequencies(input) == expected);
    }

    SECTION("Sentence with spaces") {
	std::string input("Coding is fun when it works.");
	FrequencyMap expected = {
	    {'C', 1},
	    {'o', 2},
	    {'d', 1},
	    {'i', 3},
	    {'n', 3},
	    {'g', 1},
	    {' ', 5},
	    {'s', 2},
	    {'f', 1},
	    {'u', 1},
	    {'w', 2},
	    {'h', 1},
	    {'e', 1},
	    {'t', 1},
	    {'r', 1},
	    {'k', 1},
	    {'.', 1},
	};

	CHECK(huffman.computeFrequencies(input) == expected);
    }
    
}
