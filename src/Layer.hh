/*---------------------------------------
 * Layer.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef LAYER_HH
#define LAYER_HH
/*--------------------------------------*/
#include "sprite/Sprite.hh"
#include "particle/Emitter.hh"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Layer
{
private:
    std::vector<Sprite> sprites_;
    std::vector<Emitter> emitters_;
public:
    void addSprite(Sprite sprite);
    void addEmitter(Emitter emitter);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*LAYER_HH*/
