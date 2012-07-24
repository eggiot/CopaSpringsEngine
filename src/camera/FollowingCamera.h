/*---------------------------------------
 * Camera.h
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef FOLLOWINGCAMERA_H
#define FOLLOWINGCAMERA_H
/*--------------------------------------*/
#include "Camera.h"
#include "../sprite/Sprite.h"
/*--------------------------------------*/

class FollowingCamera : public Camera
{
protected:
    Sprite& attached_sprite_;
public:
    FollowingCamera(Sprite& sprite) : Camera(), attached_sprite_(sprite)
    { }
    virtual void update();
};

/*--------------------------------------*/
#endif /*FOLLOWINGCAMERA_H*/
