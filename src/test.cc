/*----------------------------------------
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ---------------------------------------*/
#include "components/Emitter.h"
#include "components/Camera.h"
#include "core/Engine.h"
#include "core/World.h"
#include "core/GameObject.h"
#include "media/Audio.h"
#include "components/Spritesheet.h"
/*--------------------------------------*/
#include <iostream>
#include <GL/gl.h>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
/*--------------------------------------*/

#define RUN_TIME 10000

class ManObject : public GameObject
{
public:
    ManObject(float x, float y, float width, float height) : GameObject("man_object")
    {
        setTransform(x, y, width, height, 0.0);
        addComponent(new Spritesheet("media/spritesheet.png", 4, 4, 6, 13, false));
    }
};

void lotsOfMen(World& world)
{
    for(float posx = 0.0; posx < 55; ++posx)
    {
        for(float posy = 0.0; posy < 55; ++posy)
        {
            world.addGameObject(boost::make_shared<ManObject>(posx/8.0, posy/8.0, 2.0/8.0, 2.0/8.0));
        }
    }
}

void testGameObjects()
{
    // initialise some variables
    int window_width = 900; int window_height = 400;
    float viewport_width = 7.5; float viewport_height = 7.5;
    int framerate = 40;

    // create engine
    Engine engine;
    engine.initWindow(window_width, window_height, "Game Object Test");
    engine.initGraphics(viewport_width, viewport_height);
    engine.setFramerate(framerate);
    
    World world;
    //lotsOfMen(world);
    world.addGameObject(boost::make_shared<ManObject>(2.0,2.0,2.0,2.0));
    
    //world.addGameObject(new ManObject(2.0, 2.0, 2.0, 2.0));
    
    engine.setWorld(world);
    
    while(SDL_GetTicks() < RUN_TIME)
    {
        engine.update();
        engine.run();
    }
    
}

int main()
{
    //testParticleEngineAndLayers();
    testGameObjects();
    return 0;
}
