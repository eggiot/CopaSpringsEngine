/*---------------------------------------
 * Camera.cc
 *
 *  Created on: 22 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
 #include "Camera.h"
 /*--------------------------------------*/
 #include "../graphics/Graphics.h"
 /*--------------------------------------*/

void cameraLookAt(float x, float y)
{
    Graphics::lookAt(x, y);
}
