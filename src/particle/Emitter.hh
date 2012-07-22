/*---------------------------------------
 * Emitter.hh
 *
 *  Created on: 21 Jul 2012
 *      Author: Eliot J. Walker
 *
 *  Defines:
 *      Emitter
 *---------------------------------------*/
#ifndef EMITTER_HH
#define EMITTER_HH
/*---------------------------------------*/
#include "Particle.hh"
#include "../Image.hh"
/*---------------------------------------*/
#include <stdlib.h>
#include <string>
#include <vector>
/*---------------------------------------*/

/*! \brief A particle emitter.

The Emitter provides all the necessary information for the particles it produces. It
provides a minimum and maximum value for a variety of parameters and provides each
particle it emits with a random value from within these ranges. */

class Emitter
{
private:
    //! The image used for the emitter's particles
    Graphics::Image image;

    //! Minimum value for the length of time the particle exists
    int min_life_length;

    //! maximum particle life length
    int max_life_length;

    /*! \brief Minimum value for a particle's initial x-coordinate.

    This can be thought of as the emitter's left-hand side. */
    float min_x_pos;

    /*! \brief Maximum value for a particle's initial x-coordinate.

    This can be thought of as the emitter's right-hand side. */
    float max_x_pos;

    /*! \brief Minimum value for a particle's initial y-coordinate.

    This can be thought of as the emitter's bottom side. */
    float min_y_pos;

    /*! \brief Maximum value for a particle's initial y-coordinate.

    This can be thought of as the emitter's top side. */
    float max_y_pos;
    float min_velocity_x, max_velocity_x;
    float min_velocity_y, max_velocity_y;
    float min_acceleration_x, max_acceleration_x;
    float min_acceleration_y, max_acceleration_y;
    float min_rotate_velocity, max_rotate_velocity;
    float min_width, max_width;
    float min_width_change, max_width_change;
    float min_height, max_height;
    float min_height_change, max_height_change;

    float min_alpha, max_alpha;
    float min_alpha_change, max_alpha_change;

    int loop;
    std::vector<Particle> particles;

    /*! \brief Get random floating point number within a range

    Returns a random floating point number from within a range. */
    inline float getRandRangef(float min, float max)
    {
        return min + ((max-min) * rand()) / (RAND_MAX + 1.0f);
    }

    /*! \brief Get random integer within a range

    Returns a random integer from within a range. */

    inline int getRandRangei(int min, int max)
    {
        return rand() % (max - min + 1) + min; // TODO: Probably doesn't work
    }

public:
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
    Emitter(std::string filename);
    int spawn_rate;
    unsigned int particles_per_spawn;
    //! preemptively simulate cycles so particle system appears to have been running for a while
    int pre_pump_cycles;
    Particle emit();
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*EMITTER_HH*/
