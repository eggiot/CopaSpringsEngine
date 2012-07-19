/*
 * test.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 */

// include engine headers
#include "Window.hh"
#include "Graphics.hh"
#include "Image.hh"
#include "Animation.hh"
#include "Sprites.hh"
#include "State.hh"
#include "Particles.hh"

// include graphics headers
#include <SDL/SDL.h>

// include standard library
#include <queue>
#include <iostream>
#include <math.h>

void testParticleEngine()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Window window(window_width, window_height, "Particle Engine");
    int framerate = 24;

    // initialise chimney animated frame

    AnimationFrame chimney("test/chimney.png", 1, false, false);


    // initialise two emitters
    Emitter smoke("test/dust.png",
                  1, 10, 10,
                  10, 100,
                  0.5, 0.5,
                  0.0, 0.0,
                  0.001, 0.001,
                  0.01, 0.01,
                  -0.000001, 0.000001,
                  -0.000001,0.000001,
                  0.001, 0.004,
                  10.0f/(float)window_width, 10.0f/(float)window_width,
                  0.0001, 0.001,
                  10.0f/(float)window_width, 10.0f/(float)window_width,
                  0.0001, 0.001);

    Emitter rain("test/rain.png",
                 1, 10, 100,
                 100, 10000,
                 0.0, 1.0,
                 1.0, 1.0,
                 -0.001, -0.001,
                 -0.03, -0.03,
                 0.0, 0.0,
                 0.0, 0.0,
                 0.001, 0.004,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0,
                 15.0f/(float)window_width, 15.0f/(float)window_width,
                 0.0, 0.0);

    // initialise a particle system

    std::cout << "ParticleSystem psystem1;" << std::endl;
    ParticleSystem psystem1;
    std::cout << "psystem1.addEmitter(smoke)" << std::endl;
    psystem1.addEmitter(smoke);
    std::cout << "psystem1.addEmitter(rain)" << std::endl;
    psystem1.addEmitter(rain);
    std::cout << std::endl << "Added emitters" << std::endl;

    bool quit = false;
    while(quit == false)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        psystem1.update();
        psystem1.draw();
        chimney.draw(0.475, 0.0, 61/(float)window_width, 61/(float)window_height);
        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }
}

// tests for AnimatedSprites
void testAnimatedSprites_StatesVelocity()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Window window(window_width, window_height, "AnimatedSprites - States and velocity");

    // load state 1
    Animation animation1;
    animation1.load("test/test2.anim", true);
    Objects::State state1;
    state1.setAnimation(animation1);

    // load state 2
    Animation animation2;
    animation2.load("test/test1.anim", true);
    Objects::State state2;
    state2.setAnimation(animation2);

    // load state 3
    Animation animation3;
    animation3.load("test/test3.anim", true);
    Objects::State state3;
    state3.setAnimation(animation3);

    float x = 0.0f; float y = 0.0f;
    float width = 150.0f/(float)window_width; float height = 150.0f/(float)window_height;
    float velocity = 10.0f/(float)window_width;

    Objects::Sprite sprite(x, y, width, height, state3);
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
        }*/

    }
}

void demoParticles_Animation()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Window window(window_width, window_height, "Particle Engine");

    // load state 1
    Animation animation_right;
    animation_right.load("test/demo1/horse-right.anim", true);
    Objects::State state_right;
    state_right.setAnimation(animation_right);

    float x = 0.0f; float y = 0.0f;
    float width = 150.0f/(float)window_width; float height = 150.0f/(float)window_height;
    float velocity = 10.0f/(float)window_width;

    Objects::Sprite sprite(x, y, width, height, state_right);
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
}

int main()
{
    testParticleEngine();
    //testAnimatedSprites_StatesVelocity();
    //demoParticles_Animation();
    return 0;
}
