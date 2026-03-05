cmake_minimum_required(VERSION 3.15)
project(BinarySearchTree VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/aluno.cpp
    src/arvorebinaria.cpp
    src/estatisticas.cpp
    src/relatorio.cpp
    src/exportador.cpp
    src/main.cpp
)

add_executable(binary-tree ${SOURCES})

target_include_directories(binary-tree PRIVATE ${PROJECT_SOURCE_DIR}/include)
