/*----------------------------------------
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ---------------------------------------*/
#include "sprite/Sprite.h"
#include "particle/Emitter.h"
#include "Engine.h"
#include "World.h"
#include "Camera.h"
/*--------------------------------------*/
#include <iostream>
#include <GL/gl.h>
/*--------------------------------------*/

void testParticleEngineAndLayers()
{
    int window_width = 900; int window_height = 400;
    int framerate = 40;

    Engine engine;
    engine.initWindow(window_width, window_height, "Test");
    engine.initGraphics(4,4);
    engine.setFramerate(framerate);

    // initialise two emitters
    Emitter smoke("test/smoke_emitter.config");

    Emitter rain("test/rain.png", 1, 10, 100, 100, 10000, -window_width, window_width, window_height, window_height,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise two sprites
    Spritesheet man_sheet("test/spritesheet.png", 4, 4, 6, 13, false);
    Sprite man(man_sheet, 5, 0, 1.0, 2.0);
    man.setVelocity(-0.3, 0);

    Spritesheet block_sheet("test/spritesheet-blocks.png", 4, 2, 1, 8, true);
    Sprite blocks(block_sheet, 5, 0, 1, 1);

    Spritesheet chimney_sheet("test/chimney.png", 1, 1, 1, 1, false);
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
    while(quit == false)
    {
        engine.update();
        engine.draw();
    }
}

int main()
{
    testParticleEngineAndLayers();
    return 0;
}
