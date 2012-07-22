#include "Spritesheet.hh"
#include "../Graphics.hh"
/*--------------------------------------*/
#include <string>
#include <iostream>
/*--------------------------------------*/
//horizontal = columns, vertical=rows
Spritesheet::Spritesheet(std::string filename, int num_columns, int num_rows, int first, int last, bool ping_pong)
{
    // initialise some member variables
    image.load(filename, false, false);
    this->num_columns = num_columns;
    this->num_rows = num_rows;
    this->ping_pong = ping_pong;
    this->first = first;
    this->last = last;
    forwards = true;
    current_sprite = first;

    goToSprite(current_sprite);

    subimage_width = (float)image.getWidth() / (float)num_columns;
    subimage_height = (float)image.getHeight() / (float)num_rows;
}

// TODO: Make this faster - if necessary
void Spritesheet::goToSprite(int sprite)
{
    for(current_row=1; current_row <= num_rows; ++current_row)
    {
        if(current_row*num_columns >= sprite)
        {
            current_column = num_columns - (current_row * num_columns - sprite);
            current_sprite = sprite;
            break;
        }
    }
}


void Spritesheet::update()
{
    // an update is unnecessary if we're only displaying one frame
    if(first !=last)
    {
        // if we're going forwards
        if(forwards)
        {
            // if we're at the last sprite
            if(current_sprite == last && last != first)
            {
                // if we're pingponging
                if(ping_pong)
                {
                    // go backwards
                    forwards = false;
                    // move to the last sprite
                    goToSprite(current_sprite-1);
                }
                // if we're not pingponging
                else
                {
                    // go back to the first sprite
                    goToSprite(first);
                }
            }

            // if we're not at the last sprite
            else
            {
                // go to the next sprite
                goToSprite(current_sprite+1);
            }
        }

        // if we're going backwards
        else
        {
            // if we're at the first sprite
            if(current_sprite == first)
            {
                // start going forwards
                forwards = true;
                // move to the next sprite
                goToSprite(current_sprite+1);
            }

            // if we're not at the first sprite
            else
            {
                // go to the next sprite
                goToSprite(current_sprite-1);
            }
        }
    }
}

void Spritesheet::draw(float x, float y, float width, float height)
{
    // calculate which subset of the texture to display
    float tex_width = subimage_width / image.getWidth();
    float tex_height = subimage_height / image.getHeight();
    float tex_x = tex_width * (float)(current_column-1);
    float tex_y = 1.0f - tex_height * (float)(current_row-1) - tex_height;

    // draw and texture the quad
    Graphics::drawSubTexturedQuad(image.getTexture(), x, y, width, height,
                                  tex_x, tex_y, tex_width, tex_height, 1.0f);

}

