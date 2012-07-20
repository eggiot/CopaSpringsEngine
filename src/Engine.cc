/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Layer.hh"
#include "Engine.hh"

void Engine::addLayer(Layer layer)
{
    layers.push_back(layer);
}

void Engine::update()
{
    // update layers
    for(std::vector<Layer>::iterator current_layer = layers.begin();
    current_layer != layers.end(); ++current_layer)
    {
        current_layer->update();
    }
}

void Engine::draw()
{
    // draw layers
    for(std::vector<Layer>::iterator current_layer = layers.begin();
    current_layer != layers.end(); ++current_layer)
    {
        current_layer->draw();
    }
}
