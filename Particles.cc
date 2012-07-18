/*
 * Particles.cc
 *
 *  Created on: 23 Aug 2011
 *      Author: Eliot J. Walker
 */

// include engine headers
#include "Graphics.hh"
#include "Sprites.hh"
#include "Particles.hh"

// include graphics headers
#include <GL/gl.h>

// include standard library headers
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <iostream>

/*----------------------- EMITTER ---------------------------*/

Emitter::Emitter(GLuint texture,
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
    this->min_life_length = min_life_length;
    this->max_life_length = max_life_length;
    this->min_x_pos = min_x_pos;
    this->max_x_pos = max_x_pos;
    this->min_y_pos = min_y_pos;
    this->max_y_pos = max_y_pos;
    this->min_velocity_x = min_velocity_x;
    this->max_velocity_x = max_velocity_x;
    this->min_velocity_y = min_velocity_y;
    this->max_velocity_y = max_velocity_y;
    this->min_acceleration_x = min_acceleration_x;
    this->max_acceleration_x = max_acceleration_x;
    this->min_acceleration_y = min_acceleration_y;
    this->max_acceleration_y = max_acceleration_y;
    this->min_rotate_velocity = min_rotate_velocity;
    this->max_rotate_velocity = max_rotate_velocity;
    this->min_width = min_width;
    this->max_width = max_width;
    this->min_width_change = min_width_change;
    this->max_width_change = max_width_change;
    this->min_height = min_height;
    this->max_height = max_height;
    this->min_height_change = min_height_change;
    this->max_height_change = max_height_change;
}

// TODO: Load an emitter from a file
Emitter::Emitter(std::string filename)
{
}

Particle& Emitter::emit()
{
    // initialise a particle using the info from the emitter
    Particle current_particle;

    current_particle.texture = texture;
    current_particle.life_length = getRandRangei(min_life_length, max_life_length);
    current_particle.x = getRandRangef(min_x_pos, max_x_pos);
    current_particle.y = getRandRangef(min_y_pos, max_y_pos);
    current_particle.velocity_x = getRandRangef(min_velocity_x, max_velocity_x);
    current_particle.velocity_y = getRandRangef(min_velocity_y, max_velocity_y);

    current_particle.acceleration_x = getRandRangef(min_acceleration_x, max_acceleration_x);
    current_particle.acceleration_y = getRandRangef(min_acceleration_y, max_acceleration_y);

    current_particle.rotate = 0.0f;
    current_particle.rotate_velocity = getRandRangef(min_rotate_velocity, max_rotate_velocity);

    current_particle.width = getRandRangef(min_width, max_width);
    current_particle.width_change = getRandRangef(min_width_change, max_width_change);

    current_particle.height = getRandRangef(min_height, max_height);
    current_particle.height_change = getRandRangef(min_height_change, max_height_change);

    // get a reference to the particle
    Particle& current_particle_ref = current_particle;
    return current_particle_ref;
}

/*----------------------- PARTICLESYSTEM ---------------------------*/

// Constructor
ParticleSystem::ParticleSystem()
{
    loop = 1;
}

// Update the positions of the particles, drawing them if bool==true
void ParticleSystem::update()
{
    // emit any particles that need to be emitted
    for(unsigned int i = 0; i<emitters.size(); ++i)
    {
        Emitter& current_emitter = emitters[i];
        if(loop%current_emitter.spawn_rate==0)
        {
            for (unsigned int particle_number = 0; particle_number < current_emitter.particles_per_spawn; ++particle_number)
            {
                Particle current_particle = current_emitter.emit();
                particles.push_back(current_particle);
            }
        }
    }

    // update the position of all the particles
    //TODO: This should be done only for particles that are visible on the screen
    for(std::vector<Particle>::iterator current_particle = particles.begin();
    current_particle < particles.end(); ++current_particle)
    {
        //update particle
        // move the particle through its velocity
        current_particle->x += current_particle->velocity_x;
        current_particle->y += current_particle->velocity_y;

        // reduce its life length
        current_particle->life_length -= 1;

        // accelerate / decelerate the particle
        current_particle->velocity_x += current_particle->acceleration_x;
        current_particle->velocity_y += current_particle->acceleration_y;

        // rotate and resize
        current_particle->rotate += current_particle->rotate_velocity;
        current_particle->width += current_particle->width_change;
        current_particle->height += current_particle->height_change;

        if(current_particle->life_length < 0)
        {
            particles.erase(current_particle);
        }
    }
    loop += 1;

    // reset loop
    if(loop==1001)
        loop = 1;
}

void ParticleSystem::draw()
{
    for(std::vector<Particle>::iterator current_particle = particles.begin();
    current_particle != particles.end(); ++current_particle)
    {
        Graphics::Utils::drawTexturedQuad(current_particle->texture,
                                          current_particle->x,
                                          current_particle->y,
                                          current_particle->width,
                                          current_particle->height);
    }
}

void ParticleSystem::addEmitter(Emitter& emitter)
{
    // preemptively pump a number of cycles so it looks as though the emitters been running for some time
    for(int cycle = 0; cycle < emitter.pre_pump_cycles; ++cycle)
    {
        particles.push_back(emitter.emit());
    }
    emitters.push_back(emitter);
}
