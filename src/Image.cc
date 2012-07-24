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
#include "Image.h"
#include "Graphics.h"
/*--------------------------------------*/

Graphics::Image::Image(std::string filename)
{
    this->load(filename);
}

void Graphics::Image::load(std::string filename)
{
    fipImage fip_image_data;

    fip_image_data.load(filename.c_str());

    width_ = fip_image_data.getWidth();
    height_ = fip_image_data.getHeight();
    bpp_ = fip_image_data.getBitsPerPixel();

    // get a pointer to the image data (BGRA)
    image_data_ = (char*)fip_image_data.accessPixels();

    // load texture
    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // if the image has no alpha channel
    if(bpp_==24)
    {
        // generate texture
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
                    width_, height_,
                    0, GL_BGR, GL_UNSIGNED_BYTE, image_data_);
    }

    // if the image has an alpha channel
    else if(bpp_==32)
    {
        // generate the texture
        glTexImage2D(GL_TEXTURE_2D, 0, 4,
                    width_, height_,
                    0, GL_BGRA, GL_UNSIGNED_BYTE, image_data_);
    }

    // some other number of bits per pixel
    else
    {
        texture_ = 0;
    }
}

void Graphics::Image::draw(float x, float y, float width, float height)
{
    Graphics::drawTexturedQuad(texture_, x, y, width, height, 1.0f);
}


char* Graphics::Image::getPixels()
{
    return image_data_;
}

int Graphics::Image::getWidth()
{
    return width_;
}

int Graphics::Image::getHeight()
{
    return height_;
}

int Graphics::Image::getBPP()
{
    return bpp_;
}

GLuint Graphics::Image::getTexture()
{
    return texture_;
}
