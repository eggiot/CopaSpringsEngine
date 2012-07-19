/*---------------------------------------
 * Animation.hh
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *
 *  Defines:
 *      AnimationFrame
 *      Animation
 *---------------------------------------*/
#ifndef ANIMATION_HH
#define ANIMATION_HH
/*--------------------------------------*/
#include "Image.hh"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/
#include <queue>
#include <string>
/*--------------------------------------*/

/*! \class AnimationFrame Animation.hh "Animation.hh"
 \brief An animation frame

 The AnimationFrame is the representation of a single displayable frame from an animation.
 A number of frames can be combined to produce a full animation. Each frame specifies the
 number of engine loops for which it is displayed. */

class AnimationFrame
{
protected:
    //! The number of engine loops for which this frame will be displayed.
    unsigned int num_engine_loops;

    //! The number of engine loops that have elapsed.
    unsigned int elapsed_engine_loops;

    //! the OpenGL texture ID associated with this frame.
    GLuint texture;

public:
    AnimationFrame(std::string image_filename, unsigned int engine_loops, bool flip_horizontal, bool flip_vertical);
    void draw(float x, float y, float width, float height);
    void resetLoops();
    bool checkIfOver();
};

/*! \class Animation Animation.hh "Animation.hh"
 * \brief An animation
 *
 * The Animation consists of a list of AnimationFrames in a queue which can
 * either be looped through continuously or played through once from beginning
 * to end.
*/

class Animation
{
protected:
    //! A queue of animation frames in chronological order
    std::queue<AnimationFrame> blit_queue;

    //! Is the animation to be looped or played through once?
    bool loopable;

    // A string containing the path to the animation file
    // TODO (eliot#2#): only temporary - animation loading will eventually be handled by the level loader
    std::string anim_filename;
public:
    void addFrame(AnimationFrame frame);
    bool load(std::string filename, bool loop);
    void draw(float x, float y, float width, float height);
    void reload();
};

/*--------------------------------------*/
#endif /*ANIMATION_HH*/
