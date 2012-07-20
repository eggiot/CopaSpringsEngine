/*---------------------------------------
 * Image.hh
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef IMAGE_HH
#define IMAGE_HH
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/

namespace Graphics
{
class Image
{
protected:
    GLuint texture;
    int width, height, bpp;
    char* image_data;
public:
    // constructors
    Image() { }
    Image(std::string filename, bool flip_horizontal, bool flip_vertical);
    ~Image();
    // load an image from a filename
    void load(std::string filename, bool flip_horizontal, bool flip_vertical);
    char* getPixels();
    int getWidth();
    int getHeight();
    int getBPP();
    GLuint getTexture();
    void draw(float x, float y, float width, float height);
};
}

/*--------------------------------------*/
#endif /*IMAGE.HH*/
