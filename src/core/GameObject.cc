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
    id_ = id;
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

void GameObject::setComponent(Component* new_component)
{
    Component::component_id_t id = new_component->family_id;
    new_component->setOwnerObject(boost::shared_ptr<GameObject>(this));
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
    owner_object_ = game_object;
}

boost::shared_ptr<GameObject> Component::getOwnerObject()
{
    return owner_object_;
}
