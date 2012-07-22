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
    Graphics::Image image_;

    //! Minimum value for the length of time the particle exists
    int min_life_length_;

    //! maximum particle life length
    int max_life_length_;

    /*! \brief Minimum value for a particle's initial x-coordinate.

    This can be thought of as the emitter's left-hand side. */
    float min_x_pos_;

    /*! \brief Maximum value for a particle's initial x-coordinate.

    This can be thought of as the emitter's right-hand side. */
    float max_x_pos_;

    /*! \brief Minimum value for a particle's initial y-coordinate.

    This can be thought of as the emitter's bottom side. */
    float min_y_pos_;

    /*! \brief Maximum value for a particle's initial y-coordinate.

    This can be thought of as the emitter's top side. */
    float max_y_pos_;
    float min_velocity_x_, max_velocity_x_;
    float min_velocity_y_, max_velocity_y_;
    float min_acceleration_x_, max_acceleration_x_;
    float min_acceleration_y_, max_acceleration_y_;
    float min_rotate_velocity_, max_rotate_velocity_;
    float min_width_, max_width_;
    float min_width_change_, max_width_change_;
    float min_height_, max_height_;
    float min_height_change_, max_height_change_;

    float min_alpha_, max_alpha_;
    float min_alpha_change_, max_alpha_change_;

    int loop_;
    std::vector<Particle> particles_;

    int spawn_rate_;
    unsigned int particles_per_spawn_;
    // preemptively simulate cycles so particle system appears to have been running for a while
    int pre_pump_cycles_;

private:
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
    Particle emit();
    void update();
    void draw();
};

/*--------------------------------------*/
#endif /*EMITTER_HH*/
