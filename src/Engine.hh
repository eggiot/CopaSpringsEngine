/*---------------------------------------
 * Engine.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef ENGINE_HH
#define ENGINE_HH
/*--------------------------------------*/
#include "World.hh"
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
#endif /*ENGINE_HH*/
