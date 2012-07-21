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
    int first_horizontal, first_vertical;
    int last_horizontal, last_vertical;
    // how many sprites horizontally and vertically
    int num_horizontal, num_vertical;
    // grid coordinates of the current sprite
    int current_horizontal, current_vertical;
    float subimage_width, subimage_height;
    Graphics::Image image;
public:
    Spritesheet() {}
    Spritesheet(std::string filename, int num_horizontal, int num_vertical, int first, int last);
    void update();
    void draw(float x, float y, float width, float height);
};

/*--------------------------------------*/
#endif /*SPRITES_HH*/
