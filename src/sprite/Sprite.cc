/*---------------------------------------
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Sprite.h"
#include "Spritesheet.h"
#include "../Graphics.h"
/*--------------------------------------*/

Sprite::Sprite(Spritesheet spritesheet, float x, float y, float width, float height)
{
    spritesheet_ = spritesheet;
    x_           = x;
    y_           = y;
    width_       = width;
    height_      = height;
    x_velocity_  = 0.0f;
    y_velocity_  = 0.0f;
}

void Sprite::update()
{
    spritesheet_.update();
    x_ += x_velocity_;
    y_ += y_velocity_;
}

void Sprite::draw()
{
    spritesheet_.draw(x_, y_, width_, height_);
}

void Sprite::move(float x, float y)
{
    // change the x and y coordinates
    x_ += x;
    y_ += y;
}

void Sprite::setVelocity(float x_velocity, float y_velocity)
{
    x_velocity_ = x_velocity;
    y_velocity_ = y_velocity;
}

float Sprite::getX()
{
    return x_;
}

float Sprite::getY()
{
    return y_;
}

float Sprite::getWidth()
{
    return width_;
}

float Sprite::getHeight()
{
    return height_;
}
