/*---------------------------------------
 * Image.hh
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef IMAGE_HH
#define IMAGE_HH
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/

namespace Graphics
{
class Image
{
protected:
    int width, height, bpp;
    char* image_data;
public:
    // constructors
    Image() { }
    Image(std::string filename, bool flip_horizontal, bool flip_vertical);

    // load an image from a filename
    void load(std::string filename, bool flip_horizontal, bool flip_vertical);
    char* getPixels();
    int getWidth();
    int getHeight();
    int getBPP();
};
}

/*--------------------------------------*/
#endif /*IMAGE.HH*/
