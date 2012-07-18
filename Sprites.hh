/*
 * Sprites.hh
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 */
#ifndef SPRITES_HH
#define SPRITES_HH

// include engine headers
#include "Animation.hh"
#include "State.hh"

// include standard library headers
#include <string>
#include <map>

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

#endif /*SPRITES_HH*/
