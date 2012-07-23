/*---------------------------------------
 * Camera.hh
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef CAMERA_HH
#define CAMERA_HH
/*--------------------------------------*/
#include "sprite/Sprite.hh"
/*--------------------------------------*/

class Camera
{
private:
    // how much of the world does the camera show
    int x_, y_, width_, height_;
    int x_offset_, y_offset_;
    bool attached_;
    Sprite * parent_sprite_;
public:
    Camera();
    Camera(Sprite& sprite);
    ~Camera();
    void attach(Sprite& sprite);
    void unattach();
    int getX();
    int getY();
    void update();
};

/*--------------------------------------*/
#endif /*ENGINE_HH*/
