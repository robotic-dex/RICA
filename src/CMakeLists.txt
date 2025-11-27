# 1. Рекурсивный поиск всех .cpp и .c файлов в src
file(GLOB_RECURSE ENGINE_SOURCES "*.cpp" "*.c")

# 2. Исключаем все файлы Raylib
list(FILTER ENGINE_SOURCES EXCLUDE REGEX ".*/lib/raylib/.*")

# 3. Создание статической библиотеки
add_library(EngineLib STATIC ${ENGINE_SOURCES})

# 4. Пути для заголовочных файлов
target_include_directories(EngineLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Component
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Collider2D
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Physics
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Animation
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Audio
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Particles
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/Tilemap
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Objects
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/Collider
    ${CMAKE_CURRENT_SOURCE_DIR}/Collider/Collider2D
    ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/Managers
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/Physic
    ${CMAKE_CURRENT_SOURCE_DIR}/Scene
    ${CMAKE_CURRENT_SOURCE_DIR}/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/Math
    ${CMAKE_CURRENT_SOURCE_DIR}/World

    # Заголовки raylib
    ${CMAKE_SOURCE_DIR}/src/lib/raylib/src

    # Заголовки RapidJSON
    ${CMAKE_SOURCE_DIR}/src/lib/rapidjson
)

# 5. Связываем с raylib
target_link_libraries(EngineLib PUBLIC raylib)
