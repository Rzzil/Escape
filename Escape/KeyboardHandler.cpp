#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
	speed = 100;
	cooldowntriggerW = false;
	cooldowntriggerS = false;
	cooldowntriggerA = false;
	cooldowntriggerD = false;
	particleSwitch = false;
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event) {

	/*if (player->pos.x < 20)
	{
		player->pos.x = 20;
	}*/

	//button presses for our hero
	if (event->type == SDL_KEYDOWN) {
		//reset hero position if press R
		if (event->key.keysym.scancode == SDL_SCANCODE_A && !cooldowntriggerA) {
			cooldowntriggerA = true;
			player->pos.x -= 50;
			player->skilla = true;
			SoundManager::soundManager.playSound("Action");
			player->particleCD = 1.5;
			if(particleSwitch != true)
			{
				particleSwitch = true;
			}
		}
		//TODO add attacks or other actions here for button presses
		if (event->key.keysym.scancode == SDL_SCANCODE_D && !cooldowntriggerD) {
			cooldowntriggerD = true;
			player->pos.x += 50;
			player->skilld = true;
			SoundManager::soundManager.playSound("Action");
			player->particleCD = 1.5;
			if (particleSwitch != true)
			{
				particleSwitch = true;
			}
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_W && !cooldowntriggerW) {
			cooldowntriggerW = true;
			player->pos.y -= 50;
			player->skillw = true;
			SoundManager::soundManager.playSound("Action");
			player->particleCD = 1.5;
			if (particleSwitch != true)
			{
				particleSwitch = true;
			}
		}
		if (event->key.keysym.scancode == SDL_SCANCODE_S && !cooldowntriggerS) {
			cooldowntriggerS = true;
			player->pos.y += 50;
			player->skills = true;
			SoundManager::soundManager.playSound("Action");
			player->particleCD = 1.5;
			if (particleSwitch != true)
			{
				particleSwitch = true;
			}
		}
	}

	//check if a button is held down
	//first get state of all keyboard buttons (1 pressed, 0 not pressed)
	//keystates = SDL_GetKeyboardState(NULL); //you can pass it a smaller array, or null to return all keys
	keystates = SDL_GetKeyboardState(NULL);				 //if hold up, move hero up
	if (keystates[SDL_SCANCODE_UP])
	{
		keystates = SDL_GetKeyboardState(NULL);
		player->velocity.y = -speed;
	}
		
	//down
	if (keystates[SDL_SCANCODE_DOWN])
	{
		keystates = SDL_GetKeyboardState(NULL);
		player->velocity.y = speed;
	}
		
	//left
	if (keystates[SDL_SCANCODE_LEFT])
	{
		keystates = SDL_GetKeyboardState(NULL);
		player->velocity.x = -speed;
	}
		
	//right
	if (keystates[SDL_SCANCODE_RIGHT])
	{
		keystates = SDL_GetKeyboardState(NULL);
		player->velocity.x = speed;
	}
		
	//check if none are held down
	if (!keystates[SDL_SCANCODE_UP] && !keystates[SDL_SCANCODE_DOWN])
	{
		keystates = SDL_GetKeyboardState(NULL);
		//then stop moving
		player->velocity.y = 0;
	}
	if (!keystates[SDL_SCANCODE_LEFT] && !keystates[SDL_SCANCODE_RIGHT])
	{
		keystates = SDL_GetKeyboardState(NULL);
		player->velocity.x = 0;
	}

}