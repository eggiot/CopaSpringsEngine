/*---------------------------------------
 * Layer.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "World.h"
 #include "../components/Emitter.h"
 /*--------------------------------------*/
 #include <vector>
 #include <boost/shared_ptr.hpp>
 /*--------------------------------------*/
 #include <GL/gl.h>
 /*--------------------------------------*/

void World::addGameObject(GameObject* game_object)
{
    boost::shared_ptr<GameObject> new_go(game_object);
    game_objects_.push_back(new_go);
}

void World::addEmitter(Emitter emitter)
{
    emitters_.push_back(emitter);
}

void World::update()
{
    // update game objects
    for(govec_t::iterator current_go = game_objects_.begin();
    current_go != game_objects_.end(); ++current_go)
    {
        current_go->get()->update();
    }

    // update emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters_.begin();
    current_emitter != emitters_.end(); ++current_emitter)
    {
        current_emitter->update();
    }
}

void World::run()
{
    glClear(GL_COLOR_BUFFER_BIT);
    // draw emitters
    for(std::vector<Emitter>::iterator current_emitter = emitters_.begin();
    current_emitter != emitters_.end(); ++current_emitter)
    {
        current_emitter->draw();
    }

    for(govec_t::iterator current_go = game_objects_.begin();
    current_go != game_objects_.end(); ++current_go)
    {
        current_go->get()->run();
    }

    SDL_GL_SwapBuffers();
}
