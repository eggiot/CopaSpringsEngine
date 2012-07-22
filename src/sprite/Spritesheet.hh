/*---------------------------------------
 * Spritesheet.hh
 *
 *  Created on: 21 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef SPRITESHEET_HH
#define SPRITESHEET_HH
/*--------------------------------------*/
#include "../Image.hh"
#include <string>
/*--------------------------------------*/

class Spritesheet
{
private:
    // position of first and lasts sprites we want to display
    int first, last;
    // position of current_sprite
    int current_sprite;
    // grid coordinates of the current sprite
    int current_column, current_row;
    // how many sprites horizontally and vertically
    int num_columns, num_rows;

    float subimage_width, subimage_height;

    // width and height of the subtexture
    float tex_width, tex_height;

    Graphics::Image image;
    bool ping_pong;
    bool forwards;
    void goToSprite(int sprite);
public:
    Spritesheet() {}
    Spritesheet(std::string filename, int num_columns, int num_rows, int first, int last, bool ping_pong);
    void update();
    void draw(float x, float y, float width, float height);
};

/*--------------------------------------*/
#endif /*SPRITES_HH*/
