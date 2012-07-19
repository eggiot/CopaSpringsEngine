/*
 * State.hh
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
 */

#ifndef STATE_HH
#define STATE_HH

// include engine headers
#include "Animation.hh"

namespace Objects
{
class State
{
protected:
    Animation animation;
public:
    void setAnimation(Animation new_animation);
    Animation& getAnimation();
};
}

#endif /*STATE_HH*/
