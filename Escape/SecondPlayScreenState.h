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
#include "WinScreenState.h"
#include "GameOverState.h"
#include <sstream>

using namespace std;

class SecondPlayScreenState :
	public GameState
{
public:
	SecondPlayScreenState();
	~SecondPlayScreenState();

	SDL_Texture* textTexture;

	int direction1;
	int direction2;

	float count = 1.5;

	list<Player*> entities;

	KeyboardHandler keyboardHandler;
	SDL_Texture *background;
	SDL_Texture *playerTexture;
	Player *player;
	Animation *playerAnimation;
	SDL_Rect backgroundSrc;
	SDL_Rect backgroundDest;

	SDL_Texture *w;
	SDL_Rect wsrc;
	SDL_Rect wdest;

	SDL_Texture *s;
	SDL_Rect ssrc;
	SDL_Rect sdest;

	SDL_Texture *a;
	SDL_Rect asrc;
	SDL_Rect adest;

	SDL_Texture *d;
	SDL_Rect dsrc;
	SDL_Rect ddest;

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
	float dt;//time since last update

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "stage2"; }
};

