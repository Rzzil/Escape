#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
	speed = 100;
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event) {
	//button presses for our hero
	if (event->type == SDL_KEYDOWN) {
		//reset hero position if press R
		if (event->key.keysym.scancode == SDL_SCANCODE_R) {
			player->pos.x = 200;
			player->pos.y = 200;
		}
		//TODO add attacks or other actions here for button presses
	}

	//check if a button is held down
	//first get state of all keyboard buttons (1 pressed, 0 not pressed)
	const Uint8 *keystates = SDL_GetKeyboardState(NULL); //you can pass it a smaller array, or null to return all keys
														 //if hold up, move hero up
	if (keystates[SDL_SCANCODE_UP])
		player->velocity.y = -speed;
	//down
	if (keystates[SDL_SCANCODE_DOWN])
		player->velocity.y = speed;
	//left
	if (keystates[SDL_SCANCODE_LEFT])
		player->velocity.x = -speed;
	//right
	if (keystates[SDL_SCANCODE_RIGHT])
		player->velocity.x = speed;
	//check if none are held down
	if (!keystates[SDL_SCANCODE_UP] && !keystates[SDL_SCANCODE_DOWN])
	{
		//then stop moving
		player->velocity.y = 0;
	}
	if (!keystates[SDL_SCANCODE_LEFT] && !keystates[SDL_SCANCODE_RIGHT])
	{
		player->velocity.x = 0;
	}

}