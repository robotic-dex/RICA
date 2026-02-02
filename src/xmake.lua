target("rlImGui")
	set_kind("static")

	add_files(
			"../lib/rlImGui/*.cpp"
	)

	add_includedirs("../lib/rlImGui", {public=true})

	add_packages("raylib", "imgui", {public=true})
target_end()

target("EngineLib")
    set_kind("static")
    add_files(
        "Audio/*.cpp",
        "Collider/**/*.cpp",
        "ECS/**/*.cpp",
        "engine/*.cpp",
        "graphics/**/*.cpp",
        "Logger/*.cpp",
        "Physic/**/*.cpp",
        "Scene/*.cpp",
        "UI/*.cpp",
        "Var/*.cpp",
        "Input/*.cpp"
    )

    if has_config("editor") then
        add_files(        
        "editor/editor/*.cpp",
        "editor/panel/allPanels/terminal/*.cpp",
        "editor/panel/allPanels/viewport/*.cpp")

        add_includedirs("editor/editor/")
    end

    add_includedirs(
        ".",
        "ECS/Components/",
        "ECS/Components/Audio/",
        "ECS/Components/Camera/",
        "ECS/Components/Collider/Collider2D/",
        "ECS/Components/Physic/",
        "ECS/Components/Sprite/",
        "ECS/Components/Transform/",
        "ECS/Objects/",
        "ECS/Systems/",
        "Collider/",
        "Collider/Collider2D/",
        "engine/",
        "graphics/",
        "Logger/",
        "Scene/",
        "UI/",
        "Input/"
    )

    add_packages("raylib", "rapidjson", "imgui", {public=true})
    add_deps("rlImGui", {public=true})
    add_options("editor") 
target_end()
