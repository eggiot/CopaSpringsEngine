/*---------------------------------------
 * Spritesheet.h
 *
 *  Created on: 21 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef SPRITESHEET_H
#define SPRITESHEET_H
/*--------------------------------------*/
#include "../media/Image.h"
#include "../graphics/Graphics.h"
#include "../core/GameObject.h"
/*--------------------------------------*/
#include <string>
#include <vector>
/*--------------------------------------*/

/*
The Spritesheet is an image of a grid of sprites. Each time the
spritesheet is updated it moves to the next sprite in the range
[first, last]. This is hardware accelerated and very efficient.

If the spritesheet is set to ping pong it moves
forwards through the range and then backwards; if not, it only
moves forwards, jumping back to the beginning when it reaches the
last sprite. */
class Spritesheet : public Component
{
    public:
    /*Loads an image from filename and sets a number of parameters*/
    Spritesheet(std::string filename, int num_columns, int num_rows, int first, int last, bool ping_pong) : Component("render_component")
    {        
        // initialise some member variables
        image_.load(filename);
        num_columns_ = num_columns;
        num_rows_ = num_rows;
        ping_pong_ = ping_pong;
        first_ = first;
        last_ = last;
        forwards_ = true;

        // calculate how much of the image each sprite occupies
        float subimage_width = (float)image_.getWidth() / (float)num_columns_;
        float subimage_height = (float)image_.getHeight() / (float)num_rows_;

        // calculate how much of the texture each sprite occupies
        tex_width_ = subimage_width / image_.getWidth();
        tex_height_ = subimage_height / image_.getHeight();

        // finally, move to the first sprite
        goToSprite(first_);
    }

    // updates the location of the next sprite to display from the spritesheet
    void update();

    // draws the current sprite
    void run();
private:
    // the range of sprites we want to display
    int first_, last_;

    // position of the current sprite
    int current_sprite_;

    // grid coordinates of the current sprite
    int current_column_, current_row_;

    // the total size of the spritesheet grid
    int num_columns_, num_rows_;

    // the proportional size of each sprite in the OpenGL texture
    float tex_width_, tex_height_;

    // the spritesheet image
    Graphics::Image image_;

    // is the spritesheet set to ping pong?
    bool ping_pong_;

    // is the spritesheet currently moving forwards or backwards through the range?
    bool forwards_;

    // Move to a sprite within the spritesheet
    void goToSprite(int sprite);
};

/*--------------------------------------*/
#endif /*SPRITES_H*/
