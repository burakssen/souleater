#include "Entity.h"

void Entity::Update()
{
    for (auto &c : this->m_components)
        c->Update();
}

void Entity::Render()
{
    for (auto &c : this->m_components)
        c->Render();
};
void Entity::HandleInput()
{
    for (auto &c : this->m_components)
        c->HandleInput();
};