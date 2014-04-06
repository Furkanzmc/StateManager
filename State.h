#ifndef STATE_H
#define STATE_H
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

namespace zmc
{
class State
{
public:
    State()
        : mIsPaused(false)
        , mIsOnTop(false) {}

    virtual ~State() {}
    virtual void handleEvent(sf::Event &event) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void draw() = 0;
    virtual void pause()
    {
        mIsPaused = true;
    }
    virtual void resume()
    {
        mIsPaused = false;
    }

    virtual void setOnTop(bool drawOver)
    {
        mIsOnTop = drawOver;
    }

    virtual bool isOnTop()
    {
        return mIsOnTop;
    }

    bool isPaused()
    {
        return mIsPaused;
    }

private:
    /**
     * @brief Handle what happens when the state is paused inside that state
     */
    bool mIsPaused;
    /**
     * @brief Draw order is determined according to a state's order in std::map. Since we're using ints as key elements,
     * the bigger value will appear on top. If the mIsOnTop value is true, the related state is drawn over others whether it's set as
     * the current state or not.
     */
    bool mIsOnTop;
};
}
#endif // STATE_H
