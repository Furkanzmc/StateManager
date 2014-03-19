#ifndef FUSTATEMANAGER_H
#define FUSTATEMANAGER_H
#include <map>
#include <memory>
#include "FUState.h"

class FUStateManager
{
public:
    FUStateManager();
    ~FUStateManager();
    void handleEvent(sf::Event &event);
    void update(sf::Time dt);
    void draw();
    template <class State>
    void addNewState(int stateIdentifier, FUState::FUContext context) {
        mStatesMap.insert(std::make_pair(stateIdentifier, std::move(std::shared_ptr<State>(new State(context)))));
    }
    bool removeState(int stateIdentifier);
    void clearStates();
    bool isStateStackEmpty();
    void setCurrentState(int stateIdentifier);

private:
    /**
     * @brief int is used as a enumerator, since every item in enumerator has an integer value
     * We're using std::shared_ptr here because we don't want to deal with its destruction after it's removed from the map and so that
     * we can access and use its private members
     */
    typedef std::map<int, std::shared_ptr<FUState>> StateStack;
    StateStack mStatesMap;
    int mCurrentStateIdentifier;
};
#endif // FUSTATEMANAGER_H
