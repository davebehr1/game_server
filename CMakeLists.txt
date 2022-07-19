cmake_minimum_required(VERSION 3.14)
project(game_server)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


file(GLOB SOURCES
    *.h
    *.cpp
)

add_executable(
  game_server
  ${SOURCES}
)

target_link_libraries(
  game_server
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(game_server)