/*---------------------------------------
 * Animation.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Image.hh"
#include "Graphics.hh"
#include "Animation.hh"
/*--------------------------------------*/
#include <GL/gl.h>
/*--------------------------------------*/
#include <queue>
#include <iostream>
#include <string>
#include <stdio.h>
/*--------------------------------------*/

/*! \brief AnimationFrame constructor

The constructor for the AnimationFrame class.

\param image_filename The path to the frame's image.
\param engine_loops The number of loops for which the frame will be displayed. */

Graphics::AnimationFrame::AnimationFrame(std::string image_filename, unsigned int engine_loops, bool flip_horizontal, bool flip_vertical)
{
    num_engine_loops = engine_loops;
    elapsed_engine_loops = 0;

    // loading the image and texture
    image.load(image_filename, flip_horizontal, flip_vertical);
    texture = Graphics::Utils::loadTexture(image);
}

/*! \brief Draw the AnimationFrame to the screen

Draws the frame to the screen so that the bottom-left corner of the frame
is positioned at coordinate (x, y).

\param x X-coordinate of the frame.
\param y Y-coordinate of the frame.
\param width Width of the frame.
\param height Height of the frame. */

void Graphics::AnimationFrame::draw(float x, float y, float width, float height)
{
    // draw the frame
    Graphics::Utils::drawTexturedQuad(texture, x, y, width, height);

    // this AnimationFrame has now been drawn for one more engine loop, so
    // increment the number of elapsed engine loops
    elapsed_engine_loops += 1;
}

/*! \brief Reset the engine loops

Sets elapsed_engine_loops to 0, in effect resetting the frame. */

void Graphics::AnimationFrame::resetLoops()
{
    // set elapsed loops to 0, thus resetting the frame for future drawing
    elapsed_engine_loops = 0;
}

/*! \brief Check if the frame has finished being displayed

Checks if the number of elapsed engine loops exceeds the specified total
number of engine loops.
\return Whether elapsed_engine_loops > num_engine_loops. */

bool Graphics::AnimationFrame::checkIfOver()
{
    // has the frame been displayed for the specified length of time?
    return elapsed_engine_loops > num_engine_loops;
}

/*! \brief Add a frame to the animation

Pushes a frame onto the end of the blit queue.

\param frame The AnimationFrame to add to the animation. */

void Graphics::Animation::addFrame(Graphics::AnimationFrame frame)
{
    // push a frame onto the rendering queue
    blit_queue.push(frame);
}

/*! \brief Load an animation from a file - testing.

Loads an animation from a file where each line uses the
format:

path/to/image/file.png number_of_engine_loops.

This function is to only be used for testing. In a production
game, animations will be loaded from the level XML file.

\param filename Path to the animation file
\param loop Is the animation to be looped or played through once from
beginning to end?

\return Whether the file was successfully loaded.*/

bool Graphics::Animation::load(std::string filename, bool loop)
{
    loopable = loop;
    anim_filename = filename;

    FILE *file; // file to load
    char image_path[30]; // path to image
    char buffer[256]; // string buffer
    unsigned int num_engine_loops; // length of frame
    unsigned int flip_horizontal;
    unsigned int flip_vertical;

    // can't open the file
    if (!(file = fopen(filename.c_str(), "r")))
    {
        std::cerr << "Can't open file " << filename << " for reading" << std::endl;
        return false;
    }

    // can open the file
    // while the currently-read line does not equal the NULL terminator
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // get info about the frame
        sscanf(buffer, "%s %i %i %i\n", image_path, &num_engine_loops, &flip_horizontal, &flip_vertical);

        // create a frame from this information and add it to the blit queue
        blit_queue.push(Graphics::AnimationFrame(image_path, num_engine_loops, flip_horizontal==1, flip_vertical==1)); //TODO: temporarily prevents flipping
    }
    fclose(file);

    return true;
}



/*! \brief Draw the current frame of the animation to the screen

Draws the frame at the front of the blit queue to the screen so that the
bottom left corner of the frame is positioned at coordinates (x, y).

The frame is removed from the blit queue if it is over. If the animation is loopable
the frame is then pushed back into the queue.

If the size of the blit queue is 1 this sole frame is never removed from the
animation.

\param x X-coordinate of the frame.
\param y Y-coordinate of the frame.
\param width Width of the frame.
\param height Height of the frame. */

void Graphics::Animation::draw(float x, float y, float width, float height)
{
    // display the first frame in the blit queue
    blit_queue.front().draw(x, y, width, height);

    // if it's time for the next frame
    if(blit_queue.front().checkIfOver())
    {
        // if the animation is to be looped
        if(loopable)
        {
              //Add the current frame to the back of the blit queue
              blit_queue.push(blit_queue.front());
              blit_queue.back().resetLoops();
        }

        // if this isn't the last frame left in the blit queue
        if(blit_queue.size() > 1)
        {
            // remove the elapsed frame from the blit_queue
            blit_queue.pop();
        }
    }
}

/*! \brief Reloads the animation.

This function reloads the animation.

This is currently necessary after every change in state.
After changing states, the new state uses the current blit queue in its corresponding animation.
If this animation has already been played, the state of the blit queue has changed. If the animation
is loopable the first frame in the animation may not be the frame that the designer specified as being
first. If the animation is not loopable this effect is even more problematic. This is because there will,
in all probability, only be one frame remaining in the blit queue. As such, any subsequent uses of that
animation will consist of only that one frame. Thus, the animation needs to be reloaded to refresh the
blit queue.

At the moment, this is simply done by reloading the animation from the file. However, loading an animation
from file is to only be used for testing. It is also terribly inefficient. As such, I will have to devise a
new method of keeping track of the correct state of the blit queue. The probable solution to this problem
will be to have a tmp_blit_queue and a constant_blit_queue. Changes will only be applied to the
tmp_blit_queue and, after a change in state, it will restore itself to its original state using the
constant_blit_queue. However, attempts to implement this have, thus far, been unsuccessful. */

void Graphics::Animation::reload()
{
    // load the animation from file - for testing purposes only
    load(anim_filename, loopable);
}
