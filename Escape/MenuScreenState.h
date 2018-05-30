#pragma once
#include "GameState.h"
#include <SDL.h>
#include "GlobalGameState.h"
#include <iostream>
#include "GamePlayScreenState.h"
#include "SoundManager.h"

class MenuScreenState :
	public GameState
{
public:
	MenuScreenState();
	~MenuScreenState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return "menuState"; }
};

