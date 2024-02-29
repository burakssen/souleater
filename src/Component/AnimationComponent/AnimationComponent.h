#pragma once

#include <map>
#include <string>

#include "Component/SpriteComponent/SpriteComponent.h"

#include "Animation.h"

class AnimationComponent : public SpriteComponent
{
public:
    AnimationComponent() = default;
    virtual ~AnimationComponent() = default;

    void Update() override;

    void AddAnimation(const std::string &name, const Animation &animation);
    void SetAnimation(const std::string &name);

    Animation *GetCurrentAnimation() const;

private:
    std::map<std::string, Animation> m_animations;
    Animation *m_currentAnimation = nullptr;
};