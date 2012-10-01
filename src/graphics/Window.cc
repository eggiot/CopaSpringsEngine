/*---------------------------------------
 * Window.cc
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Window.h"
#include "Graphics.h"
/*--------------------------------------*/
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/

/*! \brief Window constructor

The constructor for the Window class.

\param width The width of the window in pixels
\param height The height of the window in pixels.
\param title The title to display in the window's title bar. */

Window::Window(int width, int height, std::string title)
{
    this->init(width, height, title);
}

void Window::init(int width, int height, std::string title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    fullscreen_ = false;
    screen_ = SDL_SetVideoMode( width, height, 32, SDL_OPENGL | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    SDL_WM_SetCaption(title.c_str(), NULL); // TODO: Enable icons (currently NULL)
    width_ = width;
    height_ = height;
}

void Window::initGraphics(float viewport_width, float viewport_height)
{
    viewport_width_ = viewport_width;
    viewport_height_ = viewport_height;
    Graphics::initGL(width_, height_, viewport_width_, viewport_height_);

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

\param width The width in pixels of the resized window.
\param height The height in pixels of the resized window. */

void Window::resize(int width, int height)
{
    width_ = width;
    height_ = height;
    screen_ = SDL_SetVideoMode(width_, height_, 32, SDL_OPENGL | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    //glViewport(0, 0, new_width, new_height);
    Graphics::initGL(width_, height_, viewport_width_, viewport_height_);
}
