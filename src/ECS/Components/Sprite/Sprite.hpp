#pragma once

#include "../../../Logger/Logger.hpp"
#include "../Component.hpp"
#include <raylib.h>

#include <string>

class SpriteComponent : public Component {
public:
  // Удобный современный конструктор
  SpriteComponent(const std::string& path);

  // Функция загрузки текстуры (const char*, как требует Raylib)
  bool LoadTextureSprite(const char* path);

  void setColor(Color color) {
    this->color = color;
  }
  void setSource(float x, float y, float width, float height) {
    source = {x, y, width, height};
  }

  int getHeightSprite() {
    return texture.height;
  }
  int getWidthSprite() {
    return texture.width;
  }
  Color getColor() {
    return color;
  }
  Texture2D getTexture() {
    return texture;
  }
  Rectangle getSource() {
    return source;
  }

private:
  Texture2D texture{0}; // Инициализация Raylib стиля
  Color color = WHITE;
  Rectangle source{0, 0, 0, 0};
};
