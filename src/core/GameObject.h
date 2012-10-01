/*---------------------------------------
 * GameObject.h
 *
 *  Created on: 27 Sep 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
/*---------------------------------------*/
#include "../graphics/Graphics.h"
/*---------------------------------------*/
#include <string>
#include <map>
#include <iostream>
#include <boost/shared_ptr.hpp>
/*---------------------------------------*/

class GameObject;

class Component
{
protected:
    boost::shared_ptr<GameObject> owner_object_;
public:
    typedef std::string component_id_t;
    Component() {}// : owner_object_(NULL) {}
    Component(component_id_t family_id);
    virtual ~Component() {}

    component_id_t component_id;
    component_id_t family_id;

    virtual void update() {}

    void setOwnerObject(boost::shared_ptr<GameObject> game_object);
    boost::shared_ptr<GameObject> getOwnerObject();
};

//TODO: Possibly replace the map of boost::shared_ptr<T>s with a
// boost::ptr_multimap - this would be more efficient
class GameObject
{
public:
    typedef std::string gameobject_id_t;
    typedef std::map< Component::component_id_t, boost::shared_ptr<Component> > component_table_t;
    GameObject(const gameobject_id_t& id);
    gameobject_id_t id_;
    const Graphics::Quad& getQuad();
    void setQuad(const Graphics::Quad& quad);
    const gameobject_id_t& getID();
    void setID(const gameobject_id_t& id);
    boost::shared_ptr<Component> getComponent(const Component::component_id_t& family_id);
    void setComponent(Component* new_component);
    void clearComponents();
protected:
    Graphics::Quad quad_;
    component_table_t components_;
};

/*---------------------------------------*/
#endif /*GAMEOBJECT_H*/
