/*---------------------------------------
 * Graphics.hh
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
 *
 * based on:
 *  oglutils.hh
 *
 *   Created on: 16 Aug 2011
 *       Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef GRAPHICS_HH
#define GRAPHICS_HH
/*--------------------------------------*/
#include "Image.hh"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/

namespace Graphics
{
namespace Utils
{
void drawQuad(float x, float y, float width, float height, GLfloat rgba[4]);
void drawTexturedQuad(GLuint texture_id, float x, float y, float width, float height);
void initGL(int window_width, int window_height);
}
}

/*--------------------------------------*/
#endif /*GRAPHICS_HH*/

