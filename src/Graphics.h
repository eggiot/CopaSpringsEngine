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
#include "Image.h"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/
#include <vector>
/*--------------------------------------*/

namespace Graphics
{

// objects for describing geometric data
struct TexCoord
{
    float x, y, width, height;
};

struct VertexCoord
{
    float x, y, width, height;
};

struct Quad
{
    float x, y, width, height;
    float ux, uy, uwidth, uheight;
};

// default initialisation function
void initGL(int window_width, int window_height,
            float viewport_width, float viewport_height);

// immediate mode drawing functions
void drawQuad(float x, float y, float width, float height, GLfloat rgba[4]);
void drawTexturedQuad(GLuint texture_id, float x, float y,
                                float width, float height, float alpha);
void drawSubTexturedQuad(GLuint texture_id, float x, float y,
                         float width, float height,
                         float tex_x, float tex_y,
                         float tex_width, float tex_height, float alpha);

void drawScene(std::vector<Quad> quads);
}

/*--------------------------------------*/
#endif /*GRAPHICS_H*/

