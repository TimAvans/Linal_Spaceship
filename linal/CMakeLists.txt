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
    src/math/Vector4.cpp "src/Renderer.cpp" "include/Renderer.hpp" "src/DrawableObject.cpp" "include/DrawableObject.hpp" "include/Vector3.hpp" "src/Camera.cpp" "include/Camera.hpp" "include/GameObject.hpp" "src/GameObject.cpp" "include/GameObject.hpp" "src/Bullet.cpp" "include/Bullet.hpp" "src/Ship.cpp" "include/Ship.hpp" )

target_link_libraries(linal_spaceship sfml-graphics)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  Testing
  src/Unit_Tests.cc
  include/Transform.hpp
  src/math/Transform.cpp
  include/Vector.hpp
  src/math/Vector.cpp
  include/Vector3.hpp
  include/Vector4.hpp
  src/math/Vector4.cpp
)
target_link_libraries(
  Testing
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(Testing)

add_test(
    NAME Testing
    COMMAND Testing
)