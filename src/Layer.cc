/*---------------------------------------
 * Layer.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Layer.hh"
 #include "Sprites.hh"
 /*--------------------------------------*/
 #include <vector>
 /*--------------------------------------*/

void Layer::addSprite(Sprite sprite)
{
    sprites.push_back(sprite);
}

void Layer::update()
{
    for(std::vector<Sprite>::iterator current_sprite = sprites.begin();
    current_sprite != sprites.end(); ++current_sprite)
    {
        current_sprite->update();
    }
}

void Layer::draw()
{
    for(std::vector<Sprite>::iterator current_sprite = sprites.begin();
    current_sprite != sprites.end(); ++current_sprite)
    {
        current_sprite->draw();
    }
}
