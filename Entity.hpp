#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <vector>
#include <memory>
#include "Component.hpp"

class no_such_component : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Unable to find component";
    };
};

class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

    void attachComponent(Component* component);

    /**
     * Get a component of class T.
     *
     * @return The first component of type T.
     *
     * @throw no_such_component if the component could not be found.
     */
    template<class T> T* getComponent() {
        for(auto& component : mComponents) {
            if (typeid(T) == typeid(*component)) {
                return (T*) component.get();
            }
        }
        throw no_such_component();
    }

    /**
     * Update the entity.
     *
     * @param deltaTime Time since the last update, in milliseconds.
     */
    void update(int32_t deltaTime);

protected:
    std::vector<std::unique_ptr<Component>> mComponents;
};

#endif
