/*
 * Window.hh
 *
 *  Created on: 16 Aug 2011
 *      Author: Eliot J. Walker
 */

#ifndef WINDOW_HH
#define WINDOW_HH

// include graphics headers
#include <SDL/SDL.h>

// include standard library headers
#include <string>

namespace Graphics
{
class Window
{
    protected:
        SDL_Surface* screen;

    public:
        Window(int width, int height, std::string title);
        void sleep(int msecs);
        void resize(int width, int height);
};
}

#endif /*WINDOW.HH*/
