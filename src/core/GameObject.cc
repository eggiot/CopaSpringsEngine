/*---------------------------------------
 * GameObject.h
 *
 *  Created on: 27 Sep 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "GameObject.h"
#include <boost/shared_ptr.hpp>
/*---------------------------------------*/

GameObject::GameObject(const gameobject_id_t& id)
{
    /* I believe that this is causing a memory leak - try using
       enable_shared_from_this. Eventually, I shouldn't need
       shared pointers. A GameObject would belong to a resource
       manager which will be in complete control over
       the course of its lifetime. */
    
    shared_this_ = boost::shared_ptr<GameObject>(this);
    id_ = id;
}

GameObject::~GameObject()
{
    std::cout << "Destroying GameObject: " << this;
    //shared_this_.reset();
    this->clearComponents();
}


const Graphics::Quad& GameObject::getQuad()
{
    return quad_;
}

void GameObject::setTransform(float x, float y,
                              float width, float height,
                              float rotation)
{
    quad_.x = x; quad_.y = y;
    quad_.width = width; quad_.height = height;
    quad_.rotation = rotation;
}

const GameObject::gameobject_id_t& GameObject::getID()
{
    return id_;
}

void GameObject::setID(const GameObject::gameobject_id_t& id)
{
    id_ = id;
}

Component* GameObject::getComponent(const Component::component_id_t& family_id)
{
    component_table_t::iterator component = components_.find(family_id);
    if(component == components_.end())
    {
        return NULL;
    }
    else
    {
    	return component->second;
    }
}

void GameObject::addComponent(Component* new_component)
{
    Component::component_id_t id = new_component->family_id;
    new_component->setOwnerObject(shared_this_);
    components_.insert(id, new_component);
}

void GameObject::clearComponents()
{
    components_.clear();
}

void GameObject::update()
{
    for(component_table_t::iterator component = components_.begin();
        component != components_.end(); ++component)
    {
        component->second->update();
    }
}

void GameObject::run()
{
    for(component_table_t::iterator component = components_.begin();
        component != components_.end(); ++component)
    {
        component->second->run();
    }
}


Component::Component(Component::component_id_t family_id)
{
    this->family_id = family_id;
}

void Component::setOwnerObject(boost::shared_ptr<GameObject> game_object)
{
    std::cout << "Setting owner object: " << game_object.get() << std::endl;
    owner_object_ = game_object;
}

boost::shared_ptr<GameObject> Component::getOwnerObject()
{
    return owner_object_;
}
