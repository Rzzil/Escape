#pragma once
#include "Entity.h"
#include "Animation.h"

using namespace std;

class Player :public Entity
{
private:
	Animation* animation = NULL;
	bool faceRight = true;
public:
	Player();
	~Player();

	void setAnimation(Animation* animation);

	//the skill cooldown of the player
	float cooldownW;
	float cooldownS;
	float cooldownA;
	float cooldownD;

	//the skill killing switch
	bool skillw;
	bool skills;
	bool skilla;
	bool skilld;
	//overriding
	virtual void update(float dt);
	virtual void draw(float scale);

};

