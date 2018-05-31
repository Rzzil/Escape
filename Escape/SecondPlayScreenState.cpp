#include "SecondPlayScreenState.h"



SecondPlayScreenState::SecondPlayScreenState()
{
	background = IMG_LoadTexture(GlobalGameState::renderer, "assets/Stage2.png");
	playerTexture = IMG_LoadTexture(GlobalGameState::renderer, "assets/walkfix1.png");

	player = new Player();
	playerAnimation = new Animation(playerTexture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	player->setAnimation(playerAnimation);
	player->setRenderer(GlobalGameState::renderer);
	player->pos.x = 0;
	player->pos.y = 240;

	entities.push_back(player);
	keyboardHandler.player = player;

	lastUpdate = SDL_GetTicks();
}


SecondPlayScreenState::~SecondPlayScreenState()
{
	SDL_DestroyTexture(background);
}

void SecondPlayScreenState::update()
{
	//update our delta time
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();

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
		if (e.type == SDL_KEYDOWN) {
			//see if ESC key was pressed
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				//loop = false;
				GlobalGameState::gameStateMachine.popState(); //which will kill this screen
				return;
			}

		}
		keyboardHandler.update(&e);
	}

	//hero->update(dt);
	for (auto e : entities)
	{
		e->update(dt);
	}
}

void SecondPlayScreenState::render()
{
	SDL_RenderCopy(GlobalGameState::renderer, background, &backgroundSrc, &backgroundDest);
	for (auto e : entities)
	{
		e->draw(0.6);
	}

	SDL_RenderPresent(GlobalGameState::renderer);
}

bool SecondPlayScreenState::onEnter()
{
	cout << "Enter Gameplay state" << endl;
	return true;
}

bool SecondPlayScreenState::onExit()
{
	cout << "Exit Gameplay state" << endl;
	return true;
}
