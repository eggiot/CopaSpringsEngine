/*---------------------------------------
 * Camera.cc
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Camera.h"
 /*--------------------------------------*/
 #include <GL/gl.h>
 /*--------------------------------------*/

void cameraLookAt(float x, float y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-x, -y, 0.0);
}
