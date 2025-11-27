# 1. Рекурсивный поиск исходников игры
file(GLOB_RECURSE GAME_SOURCES "*.cpp" "*.c")

# 2. Создание исполняемого файла
add_executable(MyGame ${GAME_SOURCES})

# 3. Связываем с библиотекой движка
target_link_libraries(MyGame PUBLIC EngineLib)
