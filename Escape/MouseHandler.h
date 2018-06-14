#pragma once
#include "InputHandler.h"

using namespace std;

class MouseHandler : public InputHandler
{
public:
	bool leftMousePressedDown = false;

	MouseHandler();
	~MouseHandler();

	void update(SDL_Event* event);
};

