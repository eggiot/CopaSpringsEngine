/*
 * Window.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 */

// include engine headers
#include "Window.hh"
#include "Graphics.hh"

// include graphics headers
#include <SDL/SDL.h>
#include <GL/gl.h>

// include standard library headers
#include <string>

/*! \brief Window constructor

The constructor for the Window class.

\param width The width of the window in pixels
\param height The height of the window in pixels.
\param title The title to display in the window's title bar. */

Window::Window(int width, int height, std::string title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode( width, height, 32, SDL_OPENGL | SDL_HWSURFACE);
    SDL_WM_SetCaption(title.c_str(), NULL); // TODO: Enable icons (currently NULL)
    Graphics::Utils::initGL(width, height);

    // set SDL OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
}

/*! \brief Pause computation

Causes the window to sleep, thus preventing the window from updating the display.

\param msecs The number of milliseconds to make the window sleep. */

void Window::sleep(int msecs)
{
    SDL_Delay(msecs);
}

/*! \brief Resize the window

Changes the size of the window.

Currently, this function makes the display black as it removes all textures. The engile
will have to reload all the textures and redisplay them whenever the window is resized.
First I'll have to create the engine!!

\param new_width The width in pixels of the resized window.
\param new_height The height in pixels of the resized window. */

void Window::resize(int new_width, int new_height)
{
    // prevent window from being too small
    if(new_width < 100)
    {
        new_width = 100;
    }
    if(new_height < 100)
    {
        new_height = 100;
    }

    screen = SDL_SetVideoMode(new_width, new_height, 32, SDL_OPENGL | SDL_HWSURFACE);
    glClear(GL_COLOR_BUFFER_BIT);

}
