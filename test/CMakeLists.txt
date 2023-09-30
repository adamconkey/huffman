# Testing library (adds Catch2::Catch2)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)

add_executable(test_huffman test_huffman.cpp)

target_link_libraries(test_huffman PRIVATE huffman Catch2::Catch2)

add_test(NAME huffman_test COMMAND test_huffman) # Command can be a target
