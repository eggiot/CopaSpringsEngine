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
/*--------------------------------------*/

#define RUN_TIME 10000
/*
void testParticleEngineAndLayers()
{
    int window_width = 900; int window_height = 400;
    float viewport_width = 4.0; float viewport_height = 4.0;
    int framerate = 40;

    Engine engine;
    engine.initWindow(window_width, window_height, "Test");
    engine.initGraphics(viewport_width, viewport_height);
    engine.setFramerate(framerate);

    // initialise two emitters
    Emitter smoke("media/smoke_emitter.config");

    Emitter rain("media/rain.png", 1, 10, 100, 100, 10000, -1000, 1000, viewport_height, viewport_height,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise two sprites
    Spritesheet man_sheet("media/spritesheet.png", 4, 4, 6, 13, false);
    Sprite man(man_sheet, 5, 0, 2.0, 2.0);
    man.setVelocity(-0.3, 0);

    Spritesheet block_sheet("media/spritesheet-blocks.png", 4, 2, 1, 8, true);
    Sprite blocks(block_sheet, 5, 0, 1, 1);

    Spritesheet chimney_sheet("media/chimney.png", 1, 1, 1, 1, false);
    Sprite chimney(chimney_sheet, 7, 0.0, 1.0, 1.0);

    World world;
    world.addSprite(blocks);
    world.addSprite(chimney);
    world.addEmitter(smoke);

    for (int i = 0; i > -1000; i -= 2)
    {
        Sprite block_post(block_sheet, i, 0, 1, 1);
        world.addSprite(block_post);
    }
    world.addCentralSprite(man, 0, 0);

    engine.setWorld(world);

    bool quit = false;
    while(SDL_GetTicks() < RUN_TIME)
    {
        engine.update();
        engine.draw();
    }
}
*/

void testGameObjects()
{
    int window_width = 900; int window_height = 400;
    float viewport_width = 4.0; float viewport_height = 4.0;
    int framerate = 40;
    Engine engine;
    engine.initWindow(window_width, window_height, "Test");
    engine.initGraphics(viewport_width, viewport_height);
    engine.setFramerate(framerate);
    
    // create GameObject
    GameObject* go = new GameObject("test_game_object");
    
    // set transform
    go->setTransform(1.0, 1.0, 2.0, 2.0, 0.0);
    Spritesheet* gc = new Spritesheet("media/spritesheet.png", 4, 4, 6, 13, false);
    
    // add a render component to the GameObject
    go->setComponent(gc);
    
    World world;
    world.addGameObject(go);
    
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
