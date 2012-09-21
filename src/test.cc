/*----------------------------------------
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ---------------------------------------*/
#include "Window.h"
#include "Graphics.h"
#include "Image.h"
#include "sprite/Sprite.h"
#include "particle/Emitter.h"
#include "Engine.h"
#include "World.h"
#include "camera/FollowingCamera.h"
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
    Window window(window_width, window_height, "Particle Engine", 4, 4);
    int framerate = 50;

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

    FollowingCamera camera(man);
    World world(camera);
    world.addSprite(blocks);
    world.addSprite(chimney);
    world.addEmitter(smoke);
    world.addSprite(man);
    Engine engine(world);

    bool quit = false;

    while(quit == false)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        man.update();
        camera.update();
        world.update();

        if(man.getX() < 0)
            man.setVelocity(0.3, 0);
        else if(man.getX() > 5)
            man.setVelocity(-0.3, 0);
        world.draw();
        man.draw();
        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }
}

int main()
{
    testParticleEngineAndLayers();
    return 0;
}
