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
#include <boost/ptr_container/ptr_map.hpp>
/*---------------------------------------*/

// forward declaration of GameObject
class GameObject;

/* a component is a (theoretically) self-contained unit that provides some sort of
   functionality when added to a game object (e.g. physics / renderer / input components */
class Component
{
protected:
	// a shared pointer to the GameObject that owns the component
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
	// declare types
    typedef std::string gameobject_id_t;
    typedef boost::ptr_map< Component::component_id_t, Component> component_table_t;

    // constructor
    GameObject(const gameobject_id_t& id);

    // the object's unique id
    gameobject_id_t id_;

    // get the quad for graphics
    // TODO: Quads should only contain position and width data and should be renamed to Transforms
    const Graphics::Quad& getQuad();
    void setQuad(const Graphics::Quad& quad);

    // get the id
    const gameobject_id_t& getID();
    void setID(const gameobject_id_t& id);
    Component* getComponent(const Component::component_id_t& family_id);
    void setComponent(Component* new_component);
    void clearComponents();
protected:
    Graphics::Quad quad_;
    component_table_t components_;
};

/*---------------------------------------*/
#endif /*GAMEOBJECT_H*/
