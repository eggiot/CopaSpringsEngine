/*
 * State.cc
 *
 *  Created on: 21 Aug 2011
 *      Author: Eliot J. Walker
 */

// include engine headers
#include "Animation.hh"

namespace Objects
{
class State
{
protected:
    Graphics::Animation animation;
public:
    void setAnimation(Graphics::Animation new_animation);
    Graphics::Animation& getAnimation();
};
}

void Objects::State::setAnimation(Graphics::Animation new_animation)
{
    animation = new_animation;
}

Graphics::Animation& Objects::State::getAnimation()
{
    Graphics::Animation& animation_reference = animation;
    return animation_reference;
}
