set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(out main.cpp)

# Configure testing with GTest
find_package(GTest CONFIG REQUIRED)
add_executable(test test.cpp)
target_link_libraries(test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test)
