#include "SecondPlayScreenState.h"



SecondPlayScreenState::SecondPlayScreenState()
{
	background = IMG_LoadTexture(GlobalGameState::renderer, "assets/Stage2.png");
	playerTexture = IMG_LoadTexture(GlobalGameState::renderer, "assets/walkfix1.png");
	w = IMG_LoadTexture(GlobalGameState::renderer, "assets/W.png");
	s = IMG_LoadTexture(GlobalGameState::renderer, "assets/S.png");
	a = IMG_LoadTexture(GlobalGameState::renderer, "assets/A.png");
	d = IMG_LoadTexture(GlobalGameState::renderer, "assets/D.png");

	player = new Player();
	playerAnimation = new Animation(playerTexture, GlobalGameState::renderer, 3, 47.67, 49, 0.1);
	player->setAnimation(playerAnimation);
	player->setRenderer(GlobalGameState::renderer);
	player->pos.x = 20;
	player->pos.y = 83.5;

	entities.push_back(player);
	keyboardHandler.player = player;
	keyboardHandler.state = getStateID();

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


SecondPlayScreenState::~SecondPlayScreenState()
{
	//delete everything we need to
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(w);
	SDL_DestroyTexture(s);
	SDL_DestroyTexture(a);
	SDL_DestroyTexture(d);
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

void SecondPlayScreenState::update()
{
	if (entities.back() == player)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new WinScreenState());
		return;
	}

	//update our delta time
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();

	//judge if the player body hit the monsters
	if (
		(player->pos.x + 15 >= monster1->pos.x && player->pos.y + 15 >= monster1->pos.y) &&
		(player->pos.x <= monster1->pos.x + 15 && player->pos.y <= monster1->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}

	if (
		(player->pos.x + 15 >= monster2->pos.x && player->pos.y + 15 >= monster2->pos.y) &&
		(player->pos.x <= monster2->pos.x + 15 && player->pos.y <= monster2->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}

	if (
		(player->pos.x + 15 >= monster3->pos.x && player->pos.y + 15 >= monster3->pos.y) &&
		(player->pos.x <= monster3->pos.x + 15 && player->pos.y <= monster3->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster4->pos.x && player->pos.y + 15 >= monster4->pos.y) &&
		(player->pos.x <= monster4->pos.x + 15 && player->pos.y <= monster4->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster11->pos.x && player->pos.y + 15 >= monster11->pos.y) &&
		(player->pos.x <= monster11->pos.x + 15 && player->pos.y <= monster11->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster5->pos.x && player->pos.y + 15 >= monster5->pos.y) &&
		(player->pos.x <= monster5->pos.x + 15 && player->pos.y <= monster5->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster6->pos.x && player->pos.y + 15 >= monster6->pos.y) &&
		(player->pos.x <= monster6->pos.x + 15 && player->pos.y <= monster6->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster7->pos.x && player->pos.y + 15 >= monster7->pos.y) &&
		(player->pos.x <= monster7->pos.x + 15 && player->pos.y <= monster7->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster8->pos.x && player->pos.y + 15 >= monster8->pos.y) &&
		(player->pos.x <= monster8->pos.x + 15 && player->pos.y <= monster8->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster9->pos.x && player->pos.y + 15 >= monster9->pos.y) &&
		(player->pos.x <= monster9->pos.x + 15 && player->pos.y <= monster9->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	if (
		(player->pos.x + 15 >= monster10->pos.x && player->pos.y + 15 >= monster10->pos.y) &&
		(player->pos.x <= monster10->pos.x + 15 && player->pos.y <= monster10->pos.y + 15)
		)
	{
		GlobalGameState::gameStateMachine.popState();
		GlobalGameState::gameStateMachine.pushState(new GameOverState());
		return;
	}
	//The cooldown trigger of skills
	if (keyboardHandler.cooldowntriggerA)
	{
		player->cooldownA -= dt;
		if (player->cooldownA <= 0)
		{
			keyboardHandler.cooldowntriggerA = false;
			player->cooldownA = 5;
		}
	}

	if (keyboardHandler.cooldowntriggerW)
	{
		player->cooldownW -= dt;
		if (player->cooldownW <= 0)
		{
			keyboardHandler.cooldowntriggerW = false;
			player->cooldownW = 5;
		}
	}

	if (keyboardHandler.cooldowntriggerS)
	{
		player->cooldownS -= dt;
		if (player->cooldownS <= 0)
		{
			keyboardHandler.cooldowntriggerS = false;
			player->cooldownS = 5;
		}
	}

	if (keyboardHandler.cooldowntriggerD)
	{
		player->cooldownD -= dt;
		if (player->cooldownD <= 0)
		{
			keyboardHandler.cooldowntriggerD = false;
			player->cooldownD = 5;
		}
	}

	count += dt;

	//random monster movement every 0.5 sec
	if (count > 0.5)
	{
		count = 0;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster1->velocity.x = 150;
		else
			monster1->velocity.x = -150;
		if (direction2 < 50)
			monster1->velocity.y = 150;
		else
			monster1->velocity.y = -150;


		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster2->velocity.x = 150;
		else
			monster2->velocity.x = -150;
		if (direction2 < 50)
			monster2->velocity.y = 150;
		else
			monster2->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster3->velocity.x = 150;
		else
			monster3->velocity.x = -150;
		if (direction2 < 50)
			monster3->velocity.y = 150;
		else
			monster3->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster4->velocity.x = 150;
		else
			monster4->velocity.x = -150;
		if (direction2 < 50)
			monster4->velocity.y = 150;
		else
			monster4->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster5->velocity.x = 150;
		else
			monster5->velocity.x = -150;
		if (direction2 < 50)
			monster5->velocity.y = 150;
		else
			monster5->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster6->velocity.x = 150;
		else
			monster6->velocity.x = -150;
		if (direction2 < 50)
			monster6->velocity.y = 150;
		else
			monster6->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster7->velocity.x = 150;
		else
			monster7->velocity.x = -150;
		if (direction2 < 50)
			monster7->velocity.y = 150;
		else
			monster7->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster8->velocity.x = 150;
		else
			monster8->velocity.x = -150;
		if (direction2 < 50)
			monster8->velocity.y = 150;
		else
			monster8->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster9->velocity.x = 150;
		else
			monster9->velocity.x = -150;
		if (direction2 < 50)
			monster9->velocity.y = 150;
		else
			monster9->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster10->velocity.x = 150;
		else
			monster10->velocity.x = -150;
		if (direction2 < 50)
			monster10->velocity.y = 150;
		else
			monster10->velocity.y = -150;

		direction1 = rand() % 100;
		direction2 = rand() % 100;

		if (direction1 < 50)
			monster11->velocity.x = 150;
		else
			monster11->velocity.x = -150;
		if (direction2 < 50)
			monster11->velocity.y = 150;
		else
			monster11->velocity.y = -150;

	}

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
	//judge if the player strike landed the monsters
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster1->pos.x + 15 >= player->pos.x - 15 && monster1->pos.y + 15 >= monster1->pos.y - 15) &&
		(monster1->pos.x <= player->pos.x + 30 && monster1->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster1);
		monster1->pos.x = -100;
		monster1->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster2->pos.x + 15 >= player->pos.x - 15 && monster2->pos.y + 15 >= monster2->pos.y - 15) &&
		(monster2->pos.x <= player->pos.x + 30 && monster2->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster2);
		monster2->pos.x = -100;
		monster2->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster3->pos.x + 15 >= player->pos.x - 15 && monster3->pos.y + 15 >= monster3->pos.y - 15) &&
		(monster3->pos.x <= player->pos.x + 30 && monster3->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster3);
		monster3->pos.x = -100;
		monster3->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster4->pos.x + 15 >= player->pos.x - 15 && monster4->pos.y + 15 >= monster4->pos.y - 15) &&
		(monster4->pos.x <= player->pos.x + 30 && monster4->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster4);
		monster4->pos.x = -100;
		monster4->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster5->pos.x + 15 >= player->pos.x - 15 && monster5->pos.y + 15 >= monster5->pos.y - 15) &&
		(monster5->pos.x <= player->pos.x + 30 && monster5->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster5);
		monster5->pos.x = -100;
		monster5->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster6->pos.x + 15 >= player->pos.x - 15 && monster6->pos.y + 15 >= monster6->pos.y - 15) &&
		(monster6->pos.x <= player->pos.x + 30 && monster6->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster6);
		monster6->pos.x = -100;
		monster6->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster7->pos.x + 15 >= player->pos.x - 15 && monster7->pos.y + 15 >= monster7->pos.y - 15) &&
		(monster7->pos.x <= player->pos.x + 30 && monster7->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster7);
		monster7->pos.x = -100;
		monster7->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster8->pos.x + 15 >= player->pos.x - 15 && monster8->pos.y + 15 >= monster8->pos.y - 15) &&
		(monster8->pos.x <= player->pos.x + 30 && monster8->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster8);
		monster8->pos.x = -100;
		monster8->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster9->pos.x + 15 >= player->pos.x - 15 && monster9->pos.y + 15 >= monster9->pos.y - 15) &&
		(monster9->pos.x <= player->pos.x + 30 && monster9->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster9);
		monster9->pos.x = -100;
		monster9->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster10->pos.x + 15 >= player->pos.x - 15 && monster10->pos.y + 15 >= monster10->pos.y - 15) &&
		(monster10->pos.x <= player->pos.x + 30 && monster10->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster10);
		monster10->pos.x = -100;
		monster10->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
	if ((player->skilla || player->skills || player->skillw || player->skilld) && ((monster11->pos.x + 15 >= player->pos.x - 15 && monster11->pos.y + 15 >= monster11->pos.y - 15) &&
		(monster11->pos.x <= player->pos.x + 30 && monster11->pos.y <= player->pos.y + 30)))
	{
		entities.remove(monster11);
		monster11->pos.x = -100;
		monster11->pos.y = -100;
		player->skilla = false;
		player->skillw = false;
		player->skills = false;
		player->skilld = false;
		return;
	}
}

void SecondPlayScreenState::render()
{
	SDL_RenderCopy(GlobalGameState::renderer, background, &backgroundSrc, &backgroundDest);
	SDL_RenderCopy(GlobalGameState::renderer, w, &wsrc, &wdest);
	SDL_RenderCopy(GlobalGameState::renderer, s, &ssrc, &sdest);
	SDL_RenderCopy(GlobalGameState::renderer, a, &asrc, &adest);
	SDL_RenderCopy(GlobalGameState::renderer, d, &dsrc, &ddest);
	for (auto e : entities)
	{
		e->draw(0.6);
	}
	
	stringstream s1, s2, s3, s4;
	s1.precision(1);
	s2.precision(1);
	s3.precision(1);
	s4.precision(1);
	s1 << fixed << player->cooldownW;
	s2 << fixed << player->cooldownS;
	s3 << fixed << player->cooldownA;
	s4 << fixed << player->cooldownD;

	string temp = s1.str();
	const char* location1 = temp.c_str();
	SDL_Color textColor = { 123, 0, 34, 0 };
	//LOAD UP OUR FONT
	TTF_Font* font2 = TTF_OpenFont("assets/yahei.ttf", 16); //params: font file, font size
															//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, location1, textColor);
	//convert surface to texture
	SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface2);
	//delete surface properly
	SDL_FreeSurface(textSurface2);

	//text destination
	SDL_Rect textDestination1;
	textDestination1.x = 305;
	textDestination1.y = 5;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture2, NULL, NULL, &textDestination1.w, &textDestination1.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture2, NULL, &textDestination1);
	//cleanup font
	TTF_CloseFont(font2);
	//clean up textures
	SDL_DestroyTexture(textTexture2);



	temp = s2.str();
	const char* location2 = temp.c_str();
	//LOAD UP OUR FONT
	TTF_Font* font3 = TTF_OpenFont("assets/yahei.ttf", 16); //params: font file, font size
															//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface3 = TTF_RenderText_Blended(font3, location2, textColor);
	//convert surface to texture
	SDL_Texture* textTexture3 = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface3);
	//delete surface properly
	SDL_FreeSurface(textSurface3);

	//text destination
	SDL_Rect textDestination2;
	textDestination2.x = 305;
	textDestination2.y = 35;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture3, NULL, NULL, &textDestination2.w, &textDestination2.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture3, NULL, &textDestination2);
	//cleanup font
	TTF_CloseFont(font3);
	//clean up textures
	SDL_DestroyTexture(textTexture3);




	temp = s3.str();
	const char* location3 = temp.c_str();
	//LOAD UP OUR FONT
	TTF_Font* font4 = TTF_OpenFont("assets/yahei.ttf", 16); //params: font file, font size
															//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface4 = TTF_RenderText_Blended(font4, location3, textColor);
	//convert surface to texture
	SDL_Texture* textTexture4 = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface4);
	//delete surface properly
	SDL_FreeSurface(textSurface4);

	//text destination
	SDL_Rect textDestination3;
	textDestination3.x = 275;
	textDestination3.y = 35;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture4, NULL, NULL, &textDestination3.w, &textDestination3.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture4, NULL, &textDestination3);
	//cleanup font
	TTF_CloseFont(font4);
	//clean up textures
	SDL_DestroyTexture(textTexture4);



	temp = s4.str();
	const char* location4 = temp.c_str();
	//LOAD UP OUR FONT
	TTF_Font* font5 = TTF_OpenFont("assets/yahei.ttf", 16); //params: font file, font size
															//create a sruface using this font to display some sort of message
	SDL_Surface* textSurface5 = TTF_RenderText_Blended(font5, location4, textColor);
	//convert surface to texture
	SDL_Texture* textTexture5 = SDL_CreateTextureFromSurface(GlobalGameState::renderer, textSurface5);
	//delete surface properly
	SDL_FreeSurface(textSurface5);

	//text destination
	SDL_Rect textDestination4;
	textDestination4.x = 335;
	textDestination4.y = 35;
	//get width and height from texture and set it for the destination
	SDL_QueryTexture(textTexture5, NULL, NULL, &textDestination4.w, &textDestination4.h);

	SDL_RenderCopy(GlobalGameState::renderer, textTexture5, NULL, &textDestination4);
	//cleanup font
	TTF_CloseFont(font5);
	//clean up textures
	SDL_DestroyTexture(textTexture5);

	SDL_RenderPresent(GlobalGameState::renderer);
}

bool SecondPlayScreenState::onEnter()
{
	cout << "Enter second Gameplay state" << endl;
	return true;
}

bool SecondPlayScreenState::onExit()
{
	cout << "Exit second Gameplay state" << endl;
	return true;
}
