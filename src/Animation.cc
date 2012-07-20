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
/*----------------------- ANIMATIONFRAME ---------------------------*/
AnimationFrame::AnimationFrame(std::string image_filename, unsigned int engine_loops, bool flip_horizontal, bool flip_vertical)
{
    num_engine_loops = engine_loops;
    elapsed_engine_loops = 0;
    // loading the image and texture
    image.load(image_filename, flip_horizontal, flip_vertical);
}

void AnimationFrame::draw(float x, float y, float width, float height)
{
    // draw the frame
    Graphics::drawTexturedQuad(image.getTexture(), x, y, width, height);

    // this AnimationFrame has now been drawn for one more engine loop, so
    // increment the number of elapsed engine loops
    elapsed_engine_loops += 1;
}

void AnimationFrame::resetLoops()
{
    // set elapsed loops to 0, thus resetting the frame for future drawing
    elapsed_engine_loops = 0;
}

bool AnimationFrame::checkIfOver()
{
    // has the frame been displayed for the specified length of time?
    return elapsed_engine_loops > num_engine_loops;
}

/*----------------------- ANIMATION ---------------------------*/

void Animation::addFrame(AnimationFrame frame)
{
    // push a frame onto the rendering queue
    blit_queue.push(frame);
}

bool Animation::load(std::string filename, bool loop)
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
        this->addFrame(AnimationFrame(image_path, num_engine_loops, false, false)); //TODO: temporarily prevents flipping
    }
    fclose(file);

    return true;
}

void Animation::draw(float x, float y, float width, float height)
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

void Animation::reload()
{
    // load the animation from file - for testing purposes only
    load(anim_filename, loopable);
}
