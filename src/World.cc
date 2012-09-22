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
 /*--------------------------------------*/

World::World()
{
    camera_follows_ = false;
}

void World::addSprite(Sprite sprite)
{
    sprites_.push_back(sprite);
}

void World::addCentralSprite(Sprite sprite, float x_offset, float y_offset)
{
    central_sprite_ = sprite;
    camera_follows_ = true;
}

void World::addEmitter(Emitter emitter)
{
    emitters_.push_back(emitter);
}

void World::setCamera(Camera camera)
{
    camera_ = camera;
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

    // update camera, moving it to the central sprite if camera_follows_
    if(camera_follows_)
    {
        central_sprite_.update();
        camera_.setPosition(central_sprite_.getX(), central_sprite_.getY());
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

    if (camera_follows_)
    {
        central_sprite_.draw();
    }
}
