#pragma once
#include "InputHandler.h"
#include "GamePlayScreenState.h"
#include "SecondPlayScreenState.h"

class KeyboardHandler : public InputHandler
{
public:
	float speed;
	KeyboardHandler();
	~KeyboardHandler();

	string state;

	void update(SDL_Event* event);
};

