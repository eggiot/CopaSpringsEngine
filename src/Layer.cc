/*---------------------------------------
 * Layer.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Layer.hh"
 #include "Sprites.hh"
 #include "Particles.hh"
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
    std::cout << "1\n";
    emitters.push_back(emitter);
    std::cout <<"2/n";
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