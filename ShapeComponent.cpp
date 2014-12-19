#include "ShapeComponent.hpp"

ShapeComponent::ShapeComponent() {

}

ShapeComponent::~ShapeComponent() {

}

void ShapeComponent::update(int32_t deltaTime) {

}

void ShapeComponent::setShape(sf::Shape* shape) {
    mShape = std::unique_ptr<sf::Shape>(shape);
}

const sf::Shape& ShapeComponent::getShape() const {
    return *mShape;
}
