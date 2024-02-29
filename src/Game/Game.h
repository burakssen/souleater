#pragma once

#include <string>
#include <memory>
#include <vector>

#include <raylib.h>

#include "Entity/Entity.h"
#include "Player/Player.h"

#include "ResourceManager/ResourceManager.h"

class Game
{
    Game();

public:
    ~Game();
    static Game &GetInstance();

    void Run();

private:
    void HandleInput();
    void Update();
    void Render();

private:
    float m_width = 1280;
    float m_height = 720;

    std::string m_title = "Super Mario Clone";

    std::vector<std::unique_ptr<Entity>> m_entities;

    ResourceManager *m_resourceManager = nullptr;
};