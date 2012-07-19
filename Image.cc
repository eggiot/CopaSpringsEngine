/***********************************
 * Image.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ***********************************/
#include <FreeImagePlus.h>
/***********************************/
#include <string>
/***********************************/
#include "Image.hh"
/***********************************/

Graphics::Image::Image(std::string filename, bool flip_horizontal, bool flip_vertical)
{
    this->load(filename, flip_horizontal, flip_vertical);
}

void Graphics::Image::load(std::string filename, bool flip_horizontal, bool flip_vertical)
{
    fipImage fip_image_data;

    fip_image_data.load(filename.c_str());

    width = fip_image_data.getWidth();
    height = fip_image_data.getHeight();
    bpp = fip_image_data.getBitsPerPixel();

    if(flip_horizontal)
        fip_image_data.flipHorizontal();

    if(flip_vertical)
        fip_image_data.flipVertical();

    // get a pointer to the image data (BGRA)
    image_data = (char*)fip_image_data.accessPixels();
}


char* Graphics::Image::getPixels()
{
    return image_data;
}

int Graphics::Image::getWidth()
{
    return width;
}

int Graphics::Image::getHeight()
{
    return height;
}

int Graphics::Image::getBPP()
{
    return bpp;
}
