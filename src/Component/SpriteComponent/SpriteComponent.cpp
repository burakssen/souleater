#include "SpriteComponent.h"

#include <iostream>

void SpriteComponent::Render()
{
    auto entity = this->GetEntity();
    if (!entity)
        return;

    auto transform = entity->GetComponent<TransformComponent>();
    if (!transform)
        return;

    if (this->m_texture.id != 0)
    {
        int signX = transform->GetScale().x > 0 ? 1 : -1;
        int signY = transform->GetScale().y > 0 ? 1 : -1;

        Rectangle sourceRec = {this->m_rectangle.x, this->m_rectangle.y, this->m_rectangle.width * signX, this->m_rectangle.height * signY};

        Rectangle destRec = {transform->GetPosition().x, transform->GetPosition().y, this->m_rectangle.width * abs(transform->GetScale().x), this->m_rectangle.height * abs(transform->GetScale().y)};
        Vector2 origin = {0, 0};
        float rotation = 0;

        DrawTexturePro(this->m_texture, sourceRec, destRec, origin, rotation, WHITE);
    }
}

void SpriteComponent::SetTexture(const Texture2D &texture)
{
    this->m_texture = texture;
}

void SpriteComponent::SetSourceRec(const Rectangle &rectangle)
{
    this->m_rectangle = rectangle;
}