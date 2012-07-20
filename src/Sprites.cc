/*---------------------------------------
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Animation.hh"
#include "State.hh"
#include "Sprites.hh"
/*--------------------------------------*/
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
/*--------------------------------------*/

Sprite::Sprite(float x_pos, float y_pos, float w, float h, State idle_state)
{
    // an animated sprite must have a loopable idle animation and it is initialised here.
    addState("idle", idle_state);
    x = x_pos; y = y_pos; width = w; height = h;
    x_velocity = 0.0f; y_velocity = 0.0f;
    current_state = "idle";
}

void Sprite::addState(std::string id, State new_state)
{
    states.insert(std::pair<std::string, State>(id, new_state));
}

void Sprite::draw()
{
    // call the draw function of the current state animation
    states[current_state].getAnimation().draw(x, y, width, height);
}

void Sprite::setState(std::string new_state)
{
    /* reload the current state so it will play from the start when it is next called.
       (see the comments for the Animation::reload function)*/
    states[current_state].getAnimation().reload();

    // change state
    current_state = new_state;
}

void Sprite::move(float new_x, float new_y)
{
    // change the x and y coordinates
    x = new_x;
    y = new_y;
}

void Sprite::setXVelocity(float new_velocity)
{
    x_velocity = new_velocity;
}

void Sprite::setYVelocity(float new_velocity)
{
    y_velocity = new_velocity;
}

float Sprite::getX()
{
    return x;
}

float Sprite::getY()
{
    return y;
}

void Sprite::update()
{
    x += x_velocity;
    y += y_velocity;
}
