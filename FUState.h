#ifndef FUSTATE_H
#define FUSTATE_H
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
class FUStateManager;

class FUState
{
public:
    struct FUContext
    {
        FUContext(std::shared_ptr<sf::RenderWindow> window)
            : renderWindow(window) {}
        std::shared_ptr<sf::RenderWindow> renderWindow;
    };

public:
    FUState(FUContext context);
    virtual ~FUState();
    virtual void handleEvent(sf::Event &event);
    virtual void update(sf::Time dt);
    virtual void draw();
    virtual void pause();
    virtual void resume();

protected:
    bool mIsPaused;
};

#endif // FUSTATE_H
