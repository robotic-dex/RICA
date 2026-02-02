#pragma once
#include "raylib.h"
#ifdef EDITOR
#include "../editor/editor/editor.hpp"
#include "../editor/panel/allPanels/viewport/viewport.hpp"
#include "../editor/panel/panel.hpp"
#endif

class Input {
private:
  Input() = default;

public:
  Input(const Input&) = delete;
  Input& operator=(const Input&) = delete;

  static Input& getInstance() {
    static Input instance;
    return instance;
  }

  static bool isKeyPressed(int key) {
#ifdef EDITOR
    if (!editor.getViewport().getiswindowActive())
      return false;
#endif

    if (IsKeyPressed(key)) {
      return true;
    }
    return false;
  }

  static bool isKeyReleased(int key) {
#ifdef EDITOR
    if (!editor.getViewport().getiswindowActive())
      return false;
#endif

    if (IsKeyReleased(key)) {
      return true;
    }
    return false;
  }

  static bool isKeyDown(int key) {
#ifdef EDITOR
    if (!editor.getViewport().getiswindowActive())
      return false;
#endif

    if (IsKeyDown(key)) {
      return true;
    }
    return false;
  }

  static bool isKeyUp(int key) {
#ifdef EDITOR
    if (!editor.getViewport().getiswindowActive())
      return false;
#endif

    if (IsKeyUp(key)) {
      return true;
    }
    return false;
  }
};

extern Input& input;