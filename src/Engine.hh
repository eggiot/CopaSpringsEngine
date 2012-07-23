/*---------------------------------------
 * Engine.hh
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef ENGINE_HH
#define ENGINE_HH
/*--------------------------------------*/
#include "Layer.hh"
#include "Camera.hh"
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Engine
{
private:
    std::vector<Layer> layers_;
    Camera *camera_;
public:
    Engine();
    Engine(Camera& camera);
    void addLayer(Layer layer);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*ENGINE_HH*/
