/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Layer.hh"
#include "Engine.hh"
#include "Camera.hh"
/*--------------------------------------*/
#include <iostream>
/*--------------------------------------*/

Engine::Engine()
{
    camera_ = NULL;
}
Engine::Engine(Camera& camera)
{
    camera_ = &camera;
}

void Engine::addLayer(Layer layer)
{
    layers_.push_back(layer);
}

void Engine::update()
{
    camera_->update();
    // update layers
    for(std::vector<Layer>::iterator current_layer = layers_.begin();
    current_layer != layers_.end(); ++current_layer)
    {
        current_layer->update();
    }
}

void Engine::draw()
{
    // push a new matrix for our camera
    glPushMatrix();
    glTranslatef(camera_->getX(), camera_->getY(), 0.0f);
    // draw layers
    for(std::vector<Layer>::iterator current_layer = layers_.begin();
    current_layer != layers_.end(); ++current_layer)
    {
        current_layer->draw();
    }
    glPopMatrix();
}
