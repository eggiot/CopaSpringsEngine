/*---------------------------------------
 * Layer.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Layer.hh"
 #include "sprite/Sprite.hh"
 #include "particle/Emitter.hh"
 /*--------------------------------------*/
 #include <vector>
 #include <iostream>
 /*--------------------------------------*/

void Layer::addSprite(Sprite sprite)
{
    sprites.push_back(sprite);
}

void Layer::addEmitter(Emitter emitter)
{
    emitters.push_back(emitter);
}

void Layer::update()
{
    // update sprites
    for(std::vector<Sprite>::iterator current_sprite = sprites.begin();
    current_sprite != sprites.end(); ++current_sprite)
    {
        current_sprite->update();
    }

    // update emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters.begin();
    current_emitter != emitters.end(); ++current_emitter)
    {
        current_emitter->update();
    }

}

// TODO: draw half of the particles, then draw the sprites,
// then draw the remaining particles
void Layer::draw()
{
    // draw sprites
    for(std::vector<Sprite>::iterator current_sprite = sprites.begin();
    current_sprite != sprites.end(); ++current_sprite)
    {
        current_sprite->draw();
    }

    // draw emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters.begin();
    current_emitter != emitters.end(); ++current_emitter)
    {
        current_emitter->draw();
    }

}
