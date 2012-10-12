/*---------------------------------------
 * Engine.h
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef ENGINE_H
#define ENGINE_H
/*--------------------------------------*/
#include "World.h"
#include "../graphics/Window.h"
/*--------------------------------------*/
#include <vector>
#include <string>
/*--------------------------------------*/

enum CSEngineFeature {
    CS_TEXTURING = 0,
    CS_TRANSPARENCY = 1
};

class Engine
{
private:
    World *world_;
    Window window_;
    int framerate_;
public:
    Engine();
    ~Engine();
    void setWorld(World& world);
    void initWindow(int width, int height, std::string title);
    void initGraphics(float viewport_width, float viewport_height);
    void enable(CSEngineFeature feature);
    void setFramerate(int msecs);
    void update();
    void run();
};

/*--------------------------------------*/
#endif /*ENGINE_H*/
