/*---------------------------------------
 * Sprites.hh
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef SPRITES_HH
#define SPRITES_HH
/*--------------------------------------*/
#include "Spritesheet.hh"
#include "../Image.hh"
/*--------------------------------------*/
#include <string>
#include <map>
/*--------------------------------------*/

/* in most cases, this will be the base class for a specific
   type of sprite (e.g. EnemySprite, NPCSprite).*/
class Sprite
{
protected:
    float x_, y_, width_, height_;
    float x_velocity_, y_velocity_;
    Spritesheet spritesheet_;
public:
    Sprite(Spritesheet spritesheet, float x, float y, float width, float height);
    void update();
    void draw();
    void move(float x, float y);
    void setVelocity(float x_velocity, float y_velocity);
    float getX();
    float getY();
};

/*--------------------------------------*/
#endif /*SPRITES_HH*/
