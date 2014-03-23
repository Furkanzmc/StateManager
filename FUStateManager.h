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
    void addNewState(int stateIdentifier, std::unique_ptr<FUState> state);
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
    typedef std::map<int, std::unique_ptr<FUState>> StateStack;
    StateStack mStatesMap;
    int mCurrentStateIdentifier;
};
#endif // FUSTATEMANAGER_H
