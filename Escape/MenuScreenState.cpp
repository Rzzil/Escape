#include "MenuScreenState.h"


MenuScreenState::MenuScreenState()
{
	heroTexture = IMG_LoadTexture(GlobalGameState::renderer, "assets/walkfix1.png");

	heroAnimation = new Animation(heroTexture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	player = new Player();
	player->setAnimation(heroAnimation);
	player->setRenderer(GlobalGameState::renderer);
	player->pos.x = 0;
	player->pos.y = 240;

	entities.push_back(player);

	lastUpdate = SDL_GetTicks();
}


MenuScreenState::~MenuScreenState()
{
	SDL_DestroyTexture(heroTexture);
	delete player;
	delete heroAnimation;
}

void MenuScreenState::update() {
	//update our delta time
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();
	if (player->pos.x <= 280)
	{
		player->pos.x += 3;
	}
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT) {
			//exit our loop,
			GlobalGameState::quitGame = true;
			GlobalGameState::gameStateMachine.popState(); //which will kill this screen
			return;

		}
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				GlobalGameState::quitGame = true;
				GlobalGameState::gameStateMachine.popState(); //which will kill this screen
				return;
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
				//start the game!
				GlobalGameState::gameStateMachine.pushState(new GamePlayScreenState());
			}
			//press E key, make explosion sound
			if (e.key.keysym.scancode == SDL_SCANCODE_E) {
				SoundManager::soundManager.playSound("explode");
			}
		}
	}
	for (auto e : entities) {
		e->update(dt);
	}
}
void MenuScreenState::render() {
	/*SDL_SetRenderDrawColor(GlobalGameState::renderer, 196, 223, 155, 255);

	SDL_RenderClear(GlobalGameState::renderer);*/

	SDL_Texture *background = IMG_LoadTexture(GlobalGameState::renderer, "assets/background.jpg");
	SDL_Rect src = { 0,0,640,480 };
	SDL_Rect dest = { 0,0,640,480 };

	SDL_RenderCopy(GlobalGameState::renderer, background, &src, &dest);

	for (auto e : entities) {
		e->draw(1);
	}
	//hero->draw();

	//LOAD UP OUR FONT
	TTF_Font* font = TTF_OpenFont("assets/yahei.ttf", 50); //params: font file, font size
														   //add text delay time for random color
	textDelayTime += dt;
	if (textDelayTime >= 0.5)
	{
		textColor.r = rand() % 256;
		textColor.g = rand() % 256;
		textColor.b = rand() % 256;
		textDelayTime = 0;
	}
	//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Escape", textColor);
	//convert surface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface);
	//delete surface properly
	SDL_FreeSurface(textSurface);

	//text destination
	SDL_Rect textDestination;
	textDestination.x = 230;
	textDestination.y = 70;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture, NULL, &textDestination);
	//cleanup font
	TTF_CloseFont(font);
	//clean up textures
	SDL_DestroyTexture(textTexture);

	//LOAD UP OUR FONT
	TTF_Font* font1 = TTF_OpenFont("assets/yahei.ttf", 25); //params: font file, font size
															//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface1 = TTF_RenderText_Blended(font1, "Press E to show action", textColor);
	//convert surface to texture
	SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface1);
	//delete surface properly
	SDL_FreeSurface(textSurface1);

	//text destination
	SDL_Rect textDestination1;
	textDestination1.x = 185;
	textDestination1.y = 350;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture1, NULL, &textDestination1);
	//cleanup font
	TTF_CloseFont(font1);
	//clean up textures
	SDL_DestroyTexture(textTexture1);

	SDL_RenderPresent(GlobalGameState::renderer);
	SDL_DestroyTexture(background);
}
bool MenuScreenState::onEnter() {
	std::cout << "Entering menu state" << std::endl;
	return true;
}
bool MenuScreenState::onExit() {
	std::cout << "Exiting menu state" << std::endl;
	return true;
}