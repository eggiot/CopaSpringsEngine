/*---------------------------------------
 * Image.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include <FreeImagePlus.h>
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/
#include "Image.hh"
#include "Graphics.hh"
/*--------------------------------------*/

Graphics::Image::Image(std::string filename, bool flip_horizontal, bool flip_vertical)
{
    this->load(filename, flip_horizontal, flip_vertical);
}

Graphics::Image::~Image()
{
    delete [] image_data;
    image_data = NULL;
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

    // load texture
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // if the image has no alpha channel
    if(this->bpp==24)
    {
        // generate texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
                    this->width, this->height,
                    0, GL_BGR, GL_UNSIGNED_BYTE, this->image_data);
    }

    // if the image has an alpha channel
    else if(this->bpp==32)
    {
        // generate the texture
        glTexImage2D(GL_TEXTURE_2D, 0, 4,
                    this->width, this->width,
                    0, GL_BGRA, GL_UNSIGNED_BYTE, this->image_data);
    }

    // some other number of bits per pixel
    else
    {
        texture = 0;
    }
}

void Graphics::Image::draw(float x, float y, float width, float height)
{
    Graphics::Utils::drawTexturedQuad(texture, x, y, width, height);
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

GLuint Graphics::Image::getTexture()
{
    return texture;
}
