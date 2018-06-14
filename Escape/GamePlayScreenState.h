#pragma once
#include "SecondPlayScreenState.h"
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
	SDL_Texture* textTexture;

	list<Player*> entities;

	KeyboardHandler keyboardHandler;
	MouseHandler mouseHandler;

	SDL_Texture *background;
	SDL_Rect backgroundSrc = { 0,0,644,404 };
	SDL_Rect backgroundDest = { 0,0,640,480 };

	//player declear
	SDL_Texture *playerTexture;
	Player *player;
	Animation *playerAnimation;

	//Monster1 declear
	SDL_Texture *monster1Texture;
	Player *monster1;
	Animation *monster1Animation;

	//Monster2 declear
	SDL_Texture *monster2Texture;
	Player *monster2;
	Animation *monster2Animation;

	//Monster3 declear
	SDL_Texture *monster3Texture;
	Player *monster3;
	Animation *monster3Animation;

	//Monster4 declear
	SDL_Texture *monster4Texture;
	Player *monster4;
	Animation *monster4Animation;

	//Monster5 declear
	SDL_Texture *monster5Texture;
	Player *monster5;
	Animation *monster5Animation;

	//Monster6 declear
	SDL_Texture *monster6Texture;
	Player *monster6;
	Animation *monster6Animation;

	//Monster7 declear
	SDL_Texture *monster7Texture;
	Player *monster7;
	Animation *monster7Animation;

	//Monster8 declear
	SDL_Texture *monster8Texture;
	Player *monster8;
	Animation *monster8Animation;

	//Monster9 declear
	SDL_Texture *monster9Texture;
	Player *monster9;
	Animation *monster9Animation;

	//Monster10 declear
	SDL_Texture *monster10Texture;
	Player *monster10;
	Animation *monster10Animation;

	//Monster11 declear
	SDL_Texture *monster11Texture;
	Player *monster11;
	Animation *monster11Animation;


	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt = 0;//time since last update

	GamePlayScreenState();
	~GamePlayScreenState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "stage1"; }
};

