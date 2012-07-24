/*----------------------------------------
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ---------------------------------------*/
#include "Window.hh"
#include "Graphics.hh"
#include "Image.hh"
#include "sprite/Sprite.hh"
#include "particle/Emitter.hh"
#include "Engine.hh"
#include "World.hh"
/*--------------------------------------*/
#include <SDL/SDL.h>
/*--------------------------------------*/
#include <queue>
#include <iostream>
#include <math.h>
#include <string>
/*--------------------------------------*/

void testParticleEngineAndLayers()
{
    int window_width = 900; int window_height = 400;
    Window window(window_width, window_height, "Particle Engine");
    int framerate = 27;

    // initialise two emitters
    Emitter smoke("test/smoke_emitter.config");

    Emitter rain("test/rain.png", 1, 10, 100, 100, 10000, 0.0, 1.0, 1.0, 1.0,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise two sprites
    Spritesheet man_sheet("test/spritesheet.png", 4, 4, 6, 13, false);
    Sprite man(man_sheet, 700, 0, 200, 200);

    Spritesheet block_sheet("test/spritesheet-blocks.png", 4, 2, 1, 8, true);
    Sprite blocks(block_sheet, 200, 20, 100, 100);

    Spritesheet chimney_sheet("test/chimney.png", 1, 1, 1, 1, false);
    Sprite chimney(chimney_sheet, 420, 0.0, 61, 61);

    Camera camera(man);
    World world(camera);
    world.addSprite(man);
    world.addSprite(blocks);
    world.addSprite(chimney);
    world.addEmitter(smoke);
    Engine engine(world);

    bool quit = false;

    while(quit == false)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //engine.update();
        //engine.draw();
        world.update();
        world.draw();
        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }
}

int main()
{
    testParticleEngineAndLayers();
    return 0;
}
