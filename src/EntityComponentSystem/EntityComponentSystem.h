#ifndef ENTITYCOMPONENTSYSTEM_H
#define ENTITYCOMPONENTSYSTEM_H

//all the common library that we gonna use
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

//all the classes statement
class Component;
class Entity;

//our ID for the component is size_t
using ComponentID = std::size_t;

//@inline mean we just return back the attributes
//Check CoponentID
inline ComponentID getComponentTypeID()
{   
    //basiclly if we called for second time the id become 2
    //because static remember
    //0 -> 0u because ??
    static ComponentID lastID = 0;
    return lastID++;
}

//getComponentTypeID()
template <typename T> inline ComponentID getComponentTypeID() noexcept
{   
    //generate the ID that lastly generate
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;


//Inside component there is entity
class Component
{
    public:
        Entity* entity;

        virtual void init(){}
        virtual void update(){}
        virtual void draw(){}

        //abstract component deconstructor
        virtual ~Component(){}
    private:
};

class Entity
{
    public:
        //entity loop all through the components and update the functions
       void update()
       {
           for(auto& c : components) c->update();
           
       }

       void draw()
       {
           for(auto& c : components) c->draw();
       }
       
       //getter for active attributes
       bool isActive() const {return active;}

       //so if we destroy the entit
       //we make the entity inactive
       void destroy(){active = false;}

        //hasComponet() 
       template <typename T>bool hasComponent() const
       {
            return componentBitSet[getComponentTypeID<T>()];
       }

        //addComponent(T Arguments and M Arguments)
        template <typename T, typename... TArgs>T& addComponent(TArgs&&... mArgs)
        {
            T* c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            std::unique_ptr<Component> uPtr{ c };
            components.emplace_back(std::move(uPtr));

            componentArray[getComponentTypeID<T>()] = c;
            componentBitSet[getComponentTypeID<T>()] = true;

            c->init();
            return *c;
        }

        //getComponent()
        template<typename T> T& getComponent() const
        {
            auto ptr(componentArray[getComponentTypeID<T>()]);
            return *static_cast<T*>(ptr);
        }

        

    private:
        //if false we can remove it from the game
        bool active = true;

        //insert components inside vector called components
        std::vector<std::unique_ptr<Component>> components;

        ComponentArray componentArray;
        ComponentBitSet componentBitSet;
};

//manager class
class Manager
{
    public:
        //update all the entities
        void update()
        {
            for(auto& e : entities) e->update();
    
        }

        //render all the entites
        void draw()
        {
            for(auto& e : entities) e->draw();
        }

        //refresh all the entities
        void refresh()
        {   
            //remember entites is the vector
            //so this is basiclly a erase() functions remove the
            //entity if the entity is not active
            entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
            [](const std::unique_ptr<Entity> &mEntity)
            {
                return !mEntity->isActive();
            }),
            std::end(entities));
        }

        Entity& addEntity()
        {
            Entity* e = new Entity();
            std::unique_ptr<Entity> uPtr{ e };
            entities.emplace_back(std::move(uPtr));
            return *e;

        }
    private:
        //entities vector collects all the entity
        std::vector<std::unique_ptr<Entity>>entities;

};
#endif //ENTITYCOMPONENTSYSTEM_H