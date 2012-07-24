/*---------------------------------------
 * Camera.cc
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Camera.h"
  /*--------------------------------------*/
 #include <iostream>
 #include <SDL/SDL.h>
 /*--------------------------------------*/

Camera::Camera()
{
    x_ = 0;
    y_ = 0;
}

Camera::Camera(int x, int y)
{
    this->setPosition(x, y);
}

void Camera::setX(int x)
{
    x_ = x;
}

void Camera::setY(int y)
{
    y_ = y;
}

void Camera::setPosition(int x, int y)
{
    x_ = x;
    y+ - y;
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
{ }
