#ifndef FUSTATE_H
#define FUSTATE_H
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

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
    virtual void setDrawOverOthers(bool drawOver);
    virtual bool getDrawOverOtherStates() {return mDrawOverOtherStates;}

protected:
    /**
     * @brief Handle what happens when the state is paused inside that state
     */
    bool mIsPaused;

private:
    /**
     * @brief Draw order is determined according to a state's order in std::map. Since we're using ints as key elements,
     * the bigger value will appear on top
     */
    bool mDrawOverOtherStates;
};

#endif // FUSTATE_H
