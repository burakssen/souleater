#include "Component.h"

Entity *Component::GetEntity() const
{
    return this->m_entity;
}

void Component::SetEntity(Entity *entity)
{
    this->m_entity = entity;
}

bool Component::IsVisible() const
{
    return this->m_visible;
}

void Component::SetVisible(bool visible)
{
    this->m_visible = visible;
}