/*---------------------------------------
 * Layer.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef LAYER_HH
#define LAYER_HH
/*--------------------------------------*/
#include "Sprites.hh"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Layer
{
private:
    std::vector<Sprite> sprites;
public:
    void addSprite(Sprite sprite);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*LAYER_HH*/
