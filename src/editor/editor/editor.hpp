#pragma once
#include "../panel/allPanels/terminal/terminal.hpp"
#include "../panel/allPanels/viewport/viewport.hpp"
#include "../panel/panel.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

class Editor {
protected:
Viewport &getViewport(){
    return viewport;
}

private:
    Terminal terminal;
    Viewport viewport;

    Editor() = default; 

public:
    friend class Input;

    Editor(const Editor&) = delete;
    Editor& operator=(const Editor&) = delete;

    static Editor& getInstance() {
        static Editor instance;
        return instance;
    }

    void init(){
    ImGuiIO& io = ImGui::GetIO(); 
    io.ConfigFlags |=ImGuiConfigFlags_DockingEnable; 
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    }

    void onUpdate() {
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        
        terminal.onUpdate();
        viewport.onUpdate();
    }

    PanelEditor & getPanel(std::string name) {
        if (name == "Terminal") {
            return terminal;
        } else if (name == "Viewport") {
            return viewport;
        } else {
        return terminal;
        }
    }
};

extern Editor& editor;