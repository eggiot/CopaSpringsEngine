#include "Spritesheet.h"
#include "../Graphics.h"
/*--------------------------------------*/
#include <string>
#include <iostream>
#include <vector>
/*--------------------------------------*/

Spritesheet::Spritesheet(std::string filename, int num_columns, int num_rows, int first, int last, bool ping_pong)
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

void Spritesheet::goToSprite(int sprite)
{
    // go through all the rows
    for(current_row_=1; current_row_ <= num_rows_; ++current_row_)
    {
        // if sprite is in this row
        if(current_row_*num_columns_ >= sprite)
        {
            // set the column in which the sprite resides
            current_column_ = num_columns_ - (current_row_ * num_columns_ - sprite);
            // current_sprite has changed
            current_sprite_ = sprite;
            break;
        }
    }
}


void Spritesheet::update()
{
    // an update is unnecessary if we're only displaying one frame
    if(first_ !=last_)
    {
        // if we're going forwards
        if(forwards_)
        {
            // if we're at the last sprite
            if(current_sprite_ == last_)
            {
                // if we're pingponging
                if(ping_pong_)
                {
                    // go backwards
                    forwards_ = false;
                    // move to the last sprite
                    goToSprite(current_sprite_ - 1);
                }
                // if we're not pingponging
                else
                {
                    // go back to the first sprite
                    goToSprite(first_);
                }
            }

            // if we're not at the last sprite
            else
            {
                // go to the next sprite
                goToSprite(current_sprite_ + 1);
            }
        }

        // if we're going backwards
        else
        {
            // if we're at the first sprite
            if(current_sprite_ == first_)
            {
                // start going forwards
                forwards_ = true;
                // move to the next sprite
                goToSprite(current_sprite_ + 1);
            }

            // if we're not at the first sprite
            else
            {
                // go to the next sprite
                goToSprite(current_sprite_ - 1);
            }
        }
    }
}

// get texcoord arrays
Graphics::TexCoord Spritesheet::getTexCoords()
{
    Graphics::TexCoord tex_coords;

    // set which part of the texture we're going to display
    float tex_x = tex_width_ * (float)(current_column_ - 1);
    float tex_y = 1.0f - tex_height_ * (float)(current_row_ - 1) - tex_height_;

    tex_coords.x = tex_x;
    tex_coords.y = tex_y;
    tex_coords.height = tex_height_;
    tex_coords.width = tex_width_;
    return tex_coords;
}


// immediate mode draw
void Spritesheet::draw(float x, float y, float width, float height)
{
    // set which part of the texture we're going to display
    float tex_x = tex_width_ * (float)(current_column_ - 1);
    float tex_y = 1.0f - tex_height_ * (float)(current_row_ - 1) - tex_height_;

    // draw the sprite
    Graphics::drawSubTexQuad(image_.getTexture(), x, y, width, height,
                                  tex_x, tex_y, tex_width_, tex_height_);

}

