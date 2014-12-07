#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "SpriteComponent.hpp"

int main(int argc, char *argv[]) {
    std::string title("tictacs ");
    title += std::to_string(tictacs_VERSION_MAJOR) += std::string(".") += std::to_string(tictacs_VERSION_MINOR);
    if (tictacs_VERSION_REVISION != nullptr) {
        title += std::string(" ") += tictacs_VERSION_REVISION;
    }
    if (tictacs_VERSION_BRANCH != nullptr) {
        title += std::string(" branch: ") += tictacs_VERSION_BRANCH;
    }

    Entity entity;
    entity.attachComponent(new SpriteComponent());
    sf::Texture texture;
    texture.loadFromFile("./res/noct.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    entity.getComponent<SpriteComponent>()->setSprite(sprite);

    sf::Clock clock;

    sf::RenderWindow renderWindow(sf::VideoMode(800, 600), title);
    while (renderWindow.isOpen()) {
        clock.restart();
        sf::Event Event;
        while (renderWindow.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                renderWindow.close();
        }
        renderWindow.clear();
        entity.update(clock.getElapsedTime().asMilliseconds());
        renderWindow.draw(entity.getComponent<SpriteComponent>()->getSprite());
        renderWindow.display();
    }
    return EXIT_SUCCESS;
}

