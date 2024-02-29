#include "Game.h"

Game::Game()
{
    InitWindow(this->m_width, this->m_height, this->m_title.c_str());
    SetTargetFPS(60);

    this->m_resourceManager = &ResourceManager::GetInstance();
    this->m_resourceManager->LoadResources();

    this->m_entities.push_back(std::make_unique<Player>());
}

Game::~Game()
{
    CloseWindow();
}

Game &Game::GetInstance()
{
    static Game instance;
    return instance;
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        this->HandleInput();
        this->Update();
        this->Render();
    }
}

void Game::HandleInput()
{
    for (auto &e : this->m_entities)
        e->HandleInput();
}

void Game::Update()
{
    for (auto &e : this->m_entities)
        e->Update();
}

void Game::Render()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (auto &e : this->m_entities)
        e->Render();

    EndDrawing();
}