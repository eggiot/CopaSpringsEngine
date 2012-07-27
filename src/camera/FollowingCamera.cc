/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 24 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "FollowingCamera.h"
#include "../sprite/Sprite.h"
/*--------------------------------------*/
#include <iostream>
/*--------------------------------------*/

void FollowingCamera::update()
{
    x_ = attached_sprite_.getX() - (attached_sprite_.getWidth() * 2);
    y_ = attached_sprite_.getY();
    std::cout << "Hello!!" << std::endl;
    std::cout << x_ << ", " << y_ << std::endl;
}