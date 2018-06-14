#pragma once
#include "InputHandler.h"
#include "SoundManager.h"

using namespace std;

class KeyboardHandler : public InputHandler
{
public:
	float speed;
	KeyboardHandler();
	~KeyboardHandler();
	const Uint8 *keystates;
	
	bool cooldowntriggerW;
	bool cooldowntriggerS;
	bool cooldowntriggerA;
	bool cooldowntriggerD;
	string state;

	void update(SDL_Event* event);
};

