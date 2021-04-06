cmake_minimum_required(VERSION 3.12)
project(linal_spaceship)

set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib/windows/SFML-2.5.1/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES true)
endif ()

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(linal_spaceship
    src/App.cpp
    src/math/Vector.cpp
    src/math/Transform.cpp 
    src/math/Vector4.cpp "src/Renderer.cpp" "include/Renderer.hpp" "src/DrawableObject.cpp" "include/DrawableObject.hpp" "include/Vector3.hpp" "src/Camera.cpp" "include/Camera.hpp" "include/GameObject.hpp" "src/GameObject.cpp" "include/GameObject.hpp" "src/Bullet.cpp" "include/Bullet.hpp" "src/Ship.cpp" "include/Ship.hpp")

target_link_libraries(linal_spaceship sfml-graphics)
