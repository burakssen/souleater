#pragma once

#include "Entity/Entity.h"

#include <raylib.h>

class Entity;

class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    virtual void Update(){};
    virtual void Render(){};
    virtual void HandleInput(){};

    Entity *GetEntity() const;
    void SetEntity(Entity *entity);

    bool IsVisible() const;
    void SetVisible(bool visible);

protected:
    Entity *m_entity = nullptr;
    bool m_visible = false;
};