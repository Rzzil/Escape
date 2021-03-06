#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameState.h"
#include "GlobalGameState.h"

using namespace std;

class WinScreenState :
	public GameState
{
public:
	WinScreenState();
	~WinScreenState();

	SDL_Texture *background;
	SDL_Rect backgroundSrc;
	SDL_Rect backgroundDest;

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "Win"; }
};

