/*---------------------------------------
 * Layer.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "World.h"
 #include "sprite/Sprite.h"
 #include "particle/Emitter.h"
 /*--------------------------------------*/
 #include <vector>
 #include <iostream>
 /*--------------------------------------*/

void World::addSprite(Sprite sprite)
{
    sprites_.push_back(sprite);
}

void World::addEmitter(Emitter emitter)
{
    emitters_.push_back(emitter);
}

void World::update()
{
    // update sprites
    for(std::vector<Sprite>::iterator current_sprite = sprites_.begin();
    current_sprite != sprites_.end(); ++current_sprite)
    {
        current_sprite->update();
    }

    // update emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters_.begin();
    current_emitter != emitters_.end(); ++current_emitter)
    {
        current_emitter->update();
    }
    camera_.update();
}

// TODO: draw half of the particles, then draw the sprites,
// then draw the remaining particles
void World::draw()
{
    // draw emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters_.begin();
    current_emitter != emitters_.end(); ++current_emitter)
    {
        current_emitter->draw();
    }

    for(std::vector<Sprite>::iterator current_sprite = sprites_.begin();
    current_sprite != sprites_.end(); ++current_sprite)
    {
        current_sprite->draw();
    }
}
