/*---------------------------------------
 * Sprites.cc
 *
 *  Created on: 18 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Sprites.hh"
#include "Graphics.hh"
/*--------------------------------------*/
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
/*--------------------------------------*/
/*----------------------- SPRITE ---------------------------*/
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

/*----------------------- SPRITESHEET ---------------------------*/

Spritesheet::Spritesheet(std::string filename, int num_horizontal, int num_vertical, int first, int last)
{
    image.load(filename, false, false);
    this->num_horizontal = num_horizontal-1;
    this->num_vertical = num_vertical-1;
    int count = 1;

    for(int row=0; row!=num_vertical; ++row)
    {
        for(int column=0; column!=num_horizontal; ++column)
        {
            if(count == first)
            {
                first_horizontal = column;
                first_vertical = row;
            }
            if(count == last)
            {
                last_horizontal = column;
                last_vertical = row;
            }
            ++count;
        }
    }

    for(int count=0; count <= last-1; ++count)
    {

    }

    this->current_horizontal = 0;
    this->current_vertical = 0;

    this->subimage_width = (float)image.getWidth() / (float)num_horizontal;
    this->subimage_height = (float)image.getHeight() / (float)num_vertical;

    std::cout << first_vertical << ", " << first_horizontal << std::endl;
    std::cout << last_vertical << ", " << last_horizontal << std::endl;
}


void Spritesheet::update()
{
    // if we've already updated to the last sprite
    if(current_horizontal == last_horizontal && current_vertical==last_vertical)
    {
        // go back to the first sprite
        current_horizontal = first_horizontal;
        current_vertical = first_vertical;
    }

    // if we're at the end of a horizontal line
    else if(current_horizontal == num_horizontal)
    {
        // start at the beginning of the horizontal line
        current_horizontal = 0;

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
            current_vertical = 0;
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
    // calculate which subset of the texture to display
    float tex_width = subimage_width / image.getWidth();
    float tex_height = subimage_height / image.getHeight();
    float tex_x = tex_width * (float)current_horizontal;
    float tex_y = 1.0f - tex_height * (float)current_vertical - tex_height;

    // draw and texture the quad
    Graphics::drawSubTexturedQuad(image.getTexture(), x, y, width, height,
                                  tex_x, tex_y, tex_width, tex_height, 1.0f);

}
