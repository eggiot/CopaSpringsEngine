/*---------------------------------------
 * Engine.cc
 *
 *  Created on: 20 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Camera.hh"
 #include "sprite/Sprite.hh"
 /*--------------------------------------*/
 #include <iostream>
 #include <SDL/SDL.h>
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

int Camera::getX()
{
    return x_;
}

int Camera::getY()
{
    return y_;
}

void Camera::update()
{
    if(attached_)
    {
        x_ = parent_sprite_->getX();
        y_ = parent_sprite_->getY();
        //std::cout << x_ << ", " << y_ << std::endl;
        //x_ = (parent_sprite_->getX()) - (width_ / 2) + x_offset_;
        //y_ = parent_sprite_->getY() - (height_ / 2) + y_offset_;
    }

   /*     SDL_Event event;
    while(SDL_PollEvent(&event))

    {
        if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_DOWN)
                y_ += 10;
            else if(event.key.keysym.sym == SDLK_UP)
                y_ -= 10;
            else if(event.key.keysym.sym == SDLK_LEFT)
                x_ += 10;
            else if(event.key.keysym.sym == SDLK_RIGHT)
                x_ -= 10;
        }

    }*/
}
