/*---------------------------------------
 * Particle.cc
 *
 *  Created on: 23 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "../Graphics.hh"
#include "Particle.hh"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/

/*----------------------- PARTICLE ---------------------------*/

void Particle::update()
{
    //update particle
    // move the particle through its velocity
    x += velocity_x;
    y += velocity_y;

    // reduce its life length
    life_length -= 1;

    // accelerate / decelerate the particle
    velocity_x += acceleration_x;
    velocity_y += acceleration_y;

    // rotate
    rotate += rotate_velocity;

    // resize
    width  += width_change;
    height += height_change;
}

void Particle::draw()
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    Graphics::drawTexturedQuad(texture, 0, 0, width, height, 1.0f);
    glPopMatrix();
}


