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
    Camera camera_;
    bool camera_follows_;
    Sprite central_sprite_;
public:
    World();
    void addSprite(Sprite sprite);
    void addCentralSprite(Sprite sprite, float x_offset_, float y_offset);
    void addEmitter(Emitter emitter);
    void setCamera(Camera camera);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*WORLD_H*/
