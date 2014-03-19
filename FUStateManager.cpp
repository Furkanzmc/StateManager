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
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = std::find_if(iterator, iteratorEnd, [](std::pair<const int, std::unique_ptr<FUState>> &pair) {
                return pair.second->getDrawOverOtherStates();
            });
            //There's a state to draw over others handle its events
            if (found != mStatesMap.end()) {
                found->second->handleEvent(event);
            }
        }
    }
}

void FUStateManager::update(sf::Time dt)
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->update(dt);
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = std::find_if(iterator, iteratorEnd , [](std::pair<const int, std::unique_ptr<FUState>> &pair) {
                return pair.second->getDrawOverOtherStates();
            });
            //There's a state to draw over others update it
            if (found != mStatesMap.end()) {
                found->second->update(dt);
            }
        }
    }
}

void FUStateManager::draw()
{
    if (isStateStackEmpty() == false) {
        mStatesMap.at(mCurrentStateIdentifier)->draw();
        //Iterate through all the states and find the one that's to be drawed over
        StateStack::iterator iteratorEnd = mStatesMap.end();
        for (StateStack::iterator iterator = mStatesMap.begin(); iterator != iteratorEnd; iterator++) {
            auto found = std::find_if(iterator, iteratorEnd, [](std::pair<const int, std::unique_ptr<FUState>> &pair) {
                return pair.second->getDrawOverOtherStates();
            });
            //There's a state to draw over others draw it
            if (found != mStatesMap.end()) {
                found->second->draw();
            }
        }
    }
}

bool FUStateManager::isStateStackEmpty()
{
    return mStatesMap.empty();
}

bool FUStateManager::removeState(int stateIdentifier)
{
    auto found = mStatesMap.find(stateIdentifier);
    //If the state doesn't return false
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
