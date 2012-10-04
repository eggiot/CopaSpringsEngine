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
    boost::shared_ptr<GameObject> owner_object_;
public:
    typedef std::string component_id_t;
    Component() {}// : owner_object_(NULL) {}
    Component(component_id_t family_id);
    virtual ~Component() {}

    // a unique id referring to this component instance
    component_id_t component_id;
    
    /* an id referring to the type of this component
       (e.g. render_component, ai_component, etc.).
       Each GameObject can only have one component
       from each family. */
    component_id_t family_id;

    /* the update function is internal (i.e. it only
       updates this component. */
    virtual void update() {}

    /* the run() function is external. It updates things
       outside of this component (the owner object,
       OpenGL buffers, etc.) */
    virtual void run() {}

    // assignment functions
    void setOwnerObject(boost::shared_ptr<GameObject> game_object);
    
    // query functions
    boost::shared_ptr<GameObject> getOwnerObject();
};

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
    
    void update();
    void run();
    
    // remove all the GameObject's components
    void clearComponents();

    // assignment functions
    void setID(const gameobject_id_t& id);
    void setComponent(Component* new_component);
    void setTransform(float x, float y,
                      float width, float height,
                      float rotation);

    // query functions
    // TODO: Quads should only contain position and width data and should be renamed to Transforms
    const Graphics::Quad& getQuad();
    const gameobject_id_t& getID();
    Component* getComponent(const Component::component_id_t& family_id);
    boost::shared_ptr<GameObject> shared_this_;
protected:
    Graphics::Quad quad_;
    component_table_t components_;
    
};

/*---------------------------------------*/
#endif /*GAMEOBJECT_H*/
