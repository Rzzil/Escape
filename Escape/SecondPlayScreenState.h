#pragma once
#include "GameState.h"
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GlobalGameState.h"
#include <SDL.h>
#include "Player.h"
#include "KeyboardHandler.h"
#include <list>

using namespace std;

class SecondPlayScreenState :
	public GameState
{
public:
	SecondPlayScreenState();
	~SecondPlayScreenState();

	list<Player*> entities;

	KeyboardHandler keyboardHandler;
	SDL_Texture *background;
	SDL_Texture *playerTexture;
	Player *player;
	Animation *playerAnimation;
	SDL_Rect backgroundSrc = { 0,0,644,404 };
	SDL_Rect backgroundDest = { 0,0,640,480 };

	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt = 0;//time since last update

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual string getStateID() const{ return "Stage2"; }
};

