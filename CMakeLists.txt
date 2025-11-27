cmake_minimum_required(VERSION 3.16)
project(MyGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib
add_subdirectory(src/lib/raylib) 

# Подкаталоги проекта
add_subdirectory(src)
add_subdirectory(game) 

# Папка для бинарников
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
