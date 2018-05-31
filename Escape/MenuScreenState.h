#pragma once
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameState.h"
#include <SDL.h>
#include "GlobalGameState.h"
#include <iostream>
#include "Player.h"
#include "GamePlayScreenState.h"
#include "SoundManager.h"

class MenuScreenState :
	public GameState
{
public:
	//we're gonna add textures and stuff here as attributes
	SDL_Texture* heroTexture;
	Animation* heroAnimation;
	Player* player;

	//for text color
	float textDelayTime = 0;
	//for text color
	SDL_Color textColor = { 123, 0, 34, 0 };

	list<Player*> entities;

	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt = 0;//time since last update

	bool ActionSwitch = false;
	bool Isdead = false;
	MenuScreenState();
	~MenuScreenState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "menuState"; }
};

