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
    GLuint texture;
    float x;
    float y;
    float velocity_x;
    float velocity_y;
    float acceleration_x;
    float acceleration_y;
    float gravity_x;
    float gravity_y;
    float width;
    float width_change;
    float height;
    float height_change;
    float rotate;
    float rotate_velocity;
    int life_length;
    float background_colour[4];
    float alpha;
    float alpha_change;
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*PARTICLES_HH*/
