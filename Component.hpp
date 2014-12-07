#ifndef ICOMPONENT_HPP_INCLUDED
#define ICOMPONENT_HPP_INCLUDED

#include <string>
#include <memory>

class Entity;

class Component {
public:
    enum Type : int {
        Sprite,
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
        return mType == type;
    };

    Type getType() const {
        return mType;
    };

protected:
    Entity* mOwner;
    Type mType;
};

#endif