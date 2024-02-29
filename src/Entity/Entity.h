#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "Component/Component.h"

class Component;

class Entity
{
public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void Update();
    virtual void Render();
    virtual void HandleInput();

    template <typename T>
    T *AddComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        std::shared_ptr<T> newComponent = std::make_shared<T>();
        newComponent->SetEntity(this);
        this->m_components.push_back(newComponent);
        return newComponent.get();
    }

    template <typename T>
    T *GetComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        for (auto &c : this->m_components)
        {
            T *result = dynamic_cast<T *>(c.get());
            if (result != nullptr)
            {
                return result;
            }
        }

        return nullptr;
    }

    template <typename T>
    void RemoveComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        for (auto it = this->m_components.begin(); it != this->m_components.end();)
        {
            T *result = dynamic_cast<T *>(it->get());
            if (result != nullptr)
            {
                it = this->m_components.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    template <typename T>
    bool HasComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        for (auto &c : this->m_components)
        {
            T *result = dynamic_cast<T *>(c.get());
            if (result != nullptr)
            {
                return true;
            }
        }

        return false;
    }

private:
    std::vector<std::shared_ptr<Component>> m_components;
};