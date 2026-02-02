target("MyGame")
    set_kind("binary")
    add_files("*.cpp")

    add_deps("EngineLib")

    add_packages("raylib", "rapidjson")
    add_options("editor")  -- Добавляем опцию editor для применения define EDITOR
target_end()
