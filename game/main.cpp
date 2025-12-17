#include "../src/ECS/Components/Camera/Camera3D/Camera3D.hpp"   
#include "../src/rica.hpp"
#include "../src/engine/Engine.hpp"
#include "player.hpp"
#include "raylib.h"
#include <iostream>
#include <memory> 

const int screenWidth = 1920;
const int screenHeight = 1080;

class GameScene : public Scene { 
 private: 
     std::shared_ptr<Player> player; 
     std::shared_ptr<Entity> cameraEntity; 

     int timeLoc; 
     int resolutionLoc; 
     float resolution[2];  

 public: 
     GameScene() { 
         cameraEntity = std::make_shared<Entity>(); 
         auto cam3D = std::make_shared<Camera3DComponent>( 
             Vector3{0.0f, 2.0f, 10.0f},  
             130.0f, 
             true 
         ); 
         cam3D->setTarget({0.0f, 0.0f, 0.0f});  
         cameraEntity->addComponent(cam3D); 
         this->createEntity(cameraEntity); 
         player = std::make_shared<Player>(); 
         this->createEntity(player); 
         
         Shader& engineShader = engine.getShader(); 

        engineShader = LoadShader(0, "raymarching.fs");  
         
         timeLoc = GetShaderLocation(engineShader, "time"); 
         resolutionLoc = GetShaderLocation(engineShader, "resolution"); 

         resolution[0] = (float)screenWidth; 
         resolution[1] = (float)screenHeight; 
          
         SetShaderValue(engineShader, resolutionLoc, resolution, SHADER_UNIFORM_VEC2); 
     } 

     ~GameScene() {
     }

     void OnUpdate(float dt) override { 
         Shader& engineShader = engine.getShader(); 
         float time = (float)GetTime(); 
         SetShaderValue(engineShader, timeLoc, &time, SHADER_UNIFORM_FLOAT);           
         if (player) player->update(dt); 
     } 
 };

bool gameStart() {
    engine.set3Dmode(true);
    if (!engine.init()) return false; 

    engine.sceneManager.setSceneLimit(10);
    engine.sceneManager.CreateScene<GameScene>(1);

    return true;
}