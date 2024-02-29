#include "TransformComponent.h"

void TransformComponent::Render()
{
    if (this->IsVisible())
    {
        DrawRectangle(this->m_position.x, this->m_position.y, 50, 50, RED);
    }
}

Vector2 TransformComponent::GetPosition() const
{
    return this->m_position;
}

void TransformComponent::SetPosition(const Vector2 &position)
{
    this->m_position = position;
}

Vector2 TransformComponent::GetScale() const
{
    return this->m_scale;
}

void TransformComponent::SetScale(const Vector2 &scale)
{
    this->m_scale = scale;
}

float TransformComponent::GetRotation() const
{
    return this->m_rotation;
}

void TransformComponent::SetRotation(float rotation)
{
    this->m_rotation = rotation;
}
