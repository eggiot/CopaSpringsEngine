/*---------------------------------------
 * GameObject.h
 *
 *  Created on: 27 Sep 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#include "GameObject.h"
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
    Component::component_id_t id = new_component->family_id_;
    new_component->setOwnerObject(this);
    components_[id] = new_component;
}
void GameObject::clearComponents()
{
    for(component_table_t::iterator component = components_.begin();
        component != components_.end(); ++component)
    {
        delete component->second;
        std::cout << component->second << std::endl;
        component->second = NULL;
        std::cout << component->second << std::endl;
        components_.erase(component);
    }
    components_.clear();
}

Component::Component(Component::component_id_t family_id)
{
    family_id_ = family_id;
}

void Component::setOwnerObject(GameObject* game_object)
{
    owner_object_ = game_object;
}

GameObject* Component::getOwnerObject()
{
    return owner_object_;
}
