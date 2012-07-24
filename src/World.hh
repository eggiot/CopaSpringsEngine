/*---------------------------------------
 * Layer.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef WORLD_HH
#define WORLD_HH
/*--------------------------------------*/
#include "sprite/Sprite.hh"
#include "particle/Emitter.hh"
#include "Camera.hh"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class World
{
private:
    std::vector<Sprite> sprites_;
    std::vector<Emitter> emitters_;
    Camera *camera_;
public:
    World(Camera& camera);
    void addSprite(Sprite sprite);
    void addEmitter(Emitter emitter);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*WORLD_HH*/
