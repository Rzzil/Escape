#include "GameOverState.h"



GameOverState::GameOverState()
{
	background = IMG_LoadTexture(GlobalGameState::renderer, "assets/Stage1.png");
}


GameOverState::~GameOverState()
{
	SDL_DestroyTexture(background);
}


void GameOverState::update()
{
	//TODO DEAL WITH USER INPUT
	//DEAL WITH USER INPUT
	//we check what kind of user input events have happened since our last check
	SDL_Event e;
	//loops through all events and temporarily stores event details in an SDL_Event object
	while (SDL_PollEvent(&e))
	{
		//check if user has clicked on the close window button
		if (e.type == SDL_QUIT) {
			//exit our loop,
			//loop = false;
			GlobalGameState::quitGame = true;
			GlobalGameState::gameStateMachine.popState(); //which will kill this screen
			return;
		}
		//check if user has 'pressed' a button(not held)
		if (e.type == SDL_KEYDOWN)
		{
			//see if ESC key was pressed
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				//exit loop
				//loop = false;
				GlobalGameState::gameStateMachine.popState(); //which will kill this screen
				return;
			}
		}
	}
}

void GameOverState::render()
{
	SDL_RenderCopy(GlobalGameState::renderer, background, &backgroundSrc, &backgroundDest);
	//LOAD UP OUR FONT
	TTF_Font* font = TTF_OpenFont("assets/yahei.ttf", 70); //params: font file, font size
	SDL_Color textColor = { 123, 0, 34, 0 };
	//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "You Die!!!", textColor);
	//convert surface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface);
	//delete surface properly
	SDL_FreeSurface(textSurface);

	//text destination
	SDL_Rect textDestination;
	textDestination.x = 180;
	textDestination.y = 230;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture, NULL, &textDestination);



	SDL_RenderPresent(GlobalGameState::renderer);
}

bool GameOverState::onEnter()
{
	cout << "Enter Gameplay state" << endl;
	return true;
}

bool GameOverState::onExit()
{
	cout << "Exit Gameplay state" << endl;
	return true;
}