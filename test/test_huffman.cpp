#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <huffman/huffman.hpp>


TEST_CASE("Empty string", "[huffman]") {
    Huffman huffman;
    std::string text;
    FrequencyMap freqs;
    TreeNode encoding_tree;
    
    SECTION("Compute frequencies") {
	CHECK( huffman.computeFrequencies(text).empty() );
    }

    SECTION("Create encoding tree") {
	CHECK( *huffman.createEncodingTree(freqs).get() == encoding_tree );
    }
}


TEST_CASE("Single letter", "[huffman]") {
    Huffman huffman;
    std::string text("a");
    FrequencyMap freqs = {{'a', 1}};
    TreeNode encoding_tree(1, 'a');
    
    SECTION("Compute frequencies") {
	CHECK( huffman.computeFrequencies(text) == freqs );
    }

    SECTION("Create encoding tree") {
	CHECK( *huffman.createEncodingTree(freqs).get() == encoding_tree );
    }
}
    

TEST_CASE("Single word unique letters", "[huffman]") {
    Huffman huffman;
    std::string text("love");
    FrequencyMap freqs = {{'l', 1}, {'o', 1}, {'v', 1}, {'e', 1}};
    TreeNode encoding_tree(4);
    encoding_tree.left = std::make_shared<TreeNode>(2);
    encoding_tree.left->left = std::make_shared<TreeNode>(1, 'l');
    encoding_tree.left->right = std::make_shared<TreeNode>(1, 'o');
    encoding_tree.right = std::make_shared<TreeNode>(2);
    encoding_tree.right->left = std::make_shared<TreeNode>(1, 'v');
    encoding_tree.right->right = std::make_shared<TreeNode>(1, 'e');
	

    SECTION("Compute frequencies") {
	CHECK( huffman.computeFrequencies(text) == freqs );
    }

    SECTION("Create encoding tree") {

	// TODO I think it actually doesn't make sense to check the encoding tree
	// explicitly, it would require PQ maintains order on ties which is
	// unnecessary to impose even if it were true.
	
	// CHECK( *huffman.createEncodingTree(freqs).get() == encoding_tree );
    }
}
    
    // SECTION("Single word duplicate letters") {
    // 	std::string input("blueberry");
    // 	FrequencyMap expected = {
    // 	    {'b', 2},
    // 	    {'l', 1},
    // 	    {'u', 1},
    // 	    {'e', 2},
    // 	    {'r', 2},
    // 	    {'y', 1}
    // 	};

    // 	CHECK(huffman.computeFrequencies(input) == expected);
    // }

    // SECTION("Lowercase and capital are counted as different") {
    // 	std::string input("Aa");
    // 	FrequencyMap expected = {{'A', 1}, {'a', 1}};

    // 	CHECK(huffman.computeFrequencies(input) == expected);
    // }

    // SECTION("Sentence with spaces") {
    // 	std::string input("Coding is fun when it works.");
    // 	FrequencyMap expected = {
    // 	    {'C', 1},
    // 	    {'o', 2},
    // 	    {'d', 1},
    // 	    {'i', 3},
    // 	    {'n', 3},
    // 	    {'g', 1},
    // 	    {' ', 5},
    // 	    {'s', 2},
    // 	    {'f', 1},
    // 	    {'u', 1},
    // 	    {'w', 2},
    // 	    {'h', 1},
    // 	    {'e', 1},
    // 	    {'t', 1},
    // 	    {'r', 1},
    // 	    {'k', 1},
    // 	    {'.', 1},
    // 	};

    // 	CHECK(huffman.computeFrequencies(input) == expected);
    // }
    

