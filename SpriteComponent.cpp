#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent() {
    mType = SPRITE;
}

void SpriteComponent::init(Entity* owner) {
    Component::init(owner);
}

void SpriteComponent::update(int32_t deltaTime) {
}
