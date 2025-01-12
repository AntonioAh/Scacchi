cmake_minimum_required(VERSION 3.10)
project(Scacchi)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set build type to Debug (use Debug or Release)
set(CMAKE_BUILD_TYPE Debug)

find_package(OpenGL REQUIRED)
find_package(GLFW3 3.3 REQUIRED)

file(GLOB Scacchi_SRC
     "./src/*.c"
     "./src/*.cpp"
)

# Add executab1le target
#add_executable(Scacchi ${Scacchi_SRC})

add_executable(Scacchi src/gioco.cpp src/glad.c src/main.cpp src/pedone.cpp src/pezzo.cpp src/resourceManager.cpp src/shader.cpp src/texture.cpp src/utils.cpp)

include_directories(include includes)
include_directories(include includes/Pezzi)

# Link GLFW and OpenGL libraries
target_link_libraries(Scacchi glfw OpenGL::GL)
