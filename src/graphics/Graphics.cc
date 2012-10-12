/*----------------------------------------
 * Graphics.cc
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
8
 * based on:
 *  oglutils.cc
 *
 *   Created on: 16 Aug 2011
 *       Author: Eliot J. Walker
 ---------------------------------------*/
#include "Graphics.h"
/*--------------------------------------*/
#include <GL/gl.h>
#include <GL/glu.h>
/*--------------------------------------*/
#include <vector>
#include <iostream>
/*--------------------------------------*/

void Graphics::setGLBlend(CSBlendState state)
{
    switch(state)
    {
        case CS_BLEND_OFF:
            glBlendFunc(GL_ONE, GL_ZERO);
            glDisable(GL_BLEND);
            break;
        case CS_BLEND_ZERO_OVER_DST:
            glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            break;
        case CS_BLEND_SRC_INTO_DST:
            glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            break;
        case CS_BLEND_SRC_OVER_DST: default:
            glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            break;
    }
}

void Graphics::lookAt(float x, float y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-x, -y, 0.0);
}

// initialise OpenGL
// TODO: Put this somewhere else - possibly in Engine class
void Graphics::initGL(int window_width, int window_height,
                      float viewport_width, float viewport_height)
{
    // enable texturing
    glEnable(GL_TEXTURE_2D);

    // enable blending
    setGLBlend(CS_BLEND_SRC_OVER_DST);
    
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

    /*disable the depth test - depth will be determined
    only by the order in which the objects are drawn*/
    glDisable(GL_DEPTH_TEST);

    // set up a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // clear
    float aspect = (float)window_width / (float)window_height;
    gluOrtho2D(0.0, aspect*viewport_width, 0.0, viewport_height); //orthographic projection

    // sets GL_MODELVIEW and clears it
    Graphics::lookAt(0.0, 0.0);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glClearColor(1.0f, 0.4f, 0.1f, 1.0f);
    glViewport(0, 0, window_width, window_height);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0f,1.0f,1.0f, 1.0f);
}

void Graphics::drawTexQuad(GLuint texture, float x, float y, float width, float height)
{
    Graphics::drawSubTexQuad(texture, x, y, width, height, 0.0, 0.0, 1.0, 1.0);
}

void Graphics::drawSubTexQuad(GLuint texture, float x, float y,
                              float width, float height,
                              float tex_x, float tex_y,
                              float tex_width, float tex_height)
{
    GLfloat vertices[4*2] = {0.0, 0.0,
                            width, 0.0,
                            width, height,
                            0.0, height};

    GLfloat texcoords[4 * 2] = {tex_x, tex_y,
                                tex_x + tex_width, tex_y,
                                tex_x + tex_width, tex_y + tex_height,
                                tex_x, tex_y + tex_height};
    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 4);
    glPopMatrix();
}
