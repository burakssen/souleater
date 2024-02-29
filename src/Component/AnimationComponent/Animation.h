#pragma once

#include <raylib.h>

typedef struct Animation
{
    int s_numFrames;
    float s_frameDelay;
    bool s_loop;
    bool s_playing;
    float s_frameTime;
    int s_currentFrame;
    Rectangle s_rectangle;
    Texture2D s_texture;
} Animation;