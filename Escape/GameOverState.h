#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "GameState.h"
#include "GlobalGameState.h"


using namespace std;

class GameOverState :
	public GameState
{
public:
	GameOverState();
	~GameOverState();

	SDL_Texture *background;
	SDL_Rect backgroundSrc = { 0,0,644,404 };
	SDL_Rect backgroundDest = { 0,0,640,480 };

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "GameOver"; }

};

