/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Engine.h"
#include "../components/Camera.h"
/*--------------------------------------*/
#include <iostream>
/*--------------------------------------*/

Engine::Engine()
{
    world_ = NULL;
}

Engine::~Engine()
{
    world_ = NULL;
}

void Engine::initWindow(int width, int height, std::string title)
{
    window_.init(width, height, title);
}

void Engine::initGraphics(float viewport_width, float viewport_height)
{
    window_.initGraphics(viewport_width, viewport_height);
}

void Engine::setFramerate(int msecs)
{
    framerate_ = msecs;
}


void Engine::setWorld(World& world)
{
    world_ = &world;
}

void Engine::update()
{
    world_->update();
}

void Engine::run()
{
    world_->run();
    window_.sleep(framerate_);
}
