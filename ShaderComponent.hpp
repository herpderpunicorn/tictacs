#ifndef SHADERCOMPONENT_HPP_INCLUDED
#define SHADERCOMPONENT_HPP_INCLUDED

#include <memory>
#include <SFML/Graphics/Shader.hpp>
#include "Component.hpp"
#include "Entity.hpp"

class ShaderComponent : public Component {
public:
    ShaderComponent();
    virtual ~ShaderComponent();

    virtual void update(int32_t deltaTime) override;

    void setShader(sf::Shader* shader);
    const sf::Shader& getShader() const;

    /**
     * Set lambda to run in update(int32_t).
     *
     * int32_t is delta time.
     * Entity* is the owner of this component.
     * sf::Shader& is the shader of this component.
     */
    void setOnUpdate(std::function<void (int32_t, Entity*, sf::Shader&)> onUpdate);

private:
    std::function<void (int32_t, Entity*, sf::Shader&)> mOnUpdate;
    std::unique_ptr<sf::Shader> mShader;
};

#endif
