/*----------------------------------------
 * Graphics.cc
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker

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

// initialise OpenGL
// TODO: Put this somewhere else - possibly in Engine class
void Graphics::initGL(int window_width, int window_height,
                      float viewport_width, float viewport_height)
{
    // enable texturing
    glEnable(GL_TEXTURE_2D);

    // enable blending
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
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

    // edit the model-view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); // clear

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glClearColor(104.0f/255.0f, 160.0f/255.0f, 223.0f/255.0f, 1.0f);
    glViewport(0, 0, window_width, window_height);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(1.0f,1.0f,1.0f, 1.0f);
    glTranslatef(0.0f,0.0f,0.0f);
}

void Graphics::drawTexQuad(GLuint texture, float x, float y, float width, float height)
{
    GLfloat vertices[4*2] = {0.0, 0.0,
                            width, 0.0,
                            width, height,
                            0.0, height};

    GLfloat texcoords[4 * 2] = {0.0, 0.0,
                                1.0, 0.0,
                                1.0, 1.0,
                                0.0, 1.0};
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
