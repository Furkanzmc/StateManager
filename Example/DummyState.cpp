#include "DummyState.h"
#include <iostream>

DummyState::DummyState(std::shared_ptr<sf::RenderWindow> window)
    : FUState()
    , texture()
    , sprite()
    , mRenderWindow(window)
{
    texture.loadFromFile("/home/furkan/Pictures/Black Widow.jpg");
    sprite.setTexture(texture);
    sprite.setScale(.2f, .2f);
}

DummyState::~DummyState()
{
}

void DummyState::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            pause();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            resume();
    }
}

void DummyState::update(sf::Time dt)
{
    if (!mIsPaused)
        sprite.move(sf::Vector2f(100, 0) * dt.asSeconds());
}

void DummyState::draw()
{
    mRenderWindow->draw(sprite);
}
