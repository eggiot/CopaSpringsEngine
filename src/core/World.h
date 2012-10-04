/*---------------------------------------
 * Layer.h
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef WORLD_H
#define WORLD_H
/*--------------------------------------*/
#include "GameObject.h"
#include "../components/Emitter.h"
#include "../components/Camera.h"
/*--------------------------------------*/
#include <vector>
#include <boost/shared_ptr.hpp>
/*--------------------------------------*/

class World
{
public:
    typedef std::vector < boost::shared_ptr<GameObject> > govec_t;
    World() {}
    void addGameObject(GameObject* game_object);
    void addEmitter(Emitter emitter);
    void update();
    void run();
    int i;
private:
    govec_t game_objects_;
    std::vector<Emitter> emitters_;
};

/*--------------------------------------*/
#endif /*WORLD_H*/
