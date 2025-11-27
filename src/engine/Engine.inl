#pragma once
#include "Engine.hpp"
#include "../Scene/Scene.hpp"

template<typename T>
T& Engine::SceneManager::CreateScene(unsigned int ID)
{
    if(ID >= Engine::vectorSceneManager.size()) {
        Engine::vectorSceneManager.resize(ID + 1, nullptr);
    }
    if(Engine::vectorSceneManager[ID] != nullptr)
    {
        delete Engine::vectorSceneManager[ID];
        Engine::vectorSceneManager[ID] = nullptr;
    }
    
    T* scenePtr = new T();
    Engine::vectorSceneManager[ID] = scenePtr;
    sceneCurrent = ID;
    scenePtr->OnLoad();
    return *scenePtr;
}
