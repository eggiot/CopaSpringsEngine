/*---------------------------------------
 * Camera.h
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef CAMERA_H
#define CAMERA_H
/*--------------------------------------*/

class Camera
{
protected:
    // what part of the world does the camera show
    float x_, y_;
public:
    Camera();
    Camera(float x, float y);
    //assignment methods
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);

    // query methods
    float getX();
    float getY();
    virtual void update();
};

/*--------------------------------------*/
#endif /*CAMERA_H*/
