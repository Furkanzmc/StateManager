#include <iostream>
#include "FUStateManager.h"
#include "DummyState.h"
#include "DummyState2.h"
using namespace std;

enum AD {
    A,
    B,
};

int main()
{
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(640, 480), "SD", sf::Style::Default));
    FUStateManager manager;
    //This example uses a minimal context. You can add the different variables to your context
    FUState::FUContext context(window);
    //AD:A enumerator can only have one state
    manager.addNewState<DummyState>(AD::A, context);
    manager.addNewState<DummyState2>(AD::B, context);
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
