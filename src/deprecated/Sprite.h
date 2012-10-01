/*---------------------------------------
 * Sprites.h
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef SPRITES_H
#define SPRITES_H
/*--------------------------------------*/
#include "../components/Spritesheet.h"
#include "../media/Image.h"
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
    // default constructor
    Sprite () {}
    Sprite(Spritesheet spritesheet, float x, float y, float width, float height);
    void update();
    void draw();
    void move(float x, float y);
    void setVelocity(float x_velocity, float y_velocity);

    // query methods
    float getX();
    float getY();
    float getWidth();
    float getHeight();
};

/*--------------------------------------*/
#endif /*SPRITES_H*/
