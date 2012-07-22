/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Camera.hh"
 #include "sprite/Sprite.hh"
 /*--------------------------------------*/
Camera::Camera()
{
    parent_sprite_ = NULL;
    attached_ = false;
}

Camera::Camera(Sprite& sprite)
{
    parent_sprite_ = &sprite;
    attached_ = true;
}

Camera::~Camera()
{
    parent_sprite_ = NULL;
    attached_ = true;
}

void Camera::attach(Sprite& sprite)
{
    parent_sprite_ = &sprite;
    attached_ = true;
}

void Camera::unattach()
{
    parent_sprite_ = NULL;
    attached_ = false;
}

void Camera::update()
{
    if(attached_)
    {
        x_ = (parent_sprite_->getX()) - (width_ / 2) + x_offset_;
        y_ = parent_sprite_->getY() - (height_ / 2) + y_offset_;
    }
}
