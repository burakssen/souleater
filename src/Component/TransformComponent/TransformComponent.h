#pragma once

#include <raylib.h>

#include "Component/Component.h"

class TransformComponent : public Component
{
public:
    TransformComponent() = default;
    virtual ~TransformComponent() = default;

    void Render() override;

    Vector2 GetPosition() const;
    void SetPosition(const Vector2 &position);

    Vector2 GetScale() const;
    void SetScale(const Vector2 &scale);

    float GetRotation() const;
    void SetRotation(float rotation);

private:
    Vector2 m_position = {0, 0};
    Vector2 m_scale = {1, 1};
    float m_rotation = 0;
};