#include "viewport.hpp"
#include "../../../engine/Engine.hpp"
#include "../../../graphics/Render2D/Render2D.hpp"
#include "../../../graphics/Render3D/Render3D.hpp"
#include <imgui.h>
#include <rlImGui.h>

void Viewport::onUpdate() {
  if (ImGui::Begin("Viewport")) {
    ImGui::Text("Viewport");

    isWindowActive = ImGui::IsWindowHovered() && ImGui::IsWindowFocused();

    RenderTexture2D& targetTexture = engine.is3Dmode()
                                         ? render3Dsystem.getRenderTexture()
                                         : render2Dsystem.getRenderTexture();
    rlImGuiImageRenderTextureFit(&targetTexture, false);
  }
  ImGui::End();
}

bool Viewport::getiswindowActive() {
  return isWindowActive;
}