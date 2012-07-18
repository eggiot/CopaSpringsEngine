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
    Graphics::Window window(window_width, window_height, "Particle Engine");
    int framerate = 24;

    // initialise chimney animated frame

    Graphics::AnimationFrame chimney("test/chimney.png", 1, false, false);

    // initialise smoke emitter
    /*Graphics::Image image1;
    image1.load("test/dust.png", false, false);
    GLuint new_texture = Graphics::Utils::loadTexture(image1);
    Objects::Particles::Emitter smoke_emitter{new_texture};
    smoke_emitter.spawn_rate = 1;
    smoke_emitter.particles_per_spawn = 10;
    smoke_emitter.texture = new_texture;

    smoke_emitter.min_life_length = 10; smoke_emitter.max_life_length = 100;
    smoke_emitter.min_x_pos = 0.5; smoke_emitter.max_x_pos=0.5;
    smoke_emitter.min_y_pos=0.0, smoke_emitter.max_y_pos=0.0;
    smoke_emitter.min_velocity_x=-0.001; smoke_emitter.max_velocity_x=0.001;
    smoke_emitter.min_velocity_y=0.01; smoke_emitter.max_velocity_y=0.01;
    smoke_emitter.min_acceleration_x = -0.000001; smoke_emitter.max_acceleration_x=0.000001;
    smoke_emitter.min_acceleration_y=-0.0001; smoke_emitter.max_acceleration_y=0.001;
    smoke_emitter.min_rotate_velocity=0.001; smoke_emitter.max_rotate_velocity=0.004;
    smoke_emitter.min_width=10.0f/(float)window_width; smoke_emitter.max_width=10.0f/(float)window_width;
    smoke_emitter.min_width_change=0.0001; smoke_emitter.max_width_change=0.001;
    smoke_emitter.min_height=smoke_emitter.min_width; smoke_emitter.max_height=smoke_emitter.max_width;
    smoke_emitter.min_height_change=smoke_emitter.min_width_change; smoke_emitter.max_height_change=smoke_emitter.max_width_change;



    // initialise rain emitter
    Graphics::Image image2;
    image2.load("test/rain.png", false, false);
    GLuint new_texture2 = Graphics::Utils::loadTexture(image2);
    Objects::Particles::Emitter rain_emitter{new_texture2};
    rain_emitter.spawn_rate = 1;
    rain_emitter.particles_per_spawn = 10;
    rain_emitter.texture = new_texture2;

    rain_emitter.min_life_length = 100; rain_emitter.max_life_length = 10000;
    rain_emitter.min_x_pos = 0.0; rain_emitter.max_x_pos=1.0;
    rain_emitter.min_y_pos=1.0, rain_emitter.max_y_pos=1.0;
    rain_emitter.min_velocity_x=-0.001; rain_emitter.max_velocity_x=0.001;
    rain_emitter.min_velocity_y=-0.03; rain_emitter.max_velocity_y=-0.03;
    rain_emitter.min_acceleration_x = 0.0; rain_emitter.max_acceleration_x=0.0;
    rain_emitter.min_acceleration_y=0.0; rain_emitter.max_acceleration_y=0.0;
    rain_emitter.min_rotate_velocity=0.001; rain_emitter.max_rotate_velocity=0.004;
    rain_emitter.min_width=15.0f/(float)window_width; rain_emitter.max_width=15.0f/(float)window_width;
    rain_emitter.min_width_change=0.0; rain_emitter.max_width_change=0.0;
    rain_emitter.min_height=rain_emitter.min_width; rain_emitter.max_height=rain_emitter.max_width;
    rain_emitter.min_height_change=rain_emitter.min_width_change; rain_emitter.max_height_change=rain_emitter.max_width_change;

    // initialise a particle system

    Objects::Particles::ParticleSystem psystem1;
    psystem1.addEmitter(smoke_emitter);
    psystem1.addEmitter(rain_emitter);

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
                        smoke_emitter.min_velocity_x -= 0.001;
                        smoke_emitter.max_velocity_x -= 0.001;
                        break;
                    }
                    else if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        smoke_emitter.min_velocity_x += 0.001;
                        smoke_emitter.max_velocity_x += 0.001;
                        break;
                    }

                default:
                    break;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);
        psystem1.update(true);
        //chimney.draw(0.475, 0.0, 61/(float)window_width, 61/(float)window_height);

        SDL_GL_SwapBuffers();
        window.sleep(framerate);
    }*/
}

// tests for AnimatedSprites
void testAnimatedSprites_StatesVelocity()
{
    SDL_Event event;
    int window_width = 900; int window_height = 300;
    Graphics::Window window(window_width, window_height, "AnimatedSprites - States and velocity");

    // load state 1
    Graphics::Animation animation1;
    animation1.load("test/test2.anim", true);
    Objects::State state1;
    state1.setAnimation(animation1);

    // load state 2
    Graphics::Animation animation2;
    animation2.load("test/test1.anim", true);
    Objects::State state2;
    state2.setAnimation(animation2);

    // load state 3
    Graphics::Animation animation3;
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
    Graphics::Window window(window_width, window_height, "Particle Engine");

    // load state 1
    Graphics::Animation animation_right;
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
