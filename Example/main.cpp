#include <iostream>
#include "StateManager.h"
#include "DummyState.h"
using namespace std;

enum AD {
    A,
    B,
};

int main()
{
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(640, 480), "State Manager", sf::Style::Default));
    fu::StateManager manager;
    std::unique_ptr<DummyState> dummy(new DummyState(window));
    //AD:A enumerator can only have one state
    manager.addNewState(AD::A, std::move(dummy));
    manager.setCurrentState(AD::A);
    sf::Clock clock;
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                manager.clearStates();
            }
            manager.handleEvent(event);
        }
        window->clear();
        manager.update(clock.restart());
        manager.draw();
        window->display();
    }
    return 0;
}
