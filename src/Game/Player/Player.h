#pragma once

#include <raylib.h>

#include "Entity/Entity.h"

#include "Component/TransformComponent/TransformComponent.h"
#include "Component/AnimationComponent/AnimationComponent.h"

#include "ResourceManager/ResourceManager.h"

class Player : public Entity
{
public:
    Player();
    virtual ~Player() = default;

    void HandleInput() override;

private:
    float m_speed = 300.0f;
    Vector2 m_direction = {0, 0};
    Vector2 m_previousDirection = {0, 0};

    ResourceManager *m_resourceManager = nullptr;
};
