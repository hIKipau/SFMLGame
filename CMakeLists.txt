cmake_minimum_required(VERSION 3.30)
project(SimpleGameSFML)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 3.0.0 REQUIRED COMPONENTS Graphics System Window )

add_executable(SimpleGameSFML main.cpp Buttons.cpp Buttons.hpp)

target_link_libraries(SimpleGameSFML SFML::Graphics SFML::System SFML::Window)