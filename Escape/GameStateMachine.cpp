#include "GameStateMachine.h"


GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::pushState(GameState * state)
{
	gameStates.push_back(state);
	gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState * state)
{
	if (!gameStates.empty()) {
		if (gameStates.back()->getStateID() == state->getStateID())
			return; //nothing, no state to change

		if (gameStates.back()->onExit())
		{
			delete gameStates.back();
			gameStates.pop_back();
		}

	}

	gameStates.push_back(state);
	gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!gameStates.empty()) {
		if (gameStates.back()->onExit())
		{
			delete gameStates.back();
			gameStates.pop_back();
		}

	}
}

void GameStateMachine::clearAll()
{
	//delete all memory of states
	for (auto gs : gameStates) {
		delete gs;
	}
	//empty the list
	gameStates.clear();
}

void GameStateMachine::update()
{
	if (!gameStates.empty())
		gameStates.back()->update();
}

void GameStateMachine::render()
{
	if (!gameStates.empty())
		gameStates.back()->render();
}

GameStateMachine GameStateMachine::gameStateMachine;