/*---------------------------------------
 * Window.h
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef WINDOW_H
#define WINDOW_H
/*--------------------------------------*/
#include <SDL/SDL.h>
/*--------------------------------------*/
#include <string>
/*--------------------------------------*/

/*! \class Window Window.h "Window.h"
 \brief A generic window

 A generic window class that acts much as a wrapper for SDL's windowing system. */

class Window
{
protected:
    //! The SDL surface on which everything will be displayed
    SDL_Surface* screen_;
    bool fullscreen_;

public:
    Window(int width, int height, std::string title,
           float viewport_width, float viewport_height);
    void sleep(int msecs);
    void resize(int width, int height);
};

/*--------------------------------------*/
#endif /*WINDOW.h*/
