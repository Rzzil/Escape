#pragma once
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameState.h"
#include "GlobalGameState.h"
#include <iostream>
#include "Player.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"


using namespace std;

class GamePlayScreenState :
	public GameState
{
public:
	//we're gonna add textures and stuff here as attributes
	SDL_Texture* heroTexture;
	Animation* heroAnimation;
	Player* player;
	SDL_Texture* textTexture;

	list<Entity*> entities;

	KeyboardHandler keyboardHandler;
	MouseHandler mouseHandler;

	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt = 0;//time since last update

	GamePlayScreenState();
	~GamePlayScreenState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "gamePlayState"; }
};

