FUStateManager
==============

A simple SFML state manager

Example Usage
================
```cpp
enum AD {
    A,
    B,
    C,
    D
};

int main()
{
    std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(640, 480), "SD", sf::Style::Default));
    FUStateManager manager;
    FUState::FUContext context(window);
    manager.addNewState<DummyState2>(AD::C, context);
    manager.addNewState<DummyState3>(AD::A, context);
    manager.addNewState<DummyState>(AD::B, context);
    manager.setCurrentState(AD::B);
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
```
