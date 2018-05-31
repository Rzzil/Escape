#include "Player.h"


Player::Player()
{

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