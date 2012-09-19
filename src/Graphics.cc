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

// Draw an untextured quad
void Graphics::drawQuad(float x, float y, float width, float height, GLfloat rgba[4])
{
    glColor4fv(rgba);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        // anti-clockwise
        glVertex2f(0.0, 0.0);
        glVertex2f(width, 0.0);
        glVertex2f(width, height);
        glVertex2f(0.0, height);
    glEnd();
    glPopMatrix();
}

// draw a textured quad
void Graphics::drawTexturedQuad(GLuint texture_id, float x, float y,
                                float width, float height, float alpha)
{
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        // anti-clockwise
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); glVertex2f(width, 0.0);
        glTexCoord2f(1.0f, 1.0f); glVertex2f(width, height);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0, height);
    glEnd();
    glPopMatrix();
}

// draw part of a texture onto a quad
void Graphics::drawSubTexturedQuad(GLuint texture_id, float x, float y,
                                   float width, float height,
                                   float tex_x, float tex_y,
                                   float tex_width, float tex_height,
                                   float alpha)
{
    glColor4f(1.0f, 1.0f, 1.0f, alpha);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        // anti-clockwise
        glTexCoord2f(tex_x, tex_y); glVertex2f(0.0, 0.0);
        glTexCoord2f(tex_x+tex_width, tex_y); glVertex2f(width, 0.0);
        glTexCoord2f(tex_x+tex_width, tex_y+tex_height); glVertex2f(width, height);
        glTexCoord2f(tex_x, tex_y+tex_height); glVertex2f(0.0, height);
    glEnd();
    glPopMatrix();
}

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
