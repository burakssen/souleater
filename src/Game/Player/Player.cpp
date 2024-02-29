#include "Player.h"

#include <iostream>

Player::Player()
{
    auto transform = this->AddComponent<TransformComponent>();
    transform->SetPosition({100, 100});
    transform->SetScale({3, 3});

    auto animationComponent = this->AddComponent<AnimationComponent>();

    this->m_resourceManager = &ResourceManager::GetInstance();

    auto resource = this->m_resourceManager->GetResource("player");

    for (auto &animation : resource.m_animations)
    {
        Animation a;
        a.s_texture = animation.s_texture;
        a.s_numFrames = animation.s_numberOfFrames;
        a.s_frameDelay = animation.s_frameDelay;
        a.s_loop = animation.s_loop;

        animationComponent->AddAnimation(animation.s_animationName, a);
    }

    animationComponent->SetAnimation("idle_down");
}

void Player::HandleInput()
{
    auto transform = this->GetComponent<TransformComponent>();
    auto animation = this->GetComponent<AnimationComponent>();

    if (transform == nullptr)
        return;

    Vector2 scale = transform->GetScale();

    if (IsKeyDown(KEY_RIGHT))
    {
        this->m_direction.x = 1;
    }

    if (IsKeyDown(KEY_LEFT))
    {
        this->m_direction.x = -1;
    }

    if (IsKeyDown(KEY_UP))
    {
        this->m_direction.y = -1;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        this->m_direction.y = 1;
    }

    if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_DOWN))
    {
        if (this->m_direction.y > 0)
        {
            animation->SetAnimation("idle_down");
        }
        else if (this->m_direction.y < 0)
        {
            animation->SetAnimation("idle_up");
        }
        else
        {
            animation->SetAnimation("idle_down");
        }

        this->m_direction = {0, 0};
    }
    else
    {
        if (animation)
        {
            Animation *currentAnimation = animation->GetCurrentAnimation();
            bool isPlaying = currentAnimation->s_playing;
            bool isLoop = currentAnimation->s_loop;

            if (this->m_direction.x == 0 && this->m_direction.y == 0 && !isPlaying && !isLoop)
            {
                if (this->m_previousDirection.x > 0)
                {
                    animation->SetAnimation("idle_down");
                }
                else if (this->m_previousDirection.x < 0)
                {
                    animation->SetAnimation("idle_down");
                }
                else if (this->m_previousDirection.y > 0)
                {
                    animation->SetAnimation("idle_up");
                }
                else if (this->m_previousDirection.y < 0)
                {
                    animation->SetAnimation("idle_up");
                }
            }
        }

        // normalize the direction vector
        if (this->m_direction.x != 0 && this->m_direction.y != 0)
        {
            this->m_direction.x /= sqrt(2);
            this->m_direction.y /= sqrt(2);
        }

        transform->SetPosition({transform->GetPosition().x + this->m_direction.x * this->m_speed, transform->GetPosition().y + this->m_direction.y * this->m_speed});
    }

    if (this->m_direction.x != 0 || this->m_direction.y != 0)
    {
        this->m_previousDirection = this->m_direction;
    }

    if (animation == nullptr)
        return;

    Animation *currentAnimation = animation->GetCurrentAnimation();
    bool isPlaying = currentAnimation->s_playing;
    bool isLoop = currentAnimation->s_loop;

    if (IsKeyPressed(KEY_RIGHT) || (!isPlaying && !isLoop && IsKeyDown(KEY_RIGHT)))
    {
        transform->SetScale({abs(scale.x), scale.y});
        animation->SetAnimation("walk_right");
    }

    if (IsKeyPressed(KEY_LEFT) || (!isPlaying && !isLoop && IsKeyDown(KEY_LEFT)))
    {
        transform->SetScale({-abs(scale.x), scale.y});
        animation->SetAnimation("walk_right");
    }

    if (IsKeyPressed(KEY_UP) || (!isPlaying && !isLoop && IsKeyDown(KEY_UP)))
    {
        animation->SetAnimation("walk_up");
    }

    if (IsKeyPressed(KEY_DOWN) || (!isPlaying && !isLoop && IsKeyDown(KEY_DOWN)))
    {
        animation->SetAnimation("walk_down");
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        if (this->m_previousDirection.x > 0)
        {
            animation->SetAnimation("attack_right");
        }
        else if (this->m_previousDirection.x < 0)
        {
            animation->SetAnimation("attack_right");
        }
        else if (this->m_previousDirection.y > 0)
        {
            animation->SetAnimation("attack_down");
        }
        else if (this->m_previousDirection.y < 0)
        {
            animation->SetAnimation("attack_up");
        }
    }
}
