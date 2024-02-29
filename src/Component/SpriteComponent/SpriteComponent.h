#pragma once

#include "Component/Component.h"
#include "Component/TransformComponent/TransformComponent.h"

#include <raylib.h>

class SpriteComponent : public Component
{
public:
    SpriteComponent() = default;
    virtual ~SpriteComponent() = default;

    void Render() override;

    void SetTexture(const Texture2D &texture);
    void SetSourceRec(const Rectangle &rectangle);

protected:
    Texture2D m_texture = {0};
    Rectangle m_rectangle = {0, 0, 0, 0};
};