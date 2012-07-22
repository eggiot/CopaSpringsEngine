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
#include "Layer.hh"
#include "Engine.hh"
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
    int window_width = 900; int window_height = 200;
    Window window(window_width, window_height, "Particle Engine");
    int framerate = 50;

    // initialise two emitters
    Emitter smoke("test/smoke_emitter.config");

    Emitter rain("test/rain.png", 1, 10, 100, 100, 10000, 0.0, 1.0, 1.0, 1.0,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise two sprites
    Spritesheet man_sheet("test/spritesheet.png", 4, 4, 6, 13, false);
    Sprite man(man_sheet, 0.8, 0.0, 200/(float)window_width, 200/(float)window_height);

    Spritesheet block_sheet("test/spritesheet-blocks.png", 4, 2, 1, 8, true);
    Sprite blocks(block_sheet, 0.1, 0.2, 100/(float)window_width, 100/(float)window_height);

    Spritesheet chimney_sheet("test/chimney.png", 1, 1, 1, 1, false);
    Sprite chimney(chimney_sheet, 0.47, 0.0, 61/(float)window_width, 61/(float)window_height);

    Layer emitter_layer;
    emitter_layer.addEmitter(rain);
    emitter_layer.addEmitter(smoke);
    Layer sprite_layer;
    sprite_layer.addSprite(chimney);
    sprite_layer.addSprite(man);
    sprite_layer.addSprite(blocks);
    Engine engine;
    engine.addLayer(emitter_layer);
    engine.addLayer(sprite_layer);

    bool quit = false;
    while(quit == false)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        engine.update();
        engine.draw();
        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }
}

int main()
{
    testParticleEngineAndLayers();
    return 0;
}
