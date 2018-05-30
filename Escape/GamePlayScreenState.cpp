#include "GamePlayScreenState.h"


GamePlayScreenState::GamePlayScreenState()
{
	SDL_Surface* runSurface = IMG_Load("assets/run.png");
	//tell surface which colour should be invisible
	SDL_SetColorKey(runSurface, 1, SDL_MapRGB(runSurface->format, 128, 128, 255));
	//convert it to texture
	heroTexture = SDL_CreateTextureFromSurface(GlobalGameState::renderer, runSurface);
	//cleanup surface memory
	SDL_FreeSurface(runSurface);

	heroAnimation = new Animation(heroTexture, GlobalGameState::renderer, 4, 32, 32, 0.8);

	player = new Player();
	player->setAnimation(heroAnimation);
	player->setRenderer(GlobalGameState::renderer);
	player->pos.x = 200;
	player->pos.y = 200;


	entities.push_back(player);

	keyboardHandler.player = player;
	mouseHandler.player = player;

	lastUpdate = SDL_GetTicks();

}

GamePlayScreenState::~GamePlayScreenState()
{
	//delete everything we need to
	delete player;
	delete heroAnimation;
	SDL_DestroyTexture(heroTexture);
}

void GamePlayScreenState::update() {
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
		mouseHandler.update(&e);
	}

	//hero->update(dt);
	for (auto e : entities) {
		e->update(dt);
	}
}
void GamePlayScreenState::render() {
	SDL_SetRenderDrawColor(GlobalGameState::renderer, 255, 90, 0, 255);

	SDL_RenderClear(GlobalGameState::renderer);

	for (auto e : entities) {
		e->draw();
	}
	//hero->draw();

	SDL_RenderPresent(GlobalGameState::renderer);
}
bool GamePlayScreenState::onEnter() {
	cout << "Enter Gameplay state" << endl;
	return true;
}
bool GamePlayScreenState::onExit() {
	cout << "Exit Gameplay state" << endl;
	return true;
}