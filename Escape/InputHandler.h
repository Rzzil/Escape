#pragma once
#include <SDL.h>
#include "Player.h"

using namespace std;

class InputHandler
{
public:
	Player* player;

	InputHandler();
	~InputHandler();

	//abstract function
	virtual void update(SDL_Event* event) = 0;
};

