#pragma once
#include "InputHandler.h"

using namespace std;

class KeyboardHandler : public InputHandler
{
public:
	float speed;
	KeyboardHandler();
	~KeyboardHandler();
	
	bool cooldowntriggerW;
	bool cooldowntriggerS;
	bool cooldowntriggerA;
	bool cooldowntriggerD;
	string state;

	void update(SDL_Event* event);
};

