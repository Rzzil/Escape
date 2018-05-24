#include "Entity.h"




Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::setRenderer(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Vector Entity::getPosition()
{
	return pos;
}
void Entity::setPosition(Vector pos)
{
	this->pos = pos;
}
Vector Entity::getVelocity()
{
	return velocity;
}
void Entity::setVelocity(Vector velocity)
{
	this->velocity = velocity;
}

void Entity::update(float dt)
{
	updateMovement(dt);
}
void Entity::updateMovement(float dt)
{
	pos.x = pos.x + velocity.x*dt;
	pos.y = pos.y + velocity.y*dt;
}
void Entity::draw()
{

}