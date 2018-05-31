#pragma once
#include "Entity.h"
#include "Animation.h"

class Player :public Entity
{
private:
	Animation* animation = NULL;
	bool faceRight = true;
public:
	Player();
	~Player();

	void setAnimation(Animation* animation);

	//overriding
	virtual void update(float dt);
	virtual void draw(float scale);

};

