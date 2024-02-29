#include "AnimationComponent.h"

#include <iostream>

void AnimationComponent::Update()
{
    if (this->m_currentAnimation && this->m_currentAnimation->s_playing)
    {
        this->m_currentAnimation->s_frameTime += GetFrameTime();
        if (this->m_currentAnimation->s_frameTime >= this->m_currentAnimation->s_frameDelay)
        {
            this->m_currentAnimation->s_frameTime = 0;
            this->m_currentAnimation->s_currentFrame++;
            if (this->m_currentAnimation->s_currentFrame >= this->m_currentAnimation->s_numFrames)
            {
                if (this->m_currentAnimation->s_loop)
                {
                    this->m_currentAnimation->s_currentFrame = 0;
                }
                else
                {
                    this->m_currentAnimation->s_currentFrame = this->m_currentAnimation->s_numFrames - 1;
                    this->m_currentAnimation->s_playing = false;
                }
            }

            this->m_currentAnimation->s_rectangle.x = this->m_currentAnimation->s_currentFrame * this->m_currentAnimation->s_rectangle.width;
            this->SetSourceRec(this->m_currentAnimation->s_rectangle);
        }
    }
};

void AnimationComponent::AddAnimation(const std::string &name, const Animation &animation)
{
    this->m_animations[name] = animation;
};

void AnimationComponent::SetAnimation(const std::string &name)
{
    this->m_currentAnimation = &this->m_animations[name];
    this->m_currentAnimation->s_playing = true;
    this->m_currentAnimation->s_currentFrame = 0;
    this->m_currentAnimation->s_frameTime = 0;
    // this->m_currentAnimation->s_frameDelay = 1.0f / this->m_currentAnimation->s_numFrames;
    this->m_currentAnimation->s_rectangle.width = this->m_currentAnimation->s_texture.width / this->m_currentAnimation->s_numFrames;

    this->m_currentAnimation->s_rectangle.height = this->m_currentAnimation->s_texture.height;
    this->m_currentAnimation->s_rectangle.x = 0;
    this->m_currentAnimation->s_rectangle.y = 0;
    this->m_texture = this->m_currentAnimation->s_texture;

    this->SetSourceRec(this->m_currentAnimation->s_rectangle);
};

Animation *AnimationComponent::GetCurrentAnimation() const
{
    return this->m_currentAnimation;
};