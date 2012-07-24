/*---------------------------------------
 * Engine.h
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef ENGINE_H
#define ENGINE_H
/*--------------------------------------*/
#include "World.h"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Engine
{
private:
    World *world_;
public:
    Engine(World& world);
    void setWorld(World& world);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*ENGINE_H*/
