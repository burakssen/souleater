#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include <raylib.h>

typedef struct ResourceValue
{
    float float_value;
    int int_value;
    bool bool_value;
    std::string string_value;
} ResourceValue;

typedef struct AnimationResource
{
    std::string s_animationName;
    int s_numberOfFrames;
    float s_frameDelay;
    bool s_loop;
    Texture2D s_texture;
} AnimationResource;

typedef struct Resource
{
    std::string s_entityName;
    std::map<std::string, ResourceValue> m_values;
    std::vector<AnimationResource> m_animations;
} Resource;
