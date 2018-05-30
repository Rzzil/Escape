#include "GlobalGameState.h"


GlobalGameState::GlobalGameState()
{
}


GlobalGameState::~GlobalGameState()
{
}

//static variables must be declared in this fashion in C++
//it gets this MENU value at the start of runtime
game_state GlobalGameState::currentGameState = MENU;
SDL_Renderer* GlobalGameState::renderer = NULL;
bool GlobalGameState::quitGame = false;
GameStateMachine GlobalGameState::gameStateMachine;