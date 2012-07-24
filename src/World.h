/*---------------------------------------
 * Layer.h
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef WORLD_H
#define WORLD_H
/*--------------------------------------*/
#include "sprite/Sprite.h"
#include "particle/Emitter.h"
#include "camera/Camera.h"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class World
{
private:
    std::vector<Sprite> sprites_;
    std::vector<Emitter> emitters_;
    Camera& camera_;
public:
    World(Camera& camera) : camera_(camera)
    { }
    void addSprite(Sprite sprite);
    void addEmitter(Emitter emitter);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*WORLD_H*/
