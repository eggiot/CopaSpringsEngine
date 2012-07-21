/*---------------------------------------
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Sprite.hh"
#include "Spritesheet.hh"
#include "../Graphics.hh"
/*--------------------------------------*/
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
/*--------------------------------------*/
Sprite::Sprite(Spritesheet spritesheet, float x, float y, float width, float height)
{
    this->spritesheet = spritesheet;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->x_velocity = 0.0f;
    this->y_velocity = 0.0f;
}

void Sprite::update()
{
    x += x_velocity;
    y += y_velocity;
    spritesheet.update();
}

void Sprite::draw()
{
    spritesheet.draw(x, y, width, height);
}

void Sprite::move(float x, float y)
{
    // change the x and y coordinates
    this->x = x;
    this->y = y;
}

void Sprite::setVelocity(float x_velocity, float y_velocity)
{
    this->x_velocity = x_velocity;
    this->y_velocity = y_velocity;
}

float Sprite::getX()
{
    return x;
}

float Sprite::getY()
{
    return y;
}
