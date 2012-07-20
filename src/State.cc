/*---------------------------------------
 * State.cc
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "Animation.hh"
#include "State.hh"
/*--------------------------------------*/

void Objects::State::setAnimation(Animation new_animation)
{
    animation = new_animation;
}

Animation& Objects::State::getAnimation()
{
    Animation& animation_reference = animation;
    return animation_reference;
}
