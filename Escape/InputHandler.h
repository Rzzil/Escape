#pragma once
#include <SDL.h>
#include "Player.h"

class InputHandler
{
public:
	Player* player;


	InputHandler();
	~InputHandler();

	//abstract function
	virtual void update(SDL_Event* event) = 0;
};

