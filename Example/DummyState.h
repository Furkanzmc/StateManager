#ifndef DUMMYSTATE_H
#define DUMMYSTATE_H
#include "State.h"
#include <SFML/Graphics.hpp>

class DummyState : public zmc::State
{
public:
    DummyState(std::shared_ptr<sf::RenderWindow> window);
    ~DummyState();
    //You only need to implement these three functions if you don't want to anything
    //different with the pause() and resume()
    virtual void handleEvent(sf::Event &event);
    virtual void update(sf::Time dt);
    virtual void draw();

private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::shared_ptr<sf::RenderWindow> mRenderWindow;
};

#endif // DUMMYSTATE_H
