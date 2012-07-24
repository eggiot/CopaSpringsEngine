/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Engine.hh"
#include "Camera.hh"
/*--------------------------------------*/
#include <iostream>
#include <GL/glu.h>
/*--------------------------------------*/

Engine::Engine(World& world)
{
    world_ = &world;
}
void Engine::setWorld(World& world)
{
    world_ = &world;
}

void Engine::update()
{
}

void Engine::draw()
{
}
