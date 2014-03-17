#include "FUStateManager.h"

FUStateManager::FUStateManager()
    : mCurrentStateIdentifier(0)
{

}

FUStateManager::~FUStateManager()
{
    mStatesMap.erase(mStatesMap.begin(), mStatesMap.end());
}

void FUStateManager::handleEvent(sf::Event &event)
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->handleEvent(event);
    }
}

void FUStateManager::update(sf::Time dt)
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->update(dt);
    }
}

void FUStateManager::draw()
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->draw();
    }
}

bool FUStateManager::isStateStackEmpty()
{
    return mStatesMap.size() == 0;
}

bool FUStateManager::removeState(int stateIdentifier)
{
    auto found = mStatesMap.find(stateIdentifier);
    //If the state doesn't exist return false
    if (found == mStatesMap.end())
        return false;
    mStatesMap.erase(stateIdentifier);
    return true;
}

void FUStateManager::clearStates()
{
    mStatesMap.erase(mStatesMap.begin(), mStatesMap.end());
}

void FUStateManager::setCurrentState(int stateIdentifier)
{
    mCurrentStateIdentifier = stateIdentifier;
}
