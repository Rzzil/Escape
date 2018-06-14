#include "Player.h"


Player::Player()
{
	cooldownW = 5;
	cooldownS = 5;
	cooldownA = 5;
	cooldownD = 5;
	skillw = false;
	skills = false;
	skilla = false;
	skilld = false;
}

Player::~Player()
{

}

void Player::setAnimation(Animation* animation)
{
	this->animation = animation;
}

//overriding
void Player::update(float dt) {
	//face direction based on velocity.x value
	if (velocity.x > 0) {
		faceRight = true;
	}
	if (velocity.x < 0) {
		faceRight = false;
	}
	if (pos.x < 20)
	{
		pos.x = 20;
	}
	if (pos.x > 592)
	{
		pos.x = 592;
	}
	if (pos.y < 83.5)
	{
		pos.y = 83.5;
	}
	if (pos.y > 425)
	{
		pos.y = 425;
	}

	//use basic entity movement to move around
	updateMovement(dt);

	//update animations too
	animation->update(dt);
}

void Player::draw(float scale)
{
	if (animation != NULL) {
		if (faceRight)
			animation->draw(pos.x, pos.y, scale, false);
		else
			animation->draw(pos.x, pos.y, scale, true);
	}
}