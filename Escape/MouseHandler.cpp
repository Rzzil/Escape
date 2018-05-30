#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
}


MouseHandler::~MouseHandler()
{
}


void MouseHandler::update(SDL_Event* event) {
	//check if user has clicked on Hero
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		//check if its the left mouse button
		if (event->button.button == SDL_BUTTON_LEFT)	// SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT
		{
			//check if its clicked on the hero region
			if (event->button.x >= player->pos.x && event->button.x <= player->pos.x + 32
				&& event->button.y >= player->pos.y && event->button.y <= player->pos.y + 32)
			{
				leftMousePressedDown = true;
			}
		}
	}
	//check if mouse button released
	if (event->type == SDL_MOUSEBUTTONUP) {
		if (event->button.button == SDL_BUTTON_LEFT)
			leftMousePressedDown = false;
	}
	//if left pressed and mouse moving, drag hero around
	if (leftMousePressedDown && event->type == SDL_MOUSEMOTION) {
		player->pos.x = event->motion.x;
		player->pos.y = event->motion.y;
	}
}