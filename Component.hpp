#ifndef COMPONENT_HPP_INCLUDED
#define COMPONENT_HPP_INCLUDED

#include <string>
#include <memory>

class Entity;

/**
 * Abstract base class for components.
 */
class Component {
public:
    virtual ~Component() = default;

    /**
     * Initialises the component.
     * @param owner The owner of the component.
     *
     * NOTE: The component is not responsible for the lifetime of owner. The owner must be valid as long as the Component exists.
     */
    virtual void init(Entity* owner) {
        mOwner = owner;
    };

    virtual void update(int32_t deltaTime) = 0;

protected:
    Entity* mOwner;
};

#endif
