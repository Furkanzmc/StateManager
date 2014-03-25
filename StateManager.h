#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <map>
#include <memory>
#include "State.h"

namespace zmc
{
class StateManager
{
public:
    StateManager();
    ~StateManager();
    void handleEvent(sf::Event &event);
    void update(sf::Time dt);
    void draw();
    void addNewState(int stateIdentifier, std::unique_ptr<zmc::State> state);
    bool removeState(int stateIdentifier);
    void clearStates();
    bool isStateStackEmpty();
    void setCurrentState(int stateIdentifier);
    template <class T>
    T* getState(int stateInentifier)
    {
        return dynamic_cast<T*>(mStatesMap.at(stateInentifier).get());
    }

private:
    /**
     * @brief int is used as a enumerator, since every item in enumerator has an integer value
     */
    typedef std::map<int, std::unique_ptr<zmc::State>> StateStack;
    StateStack mStatesMap;
    int mCurrentStateIdentifier;
};
}
#endif // STATEMANAGER_H
