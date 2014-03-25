#include "StateManager.h"

namespace zmc
{
StateManager::StateManager()
    : mCurrentStateIdentifier(0)
{

}

StateManager::~StateManager()
{
    mStatesMap.erase(mStatesMap.begin(), mStatesMap.end());
}

void StateManager::handleEvent(sf::Event &event)
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->handleEvent(event);
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = iterator->second.get();
            if (found->isOnTop()) {
                found->handleEvent(event);
            }
        }
    }
}

void StateManager::update(sf::Time dt)
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->update(dt);
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = iterator->second.get();
            if (found->isOnTop()) {
                found->update(dt);
            }
        }
    }
}

void StateManager::draw()
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->draw();
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = iterator->second.get();
            if (found->isOnTop()) {
                found->draw();
            }
        }
    }
}

bool StateManager::isStateStackEmpty()
{
    return mStatesMap.empty();
}

void StateManager::addNewState(int stateIdentifier, std::unique_ptr<zmc::State> state)
{
    mStatesMap.insert(std::make_pair(stateIdentifier, std::move(state)));
    state.reset();
}

bool StateManager::removeState(int stateIdentifier)
{
    auto found = mStatesMap.find(stateIdentifier);
    //If the state doesn't return false
    if (found == mStatesMap.end())
        return false;
    mStatesMap.erase(stateIdentifier);
    return true;
}

void StateManager::clearStates()
{
    mStatesMap.erase(mStatesMap.begin(), mStatesMap.end());
}

void StateManager::setCurrentState(int stateIdentifier)
{
    mCurrentStateIdentifier = stateIdentifier;
}
}
