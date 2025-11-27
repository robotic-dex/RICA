#pragma once 

// Предварительные объявления 
class Component; 
class SpriteComponent; 
class TransformComponent; 
class Camera2DComponent;
class Entity; 
class Player; 
class Terminal; 
class Log; 
class Collider2DSystem;
class RenderSystem;
class AudioSystem;

#include "lib/raylib/src/raylib.h"
#include "lib/raylib/src/raymath.h"

#include "lib/rapidjson1/rapidjson/document.h"

#include <vector> 
#include <memory> 
#include <string> 

#include "Logger/Logger.hpp" 

// Компоненты ECS 
#include "ECS/Components/Component.hpp" 
#include "ECS/Components/Sprite/Sprite.hpp" 
#include "ECS/Components/Transform/Transform.hpp" 
#include "ECS/Components/Collider2D/Collider2D.hpp"
#include "ECS/Components/Audio/Audio.hpp"
#include "ECS/Components/Camera/Camera2D/Camera2D.hpp"
// Объекты ECS 
#include "ECS/Objects/Entity.hpp" 

// системы 
#include "graphics/Render.hpp" 
#include "Collider/Collider2D/Collider2D.hpp"
#include "Audio/Audio.hpp"
// Мир 
#include "Scene/Scene.hpp" 

// Движок 
#include "engine/Engine.hpp"

//переменные
#include "Var/Var.hpp"