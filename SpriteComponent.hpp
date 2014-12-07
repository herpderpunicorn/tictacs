#ifndef SPRITECOMPONENT_HPP_INCLUDED
#define SPRITECOMPONENT_HPP_INCLUDED

#include "Component.hpp"
#include "Entity.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent();
    virtual ~SpriteComponent() = default;

    void init(Entity* owner) override;
    void update(int32_t deltaTime) override;

protected:
};

#endif