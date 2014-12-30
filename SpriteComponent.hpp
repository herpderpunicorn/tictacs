#ifndef SPRITECOMPONENT_HPP_INCLUDED
#define SPRITECOMPONENT_HPP_INCLUDED

#include <SFML/Graphics/Sprite.hpp>
#include "Component.hpp"
#include "Entity.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent();
    virtual ~SpriteComponent();

    void update(int32_t deltaTime) override;

    void setSprite(const sf::Sprite& sprite);
    const sf::Sprite& getSprite() const;

protected:
    sf::Sprite mSprite;
};

#endif
