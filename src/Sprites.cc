/*---------------------------------------
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Animation.hh"
#include "State.hh"
#include "Sprites.hh"
#include "Graphics.hh"
/*--------------------------------------*/
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
/*--------------------------------------*/
/*----------------------- SPRITE ---------------------------*/
Sprite::Sprite(Spritesheet spritesheet)
{
    this->spritesheet = spritesheet;
}

void Sprite::update()
{
    x += x_velocity;
    y += y_velocity;
}

void Sprite::draw()
{}

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

/*----------------------- SPRITESHEET ---------------------------*/

Spritesheet::Spritesheet(std::string filename, int num_horizontal, int num_vertical)
{
    image.load(filename, false, false);
    this->num_horizontal = num_horizontal;
    this->num_vertical = num_vertical;
    this->current_horizontal = 0;
    this->current_vertical = 0;

    this->subimage_width = (float)image.getWidth() / (float)num_horizontal;
    this->subimage_height = (float)image.getHeight() / (float)num_vertical;
}


/* TODO: only move through a subset of the sprites in the spritesheet. At the moment
we're going through all of them. */
void Spritesheet::update()
{
    // if we're at the end of a horizontal line
    if(current_horizontal == num_horizontal)
    {
        // start at the beginning of the horizontal line
        current_horizontal = 1;

        // if we're not at the end of the sheet
        if(current_vertical < num_vertical)
        {
            // move to the next horizontal line
            ++current_vertical;
        }
        // if we are at the end of the sheet
        else
        {
            // move to the first horizontal line
            current_vertical = 1;
        }
    }

    // if we're not at the end of a horizontal line
    else
    {
        // move to the next image in the line
        ++current_horizontal;
    }
}

void Spritesheet::draw(float x, float y, float width, float height)
{
    float tex_width = 1.0f / subimage_width;
    float tex_height = 1.0f / subimage_height;
    float tex_x = tex_width * current_horizontal;
    float tex_y = tex_height * current_vertical;

    Graphics::drawSubTexturedQuad(image.getTexture(), x, y, width, height,
                                  tex_x, tex_y, tex_width, tex_height, 1.0f);

}
