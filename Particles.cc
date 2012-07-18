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

Objects::Particles::Particle& Objects::Particles::Emitter::emit()
{
    // initialise a particle using the info from the emitter
    Objects::Particles::Particle current_particle;

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
    Objects::Particles::Particle& current_particle_ref = current_particle;
    return current_particle_ref;
}

Objects::Particles::ParticleSystem::ParticleSystem()
{
    loop = 1;
}

void Objects::Particles::ParticleSystem::update(bool draw)
{
    // emit any particles that need to be emitted
    for(unsigned int i = 0; i<emitters.size(); ++i)
    {
        Objects::Particles::Emitter& current_emitter = emitters[i];
        if(loop%current_emitter.spawn_rate==0)
        {
            for (unsigned int particle_number = 0; particle_number < current_emitter.particles_per_spawn; ++particle_number)
            {
                Objects::Particles::Particle current_particle = current_emitter.emit();
                particles.push_back(current_particle);
            }
        }
    }

    // update the position of all the particles
    //TODO: This should be done only for particles that are visible on the screen
    for(unsigned int i = 0; i<particles.size(); ++i)
    {
        Objects::Particles::Particle& current_particle_ref = particles[i];

        if(draw)
        {
            Graphics::Utils::drawTexturedQuad(current_particle_ref.texture,
                                              current_particle_ref.x,
                                              current_particle_ref.y,
                                              current_particle_ref.width,
                                              current_particle_ref.height);
        }

        //update particle
        // move the particle through its velocity
        current_particle_ref.x += current_particle_ref.velocity_x;
        current_particle_ref.y += current_particle_ref.velocity_y;

        // reduce its life length
        current_particle_ref.life_length -= 1;

        // accelerate / decelerate the particle
        current_particle_ref.velocity_x += current_particle_ref.acceleration_x;
        current_particle_ref.velocity_y += current_particle_ref.acceleration_y;

        // rotate and resize
        current_particle_ref.rotate += current_particle_ref.rotate_velocity;
        current_particle_ref.width += current_particle_ref.width_change;
        current_particle_ref.height += current_particle_ref.height_change;

        if(current_particle_ref.life_length < 0)
        {
            particles.erase(particles.begin()+i);
        }
    }
    loop += 1;

    // reset loop
    if(loop==1001)
        loop = 1;
}

void Objects::Particles::ParticleSystem::addEmitter(Objects::Particles::Emitter& emitter)
{
    // preemptively pump a number of cycles so it looks as though the emitters been running for some time
    for(int cycle = 0; cycle < emitter.pre_pump_cycles; ++cycle)
    {
        particles.push_back(emitter.emit());
    }
    emitters.push_back(emitter);
}
