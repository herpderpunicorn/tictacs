#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char* argv[]) {

  /* Code adapted from the SFML 2 "Window" example */

  cout << "Version " << tictacs_VERSION_MAJOR << "." << tictacs_VERSION_MINOR << "." << tictacs_VERSION_REVISION << " on " << tictacs_VERSION_BRANCH << endl;

  sf::Window App(sf::VideoMode(800, 600), "tictacs");

  while (App.isOpen()) {
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
    App.close();
    }
    App.display();
  }
}

