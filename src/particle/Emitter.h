/*---------------------------------------
 * Emitter.h
 *
 *  Created on: 21 Jul 2012
 *      Author: Eliot J. Walker
 *
 *  Defines:
 *      Emitter
 *---------------------------------------*/
#ifndef EMITTER_H
#define EMITTER_H
/*---------------------------------------*/
#include "Particle.h"
#include "../Image.h"
/*---------------------------------------*/
#include <stdlib.h>
#include <string>
#include <vector>
/*---------------------------------------*/

/* The Emitter provides all the necessary information for the particles it produces.
It provides a minimum and maximum value for a variety of parameters and provides
each particle it emits with a random value from within these ranges. */

class Emitter
{
private:
    // the image used for the emitter's particles
    Graphics::Image image_;

    // the length of time the particle exists
    int min_life_length_, max_life_length_;

    // these can be thought of as the emitter's left- and right-hand sides
    float min_x_pos_, max_x_pos_;

    // these can be thought of as the emitter's bottom and top sides
    float min_y_pos_, max_y_pos_;

    // the speed of the particle in the x-axis
    float min_velocity_x_, max_velocity_x_;

    // the speed of the particle in the y-axis
    float min_velocity_y_, max_velocity_y_;

    // the acceleration of the particly in the x-axis
    float min_acceleration_x_, max_acceleration_x_;

    // the acceleration of the particle in the y-axis
    float min_acceleration_y_, max_acceleration_y_;

    // the speed at which the particle rotates
    float min_rotate_velocity_, max_rotate_velocity_;

    // the initial particle width
    float min_width_, max_width_;

    // the speed at which the particle widens
    float min_width_change_, max_width_change_;

    // the initial particle height
    float min_height_, max_height_;

    // the speed at which the particle heightens
    float min_height_change_, max_height_change_;

    // keeps track of how many updates there have been
    int loop_;

    // how often the emitter emits
    int spawn_rate_;

    // how many particles are emitted each emission
    unsigned int particles_per_spawn_;

    // how many cycles to preemptively simulate so it appears to have been running for a while
    int pre_pump_cycles_;

    // the alive particles emitted by this emitter
    std::vector<Particle> particles_;

private:

    // Returns a random floating point number from within a range.
    inline float getRandRangef(float min, float max)
    {
        return min + ((max-min) * rand()) / (RAND_MAX + 1.0f);
    }

    // Returns a random integer from within a range. */

    inline int getRandRangei(int min, int max)
    {
        return rand() % (max - min + 1) + min; // TODO: Probably doesn't work
    }

    void prePump();

public:
    // constructor: manually create an emitter
    Emitter(std::string image_filename,
                 int spawn_rate, int particles_per_spawn, int pre_pump_cycles,
                 int min_life_length, int max_life_length,
                 float min_x_pos, float max_x_pos,
                 float min_y_pos, float max_y_pos,
                 float min_velocity_x, float max_velocity_x,
                 float min_velocity_y, float max_velocity_y,
                 float min_acceleration_x, float max_acceleration_x,
                 float min_acceleration_y,float max_acceleration_y,
                 float min_rotate_velocity, float max_rotate_velocity,
                 float min_width, float max_width,
                 float min_width_change, float max_width_change,
                 float min_height, float max_height,
                 float min_height_change, float max_height_change);

    // constructor: create an emitter from a config file
    Emitter(std::string filename);

    // emit a particle
    Particle emit();

    // update the state of the emitter and all the alive particles
    void update();

    // draw all the alive particles
    void draw();
};

/*--------------------------------------*/
#endif /*EMITTER_H*/
