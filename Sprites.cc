/*
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 */

// include engine headers
#include "Animation.hh"
#include "State.hh"

// include standard library headers
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>

namespace Objects
{
class Sprite
{
protected:
    float x, y, width, height;// TODO (eliot#1#): State
    float x_velocity, y_velocity;// TODO (eliot#1#): State
    // a string-animation map of states - (e.g. "walk", walking_animation)
    std::map<std::string, Objects::State> states;
    std::string current_state;
public:
    Sprite(float x_pos, float y_pos, float w, float h, Objects::State idle_state);
    //bool load(std::string filename);
    void addState(std::string id, Objects::State new_state);
    void draw();
    void setState(std::string new_state);
    void move(float x, float y);// TODO (eliot#1#): State
    void setXVelocity(float new_velocity);// TODO (eliot#1#): State
    void setYVelocity(float new_velocity);// TODO (eliot#1#): State
    float getX();// TODO (eliot#1#): State
    float getY();// TODO (eliot#1#): State
    void update();
};
}

Objects::Sprite::Sprite(float x_pos, float y_pos, float w, float h, Objects::State idle_state)
{
    // an animated sprite must have a loopable idle animation and it is initialised here.
    addState("idle", idle_state);
    x = x_pos; y = y_pos; width = w; height = h;
    x_velocity = 0.0f; y_velocity = 0.0f;
    current_state = "idle";
}

void Objects::Sprite::addState(std::string id, Objects::State new_state)
{
    states.insert(std::pair<std::string, Objects::State>(id, new_state));
}

void Objects::Sprite::draw()
{
    // call the draw function of the current state animation
    states[current_state].getAnimation().draw(x, y, width, height);
}

void Objects::Sprite::setState(std::string new_state)
{
    /* reload the current state so it will play from the start when it is next called.
       (see the comments for the Animation::reload function)*/
    states[current_state].getAnimation().reload();

    // change state
    current_state = new_state;
}

void Objects::Sprite::move(float new_x, float new_y)
{
    // change the x and y coordinates
    x = new_x;
    y = new_y;
}

void Objects::Sprite::setXVelocity(float new_velocity)
{
    x_velocity = new_velocity;
}

void Objects::Sprite::setYVelocity(float new_velocity)
{
    y_velocity = new_velocity;
}

float Objects::Sprite::getX()
{
    return x;
}

float Objects::Sprite::getY()
{
    return y;
}

void Objects::Sprite::update()
{
    x += x_velocity;
    y += y_velocity;
}
