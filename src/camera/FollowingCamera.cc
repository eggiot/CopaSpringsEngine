/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 24 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "FollowingCamera.h"
#include "../sprite/Sprite.h"
/*--------------------------------------*/

void FollowingCamera::update()
{
    x_ = attached_sprite_.getX() - 2;
    y_ = attached_sprite_.getY();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-x_, -y_, 0.0);
}
