#pragma once

#include <string>

class GameState
{
public:
	GameState();
	~GameState();
	virtual void update() = 0; //=0 means abstract function, meaning GameState is now abstract class
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};

