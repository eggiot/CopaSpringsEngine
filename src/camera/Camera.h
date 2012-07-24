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
    int x_, y_;
public:
    Camera();
    Camera(int x, int y);
    //assignment methods
    void setX(int x);
    void setY(int y);
    void setPosition(int x, int y);

    // query methods
    int getX();
    int getY();
    virtual void update();
};

/*--------------------------------------*/
#endif /*CAMERA_H*/
