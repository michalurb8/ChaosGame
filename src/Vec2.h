#pragma once

struct Vec2
{
    float xPos, yPos;
    Vec2(float xArg = 0, float yArg = 0)
    {
        xPos = xArg;
        yPos = yArg;
    }
    void Move(const Vec2& arg)
    {
        this->xPos = (this->xPos + arg.xPos)/2;
        this->yPos = (this->yPos + arg.yPos)/2;
    }
};