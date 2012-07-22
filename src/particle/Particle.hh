/*---------------------------------------
 * Particles.hh
 *
 *  Created on: 23 Aug 2011
 *      Author: Eliot J. Walker
 *
 *  Defines:
 *      Particle
 *      Emitter
 *      ParticleSystem
 *---------------------------------------*/
#ifndef PARTICLES_HH
#define PARTICLES_HH
/*---------------------------------------*/
#include <GL/gl.h>
/*---------------------------------------*/

struct Particle
{
    // the texture to draw
    GLuint texture;

    // the current x and y coordinates
    float x, y;

    // the direction in which the particle is travelling
    float velocity_x, velocity_y;

    // the acceleration of the particle on the x- and y-axis
    float acceleration_x, acceleration_y;

    // the amount by which the particle is being dragged down or pulled up
    float gravity_x, gravity_y;

    // the current size of the particle
    float width, height;

    // the amount by which the particle grows per update
    float width_change, height_change;

    // how rotated is the particle
    float rotate;

    // how much does the particle rotate per update
    float rotate_velocity;

    // for how many updates is the particle updated
    int life_length;

    // what is its background colour
    float background_colour[4];

    // what is its alpha value
    float alpha;

    // by how much does its alpha value change per update
    float alpha_change;

    // update the particle
    void update();

    // draw the particle
    void draw();
};

/*--------------------------------------*/
#endif /*PARTICLES_HH*/
