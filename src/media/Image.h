/*---------------------------------------
 * Image.h
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef IMAGE_H
#define IMAGE_H
/*--------------------------------------*/
#include <GL/gl.h>
#include <SDL/SDL_image.h>
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/

namespace Graphics
{
class Image
{
protected:
    GLuint texture_;
    int width_, height_, bpp_;
    char* image_data_;
public:
    // constructors
    Image() { }
    Image(std::string filename);
    //~Image();
    // load an image from a filename
    void load(std::string filename);
    char* getPixels();
    int getWidth();
    int getHeight();
    int getBPP();
    GLuint getTexture();
    void draw(float x, float y, float width, float height);
};
}

/*--------------------------------------*/
#endif /*IMAGE.h*/
