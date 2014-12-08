#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "SpriteComponent.hpp"
#include "ShapeComponent.hpp"
#include "ShaderComponent.hpp"

int main(int argc, char *argv[]) {
    std::string title("tictacs ");
    title += std::to_string(tictacs_VERSION_MAJOR) += std::string(".") += std::to_string(tictacs_VERSION_MINOR);
    if (tictacs_VERSION_REVISION != nullptr) {
        title += std::string(" ") += tictacs_VERSION_REVISION;
    }
    if (tictacs_VERSION_BRANCH != nullptr) {
        title += std::string(" branch: ") += tictacs_VERSION_BRANCH;
    }

    sf::Clock clock;

    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), title);

    Entity entity;
    entity.attachComponent(new SpriteComponent());
    sf::Texture texture;
    texture.loadFromFile("./res/noct.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    entity.getComponent<SpriteComponent>()->setSprite(sprite);

    entity.attachComponent(new ShapeComponent());
    sf::CircleShape* shape = new sf::CircleShape(50);
    shape->setFillColor(sf::Color::Green);
    entity.getComponent<ShapeComponent>()->setShape(shape);

    entity.attachComponent(new ShaderComponent());
    sf::Shader* shader = new sf::Shader();
    shader->loadFromMemory(R"(
uniform float wave_phase;
uniform vec2 wave_amplitude;

void main()
{
    vec4 vertex = gl_Vertex;
    vertex.x += cos(gl_Vertex.y * 0.02 + wave_phase * 3.8) * wave_amplitude.x
              + sin(gl_Vertex.y * 0.02 + wave_phase * 6.3) * wave_amplitude.x * 0.3;
    vertex.y += sin(gl_Vertex.x * 0.02 + wave_phase * 2.4) * wave_amplitude.y
              + cos(gl_Vertex.x * 0.02 + wave_phase * 5.2) * wave_amplitude.y * 0.3;

	gl_Position = gl_ModelViewProjectionMatrix * vertex;
	gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;
	gl_FrontColor = gl_Color;
}
)", sf::Shader::Vertex);
    ShaderComponent* sc = entity.getComponent<ShaderComponent>();
    sc->setShader(shader);
    sc->setOnUpdate([&renderWindow](int32_t deltaTime, Entity* owner, sf::Shader& shader){
        float x = static_cast<float>(sf::Mouse::getPosition(renderWindow).x) / renderWindow.getSize().x;
        float y = static_cast<float>(sf::Mouse::getPosition(renderWindow).y) / renderWindow.getSize().y;
        shader.setParameter("wave_phase", deltaTime*1000.f);
        shader.setParameter("wave_amplitude", x * 40, y * 40);
    });


    while (renderWindow.isOpen()) {
        clock.restart();
        sf::Event Event;
        while (renderWindow.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                renderWindow.close();
        }
        renderWindow.clear();
        entity.update(clock.getElapsedTime().asMilliseconds());
        renderWindow.draw(entity.getComponent<SpriteComponent>()->getSprite(), &entity.getComponent<ShaderComponent>()->getShader());
        renderWindow.draw(entity.getComponent<ShapeComponent>()->getShape());
        renderWindow.display();
    }
    return EXIT_SUCCESS;
}

