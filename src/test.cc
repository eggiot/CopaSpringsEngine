/*----------------------------------------
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 ---------------------------------------*/
#include "Window.hh"
#include "Graphics.hh"
#include "Image.hh"
#include "Sprites.hh"
#include "Particles.hh"
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
    int framerate = 24;

    // initialise chimney animated frame
    Spritesheet chimney_sheet("test/spritesheet.png", 4, 4);
    Sprite chimney(chimney_sheet, 0.475, 0.0, 61/(float)window_width, 61/(float)window_height);

    // initialise two emitters - this will be done through config files
    /*Emitter smoke("test/dust.png", 1, 50, 100, 10, 100, 0.5, 0.5, 0.0, 0.0,
                  -0.0001, 0.0001, 0.01, 0.01, -0.000001, 0.000001, -0.000001,0.000001,
                  0.001, 0.004, 10.0f/(float)window_width, 10.0f/(float)window_width,
                  0.0001, 0.001, 10.0f/(float)window_width, 10.0f/(float)window_width,
                  0.0001, 0.001);*/
    Emitter smoke("test/smoke_emitter.config");

    Emitter rain("test/rain.png", 1, 10, 10, 100, 10000, 0.0, 1.0, 1.0, 1.0,
                 -0.001, -0.001, -0.03, -0.03, 0.0, 0.0, 0.0, 0.0, 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0, 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);
    Layer layer;
    layer.addEmitter(smoke);
    Layer layer2;
    layer2.addEmitter(rain);

    Engine engine;
    engine.addLayer(layer);
    engine.addLayer(layer2);

    bool quit = false;
    while(quit == false)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        engine.update();
        engine.draw();
        chimney.update();
        chimney.draw();
        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }
}

// tests for AnimatedSprites
/*void testAnimatedSprites_StatesVelocity()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Window window(window_width, window_height, "AnimatedSprites - States and velocity");

    // load state 1
    Animation animation1;
    animation1.load("test/test2.anim", true);
    State state1;
    state1.setAnimation(animation1);

    // load state 2
    Animation animation2;
    animation2.load("test/test1.anim", true);
    State state2;
    state2.setAnimation(animation2);

    // load state 3
    Animation animation3;
    animation3.load("test/test3.anim", true);
    State state3;
    state3.setAnimation(animation3);

    float x = 0.0f; float y = 0.0f;
    float width = 150.0f/(float)window_width; float height = 150.0f/(float)window_height;

    Sprite sprite(x, y, width, height, state3);
    sprite.addState("right", state1);
    sprite.addState("left", state2);

    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_LEFT)
                    {
                        sprite.setState("left");
                        sprite.setXVelocity(-0.01f);
                        break;
                    }
                    else if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        sprite.setState("right");
                        sprite.setXVelocity(0.01f);
                        break;
                    }

                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
                    {
                        sprite.setState("idle");
                        sprite.setXVelocity(0.0f);
                        break;
                    }


                default:
                    break;
            }
        }

        sprite.update();
        sprite.draw();
        SDL_GL_SwapBuffers();
        window.sleep(24);
        glClear(GL_COLOR_BUFFER_BIT);


 /*       if(sprite.getX() > (1.0f-width))
        {
            sprite.setState("choke");
            sprite.setXVelocity(-velocity);
        }
        else if(sprite.getX() < 0.0f)
        {
            sprite.setState("idle");
            sprite.setXVelocity(velocity);
        }

    }
}*/

/*void demoParticles_Animation()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Window window(window_width, window_height, "Particle Engine");

    // load state 1
    Animation animation_right;
    animation_right.load("test/demo1/horse-right.anim", true);
    State state_right;
    state_right.setAnimation(animation_right);

    float x = 0.0f; float y = 0.0f;
    float width = 150.0f/(float)window_width; float height = 150.0f/(float)window_height;
    float velocity = 10.0f/(float)window_width;

    Sprite sprite(x, y, width, height, state_right);
    sprite.setXVelocity(velocity);

    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }

        sprite.update();
        sprite.draw();
        SDL_GL_SwapBuffers();
        window.sleep(24);
        glClear(GL_COLOR_BUFFER_BIT);


        if(sprite.getX() > (1.0f-width))
        {
            sprite.setState("choke");
            sprite.setXVelocity(-velocity);
        }
        else if(sprite.getX() < 0.0f)
        {
            sprite.setState("idle");
            sprite.setXVelocity(velocity);
        }

    }
}*/

int main()
{
    testParticleEngineAndLayers();
    //testAnimatedSprites_StatesVelocity();
    //demoParticles_Animation();
    return 0;
}
