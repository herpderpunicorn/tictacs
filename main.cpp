#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char *argv[]) {
    std::string title("tictacs ");
    title += std::to_string(tictacs_VERSION_MAJOR) += std::string(".") += std::to_string(tictacs_VERSION_MINOR);
    if (tictacs_VERSION_REVISION != nullptr) {
        title += std::string(".") += tictacs_VERSION_REVISION;
    }
    if (tictacs_VERSION_BRANCH != nullptr) {
        title += std::string(" on ") += tictacs_VERSION_BRANCH;
    }

    sf::RenderWindow App(sf::VideoMode(800, 600), title);
    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.clear();
        App.display();
    }
    return EXIT_SUCCESS;
}

