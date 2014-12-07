#ifndef ICOMPONENT_HPP_INCLUDED
#define ICOMPONENT_HPP_INCLUDED

#include <string>
#include <memory>

class Entity;

class Component {
public:
    enum Type : int {
        SPRITE,
    };
    Component() = default;
    virtual ~Component() = default;

    /**
     * Initialises the component.
     * @param owner The owner of the component.
     *
     * NOTE: The component is not responsible for the lifetime of owner.
     */
    virtual void init(Entity* owner) {
        mOwner = owner;
    };

    virtual void update(int32_t deltaTime) {};

    bool isType(const Type& type) {
        return mType = type;
    };

protected:
    Entity* mOwner;
    Type mType;
};

#endif