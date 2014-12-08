#ifndef SHAPECOMPONENT_HPP_INCLUDED
#define SHAPECOMPONENT_HPP_INCLUDED

#include <memory>
#include <SFML/Graphics/Shape.hpp>
#include "Component.hpp"
#include "Entity.hpp"

class ShapeComponent : public Component {
public:
    ShapeComponent();
    virtual ~ShapeComponent();

    virtual void init(Entity* owner) override;
    virtual void update(int32_t deltaTime) override;

    void setShape(sf::Shape* shape);
    const sf::Shape& getShape() const;

protected:
    std::unique_ptr<sf::Shape> mShape;
};

#endif
