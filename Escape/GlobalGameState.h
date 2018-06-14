#pragma once

#include <SDL.h>
#include"GameStateMachine.h"

using namespace std;

enum game_state {
	MENU,
	OPTIONS,
	GAMEPLAY
};


class GlobalGameState
{
public:
	GlobalGameState();
	~GlobalGameState();

	//are declared at the start of program runtime
	static game_state currentGameState;
	static SDL_Renderer* renderer;
	static bool quitGame;

	//global reference we can use
	static GameStateMachine gameStateMachine;
};

