/*---------------------------------------
 * Emitter.cc
 *
 *  Created on: 21 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Emitter.h"
#include "Particle.h"
#include "../Image.h"
#include "../util/ConfigFile.h"
/*---------------------------------------*/
#include <vector>
/*---------------------------------------*/

// preemptively pump a number of cycles so it looks as though the emitters been running for some time
void Emitter::prePump()
{
    for(int cycle = 0; cycle != pre_pump_cycles_; ++cycle)
    {
        particles_.push_back(this->emit());
        this->update();
    }
}

Emitter::Emitter(std::string image_filename,
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
                 float min_height_change, float max_height_change)
{
    pre_pump_cycles_      = pre_pump_cycles;
    spawn_rate_           = spawn_rate;
    particles_per_spawn_  = particles_per_spawn;
    min_life_length_      = min_life_length;
    max_life_length_      = max_life_length;
    min_x_pos_            = min_x_pos;
    max_x_pos_            = max_x_pos;
    min_y_pos_            = min_y_pos;
    max_y_pos_            = max_y_pos;
    min_velocity_x_       = min_velocity_x;
    max_velocity_x_       = max_velocity_x;
    min_velocity_y_       = min_velocity_y;
    max_velocity_y_       = max_velocity_y;
    min_acceleration_x_   = min_acceleration_x;
    max_acceleration_x_   = max_acceleration_x;
    min_acceleration_y_   = min_acceleration_y;
    max_acceleration_y_   = max_acceleration_y;
    min_rotate_velocity_  = min_rotate_velocity;
    max_rotate_velocity_  = max_rotate_velocity;
    min_width_            = min_width;
    max_width_            = max_width;
    min_width_change_     = min_width_change;
    max_width_change_     = max_width_change;
    min_height_           = min_height;
    max_height_           = max_height;
    min_height_change_    = min_height_change;
    max_height_change_    = max_height_change;

    image_.load(image_filename);
    loop_ = 1;

    prePump();
}

Emitter::Emitter(std::string filename)
{
    ConfigFile config(filename);

    pre_pump_cycles_      = config.getValue("pre_pump_cycles");
    spawn_rate_           = config.getValue("spawn_rate");
    particles_per_spawn_  = config.getValue("particles_per_spawn");
    min_life_length_      = config.getValue("min_life_length");
    max_life_length_      = config.getValue("max_life_length");
    min_x_pos_            = config.getValue("min_x_pos");
    max_x_pos_            = config.getValue("max_x_pos");
    min_y_pos_            = config.getValue("min_y_pos");
    max_y_pos_            = config.getValue("max_y_pos");
    min_velocity_x_       = config.getValue("min_velocity_x");
    max_velocity_x_       = config.getValue("max_velocity_x");
    min_velocity_y_       = config.getValue("min_velocity_y");
    max_velocity_y_       = config.getValue("max_velocity_y");
    min_acceleration_x_   = config.getValue("min_acceleration_x");
    max_acceleration_x_   = config.getValue("max_acceleration_x");
    min_acceleration_y_   = config.getValue("min_acceleration_y");
    max_acceleration_y_   = config.getValue("max_acceleration_y");
    min_rotate_velocity_  = config.getValue("min_rotate_velocity");
    max_rotate_velocity_  = config.getValue("max_rotate_velocity");
    min_width_            = config.getValue("min_width");
    max_width_            = config.getValue("max_width");
    min_width_change_     = config.getValue("min_width_change");
    max_width_change_     = config.getValue("max_width_change");
    min_height_           = config.getValue("min_height");
    max_height_           = config.getValue("max_height");
    min_height_change_    = config.getValue("min_height_change");
    max_height_change_    = config.getValue("max_height_change");
    std::string image_filename = config.getValue("image_filename");

    image_.load(image_filename);
    loop_ = 1;

    prePump();
}

Particle Emitter::emit()
{
    // initialise a particle using the info from the emitter
    Particle current_particle;

    current_particle.texture = image_.getTexture();

    current_particle.life_length = getRandRangei(min_life_length_, max_life_length_);

    current_particle.x = getRandRangef(min_x_pos_, max_x_pos_);
    current_particle.y = getRandRangef(min_y_pos_, max_y_pos_);

    current_particle.velocity_x = getRandRangef(min_velocity_x_, max_velocity_x_);
    current_particle.velocity_y = getRandRangef(min_velocity_y_, max_velocity_y_);

    current_particle.acceleration_x = getRandRangef(min_acceleration_x_, max_acceleration_x_);
    current_particle.acceleration_y = getRandRangef(min_acceleration_y_, max_acceleration_y_);

    current_particle.rotate          = 0.0f;
    current_particle.rotate_velocity = getRandRangef(min_rotate_velocity_, max_rotate_velocity_);

    current_particle.width        = getRandRangef(min_width_, max_width_);
    current_particle.width_change = getRandRangef(min_width_change_, max_width_change_);

    current_particle.height        = getRandRangef(min_height_, max_height_);
    current_particle.height_change = getRandRangef(min_height_change_, max_height_change_);

    return current_particle;
}

void Emitter::update()
{
    // if it's time to emit particles
    if(loop_%spawn_rate_==0)
    {
        // emit particles_per_spawn number of particles
        for(unsigned int particle_number = 0; particle_number < particles_per_spawn_; ++particle_number)
        {
            particles_.push_back(this->emit());
        }
    }

    // update the position of all the particles
    //TODO: This should be done only for particles that are visible on the screen
    for(std::vector<Particle>::iterator current_particle = particles_.begin();
    current_particle < particles_.end(); ++current_particle)
    {
        current_particle->update();

        // remove dead particles
        if(current_particle->life_length < 0)
        {
            particles_.erase(current_particle);
        }
    }
    ++loop_;

    // reset loop
    if(loop_==1001)
        loop_ = 1;

}

void Emitter::draw()
{
    for(std::vector<Particle>::iterator current_particle = particles_.begin();
    current_particle != particles_.end(); ++current_particle)
    {
        current_particle->draw();
    }
}
