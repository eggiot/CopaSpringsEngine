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
#include "Audio.h"
#include "GameObject.h"
/*--------------------------------------*/
#include <iostream>
#include <GL/gl.h>
/*--------------------------------------*/

#define RUN_TIME 10000

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
    Emitter smoke("test/smoke_emitter.config");

    Emitter rain("test/rain.png", 1, 10, 100, 100, 10000, -1000, 1000, viewport_height, viewport_height,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise two sprites
    Spritesheet man_sheet("test/spritesheet.png", 4, 4, 6, 13, false);
    Sprite man(man_sheet, 5, 0, 2.0, 2.0);
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
    while(SDL_GetTicks() < RUN_TIME)
    {
        engine.update();
        engine.draw();
    }
}

class RenderComponent : public Component
{
public:
    void update()
    {
        std::cout << "Updating TestComponent" << std::endl;
    }

    void render()
    {
        std::cout << "Rendering" << std::endl;
    }
};

void testGameObjects()
{
    GameObject go("test_game_object");
    Graphics::Quad quad;
    quad.x = 1; quad.y = 1; quad. width = 1; quad.height = 1; quad.rotation = 0;
    quad.ux = 0; quad.uy = 0; quad.uwidth = 1; quad.uheight = 1;
    go.setQuad(quad);
    RenderComponent* gc = new RenderComponent();
    go.setComponent(gc);

    Component* gcd = go.getComponent(gc->family_id_);
    RenderComponent* testgcd = static_cast<RenderComponent*>(gcd);

    if (gcd != NULL)
    {
        std::cout << "Got something" << std::endl;
        if (gc == gcd)
        {
            std::cout << "gc == gcd" << std::endl;
            gcd->update();
            testgcd->render();
        }
        else
        {
            std::cout << "gc != gcd" << std::endl;
        }
    }
    else
    {
        std::cout << "Didn't get anything" << std::endl;
    }

    std::cout << gc << std::endl;

    go.clearComponents();

    std::cout << gc << std::endl;
}

int main()
{
    testParticleEngineAndLayers();
    //testGameObjects();
    return 0;
}
