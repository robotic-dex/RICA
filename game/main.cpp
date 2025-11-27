#include "../src/rica.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <iostream>

class GameScene:public Scene
{
    private:
    Player* p1;
    shahed* s1;
    public:

    void OnLoad() override{
        p1=Create<Player>();
        s1=Create<shahed>();

    }
    void OnUpdate(float deltaTime) override{
        p1->update(deltaTime);
        s1->update(deltaTime);
    }
};

class World;
class RenderSystem;
class Log;
enum LogLevel;
void gameStart()
{
    engine.init();
    engine.sceneManager.setSceneLimit(10);
    engine.sceneManager.CreateScene<GameScene>(1);

}
