#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
	speed = 100;
	cooldowntriggerW = false;
	cooldowntriggerS = false;
	cooldowntriggerA = false;
	cooldowntriggerD = false;
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event) {
	//button presses for our hero
	if (event->type == SDL_KEYDOWN) {
		//reset hero position if press R
		if (event->key.keysym.scancode == SDL_SCANCODE_A && !cooldowntriggerA) {
			cooldowntriggerA = true;
			player->pos.x -= 20;
		}
		//TODO add attacks or other actions here for button presses
		if (event->key.keysym.scancode == SDL_SCANCODE_D && !cooldowntriggerD) {
			cooldowntriggerD = true;
			player->pos.x += 20;
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_W && !cooldowntriggerW) {
			cooldowntriggerW = true;
			player->pos.y -= 20;
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_S && !cooldowntriggerS) {
			cooldowntriggerS = true;
			player->pos.y += 20;
		}
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