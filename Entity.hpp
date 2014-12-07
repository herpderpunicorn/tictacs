#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include <vector>
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

    void attachComponent(Component component);
    const Component& getComponent(const Component::Type& type);
    void update(int32_t deltaTime);

protected:
    std::vector<Component> mComponents;
};

#endif
