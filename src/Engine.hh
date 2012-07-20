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
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

class Engine
{
private:
    std::vector<Layer> layers;
public:
    void addLayer(Layer layer);
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*ENGINE_HH*/
