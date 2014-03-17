#include "FUState.h"

FUState::FUState(FUContext context)
    : mIsPaused(false)
{
    (void)context;
}

FUState::~FUState()
{
}

void FUState::handleEvent(sf::Event &event)
{
    (void)event;
}

void FUState::update(sf::Time dt)
{
    (void)dt;
}

void FUState::draw()
{

}

void FUState::pause()
{
    mIsPaused = true;
}

void FUState::resume()
{
    mIsPaused = false;
}
