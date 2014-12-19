#include "ShaderComponent.hpp"

ShaderComponent::ShaderComponent() {

}

ShaderComponent::~ShaderComponent() {

}

void ShaderComponent::update(int32_t deltaTime) {
    if (mOnUpdate) {
        mOnUpdate(deltaTime, mOwner, *mShader);
    }
}

void ShaderComponent::setShader(sf::Shader* shader) {
    mShader = std::unique_ptr<sf::Shader>(shader);
}

const sf::Shader& ShaderComponent::getShader() const {
    return *mShader;
}

void ShaderComponent::setOnUpdate(std::function<void (int32_t, Entity*, sf::Shader&)> onUpdate) {
    mOnUpdate = onUpdate;
}
