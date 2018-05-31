#include "GamePlayScreenState.h"


GamePlayScreenState::GamePlayScreenState()
{
	background = IMG_LoadTexture(GlobalGameState::renderer, "assets/Stage1.png");
	//Player set
	playerTexture = IMG_LoadTexture(GlobalGameState::renderer, "assets/walkfix1.png");
	player = new Player();
	playerAnimation = new Animation(playerTexture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	player->setAnimation(playerAnimation);
	player->setRenderer(GlobalGameState::renderer);
	player->pos.x = 20;
	player->pos.y = 83.5;
	entities.push_back(player);
	keyboardHandler.player = player;
	//monster1 set
	monster1Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster1.png");
	monster1 = new Player();
	monster1Animation = new Animation(monster1Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster1->setAnimation(monster1Animation);
	monster1->setRenderer(GlobalGameState::renderer);
	monster1->pos.x = 40.7;
	monster1->pos.y = 194.5;
	entities.push_back(monster1);
	//monster2 set
	monster2Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster2.png");
	monster2 = new Player();
	monster2Animation = new Animation(monster2Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster2->setAnimation(monster2Animation);
	monster2->setRenderer(GlobalGameState::renderer);
	monster2->pos.x = 80.5;
	monster2->pos.y = 425.2;
	entities.push_back(monster2);
	//monster3 set
	monster3Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster1.png");
	monster3 = new Player();
	monster3Animation = new Animation(monster3Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster3->setAnimation(monster3Animation);
	monster3->setRenderer(GlobalGameState::renderer);
	monster3->pos.x = 249.7;
	monster3->pos.y = 196.39;
	entities.push_back(monster3);
	//monster4 set
	monster4Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster2.png");
	monster4 = new Player();
	monster4Animation = new Animation(monster4Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster4->setAnimation(monster4Animation);
	monster4->setRenderer(GlobalGameState::renderer);
	monster4->pos.x = 186.49;
	monster4->pos.y = 311.5;
	entities.push_back(monster4);
	//monster5 set
	monster5Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster3.png");
	monster5 = new Player();
	monster5Animation = new Animation(monster5Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster5->setAnimation(monster5Animation);
	monster5->setRenderer(GlobalGameState::renderer);
	monster5->pos.x = 401.2;
	monster5->pos.y = 426.5;
	entities.push_back(monster5);
	//monster6 set
	monster6Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster1.png");
	monster6 = new Player();
	monster6Animation = new Animation(monster6Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster6->setAnimation(monster6Animation);
	monster6->setRenderer(GlobalGameState::renderer);
	monster6->pos.x = 377.6;
	monster6->pos.y = 196.69;
	entities.push_back(monster6);
	//monster7 set
	monster7Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster2.png");
	monster7 = new Player();
	monster7Animation = new Animation(monster7Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster7->setAnimation(monster7Animation);
	monster7->setRenderer(GlobalGameState::renderer);
	monster7->pos.x = 407.7;
	monster7->pos.y = 311.8;
	entities.push_back(monster7);
	//monster8 set
	monster8Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster1.png");
	monster8 = new Player();
	monster8Animation = new Animation(monster8Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster8->setAnimation(monster8Animation);
	monster8->setRenderer(GlobalGameState::renderer);
	monster8->pos.x = 556.2;
	monster8->pos.y = 196.9;
	entities.push_back(monster8);
	//monster9 set
	monster9Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster1.png");
	monster9 = new Player();
	monster9Animation = new Animation(monster9Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster9->setAnimation(monster9Animation);
	monster9->setRenderer(GlobalGameState::renderer);
	monster9->pos.x = 524.6;
	monster9->pos.y = 426.8;
	entities.push_back(monster9);
	//monster10 set
	monster10Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster3.png");
	monster10 = new Player();
	monster10Animation = new Animation(monster10Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster10->setAnimation(monster10Animation);
	monster10->setRenderer(GlobalGameState::renderer);
	monster10->pos.x = 591.3;
	monster10->pos.y = 395.2;
	entities.push_back(monster10);

	//monster11 set
	monster11Texture = IMG_LoadTexture(GlobalGameState::renderer, "assets/Monster3.png");
	monster11 = new Player();
	monster11Animation = new Animation(monster10Texture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	monster11->setAnimation(monster11Animation);
	monster11->setRenderer(GlobalGameState::renderer);
	monster11->pos.x = 556.4;
	monster11->pos.y = 83.7;
	entities.push_back(monster11);



	lastUpdate = SDL_GetTicks();

	
}

GamePlayScreenState::~GamePlayScreenState()
{
	//delete everything we need to
	SDL_DestroyTexture(background);
	//player destory
	SDL_DestroyTexture(playerTexture);
	delete player;
	delete playerAnimation;
	//monster1 destory
	SDL_DestroyTexture(monster1Texture);
	delete monster1;
	delete monster1Animation;
	//monster2 destory
	SDL_DestroyTexture(monster2Texture);
	delete monster2;
	delete monster2Animation;
	//monster3 destory
	SDL_DestroyTexture(monster3Texture);
	delete monster3;
	delete monster3Animation;
	//monster4 destory
	SDL_DestroyTexture(monster4Texture);
	delete monster4;
	delete monster4Animation;
	//monster5 destory
	SDL_DestroyTexture(monster5Texture);
	delete monster5;
	delete monster5Animation;
	//monster6 destory
	SDL_DestroyTexture(monster6Texture);
	delete monster6;
	delete monster6Animation;
	//monster7 destory
	SDL_DestroyTexture(monster7Texture);
	delete monster7;
	delete monster7Animation;
	//monster8 destory
	SDL_DestroyTexture(monster8Texture);
	delete monster8;
	delete monster8Animation;
	//monster9 destory
	SDL_DestroyTexture(monster9Texture);
	delete monster9;
	delete monster9Animation;
	//monster10 destory
	SDL_DestroyTexture(monster10Texture);
	delete monster10;
	delete monster10Animation;
	//monster11 destory
	SDL_DestroyTexture(monster11Texture);
	delete monster11;
	delete monster11Animation;
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
			if (e.key.keysym.scancode == SDL_SCANCODE_1)
			{
				GlobalGameState::gameStateMachine.popState();
				GlobalGameState::gameStateMachine.pushState(new SecondPlayScreenState());
				return;
			}
		}
		keyboardHandler.update(&e);
		//mouseHandler.update(&e);
	}

	//hero->update(dt);
	for (auto e : entities)
	{
		e->update(dt);
	}
}
void GamePlayScreenState::render() {

	
	//hero->draw();

	SDL_RenderCopy(GlobalGameState::renderer, background, &backgroundSrc, &backgroundDest);
	for (auto e : entities)
	{
		e->draw(0.6);
	}

	string temp = "x: " + to_string(player->pos.x) + " y: " + to_string(player->pos.y);
	const char* location = temp.c_str();
	//LOAD UP OUR FONT
	TTF_Font* font = TTF_OpenFont("assets/yahei.ttf", 16); //params: font file, font size
	SDL_Color textColor = { 123, 0, 34, 0 };
	//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, location, textColor);
	//convert surface to texture
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface);
	//delete surface properly
	SDL_FreeSurface(textSurface);

	//text destination
	SDL_Rect textDestination;
	textDestination.x = 400;
	textDestination.y = 10;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture, NULL, &textDestination);
	//cleanup font
	TTF_CloseFont(font);
	//clean up textures
	SDL_DestroyTexture(textTexture);



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