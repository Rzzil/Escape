#pragma once
#include "GameState.h"
#include <vector>

using namespace std;
class GameStateMachine
{
public:
	vector<GameState*> gameStates;

	GameStateMachine();
	~GameStateMachine();

	//state management
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();
	void clearAll();

	//update and render
	void update();
	void render();

	//global reference we can use
	static GameStateMachine gameStateMachine;

};

