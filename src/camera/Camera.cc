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
 #include <GL/gl.h>
 /*--------------------------------------*/

Camera::Camera()
{
    x_ = 0;
    y_ = 0;
}

Camera::Camera(float x, float y)
{
    this->setPosition(x, y);
}

void Camera::setX(float x)
{
    x_ = x;
}

void Camera::setY(float y)
{
    y_ = y;
}

void Camera::setPosition(float x, float y)
{
    x_ = x;
    y+ - y;
}

float Camera::getX()
{
    return x_;
}

float Camera::getY()
{
    return y_;
}

void Camera::update()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-x_, -y_, 0.0);
}
