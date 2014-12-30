#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent() {
}

SpriteComponent::~SpriteComponent() {
}

void SpriteComponent::update(int32_t deltaTime) {
}

void SpriteComponent::setSprite(const sf::Sprite& sprite) {
    mSprite = sprite;
}

const sf::Sprite& SpriteComponent::getSprite() const {
    return mSprite;
}
