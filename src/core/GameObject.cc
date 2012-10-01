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

void GameObject::setQuad(const Graphics::Quad& quad)
{
    quad_ = quad;
}

const GameObject::gameobject_id_t& GameObject::getID()
{
    return id_;
}

void GameObject::setID(const GameObject::gameobject_id_t& id)
{
    id_ = id;
}

boost::shared_ptr<Component> GameObject::getComponent(const Component::component_id_t& family_id)
{
    component_table_t::iterator component = components_.find(family_id);
    if(component == components_.end())
    {
        boost::shared_ptr<Component> null_component;
        return null_component;
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
    components_[id] = boost::shared_ptr<Component> (new_component);
}
void GameObject::clearComponents()
{
    components_.clear();
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
