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
#include "Particles.hh"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Layer
{
private:
    std::vector<Sprite> sprites;
    std::vector<Emitter> emitters;
public:
    void addSprite(Sprite sprite);
    void addEmitter(Emitter emitter);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*LAYER_HH*/
