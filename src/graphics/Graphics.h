/*---------------------------------------
 * Graphics.h
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
 *
 * based on:
 *  oglutils.h
 *
 *   Created on: 16 Aug 2011
 *       Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef GRAPHICS_H
#define GRAPHICS_H
/*--------------------------------------*/
#include "../media/Image.h"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

enum CSBlendState
{
    CS_BLEND_OFF = 0,
    CS_BLEND_SRC_OVER_DST = 1,
    CS_BLEND_ZERO_OVER_DST = 2,
    CS_BLEND_SRC_INTO_DST = 3
};
    

namespace Graphics
{

struct Quad
{
    float x, y, width, height;
    float ux, uy, uwidth, uheight;
    float rotation;
};

// default initialisation function
void initGL(int window_width, int window_height,
            float viewport_width, float viewport_height);

// update the OpenGL blend state with glBlendFunc
void setGLBlend(CSBlendState state);

// move the "camera" to (x, y)
void lookAt(float x, float y);

// immediate mode drawing functions
void drawQuad_i(float x, float y, float width, float height, GLfloat rgba[4]);
void drawTexQuad_i(GLuint texture_id, float x, float y,
                                float width, float height, float alpha);
void drawSubTexQuad_i(GLuint texture_id, float x, float y,
                         float width, float height,
                         float tex_x, float tex_y,
                         float tex_width, float tex_height, float alpha);

void drawTexQuad(GLuint texture, float x, float y, float width, float height);
void drawSubTexQuad(GLuint texture, float x, float y,
                    float width, float height,
                    float tex_x, float tex_y,
                    float tex_width, float tex_height);
}

/*--------------------------------------*/
#endif /*GRAPHICS_H*/

