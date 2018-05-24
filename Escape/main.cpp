#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <time.h>
#include "Animation.h"
#include "Entity.h"
#include "Player.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

//texture pointer
SDL_Texture* texture;
SDL_Rect sourceRectangle;
SDL_Rect destinationRectangle;


int main(int argc, char **argv)
{
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return -1;
	}

	if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
	{
		cout << "sdl image did not load: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		cout << "sdl image did not load: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	window = SDL_CreateWindow("Escape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		return -1;
	}

	if (TTF_Init() != 0)
	{
		//if failed, complain about it
		cout << "SDL TTF FAILED!" << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}


	SDL_Texture *background = IMG_LoadTexture(renderer, "assets/background.jpg");
	SDL_Texture *run = IMG_LoadTexture(renderer, "assets/player1.png");
	SDL_Rect src = { 0,0,640,480 };
	SDL_Rect dest = { 0,0,640,480 };

	Animation anime1(run, renderer, 6, 63.33, 64, 0.1);

	Player *p1 = new Player();
	Vector playerPosition(0, 240);
	p1->setPosition(playerPosition);
	p1->setAnimation(&anime1);
	p1->setRenderer(renderer);

	//Load up our font
	TTF_Font* font1 = TTF_OpenFont("assets/yahei.ttf", 50);
	TTF_Font* font2 = TTF_OpenFont("assets/yahei.ttf", 25);


	//text destination
	SDL_Rect textDestination1;
	textDestination1.x = 230;
	textDestination1.y = 70;

	//text destination
	SDL_Rect textDestination2;
	textDestination2.x = 170;
	textDestination2.y = 350;
	//get width and height from texture and set it for the destination
	SDL_Color textColor1 = { 123,0,34,0 };
	SDL_Color textColor2 = { 123,0,34,0 };

	//text deley time
	float textDelayTime = 0;

	bool loop = true;
	Uint32 lastUpdate = SDL_GetTicks();
	while (loop)
	{
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
		float dt = timeDiff / 1000.0;
		lastUpdate = SDL_GetTicks();

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, background, &src, &dest);

		p1->update(dt);
		if (p1->pos.x <= 280)
			p1->pos.x += 0.8;
		p1->draw();

		//add text delay time
		textDelayTime += dt;
		//text title
		if (textDelayTime >= 1)
		{
			textColor1.r = rand() % 256;
			textColor1.g = rand() % 256;
			textColor1.b = rand() % 256;
			textColor2.r = rand() % 256;
			textColor2.g = rand() % 256;
			textColor2.b = rand() % 256;
			textDelayTime = 0;
		}
		SDL_Surface* textSurface1 = TTF_RenderText_Blended(font1, "Escape", textColor1);
		//convert surface to texture
		SDL_Texture* textTexture1 = SDL_CreateTextureFromSurface(renderer, textSurface1);
		//delete surface properly
		SDL_FreeSurface(textSurface1);
		SDL_QueryTexture(textTexture1, NULL, NULL, &textDestination1.w, &textDestination1.h);

		//text below
		SDL_Surface* textSurface2 = TTF_RenderText_Blended(font2, "Press any key to continue", textColor2);
		//convert surface to texture
		SDL_Texture* textTexture2 = SDL_CreateTextureFromSurface(renderer, textSurface2);
		//delete surface properly
		SDL_FreeSurface(textSurface2);
		SDL_QueryTexture(textTexture2, NULL, NULL, &textDestination2.w, &textDestination2.h);



		//Draw Text
		SDL_RenderCopy(renderer, textTexture1, NULL, &textDestination1);
		SDL_RenderCopy(renderer, textTexture2, NULL, &textDestination2);

		SDL_RenderPresent(renderer);

		SDL_DestroyTexture(textTexture1);
		SDL_DestroyTexture(textTexture2);

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				loop = false;
		}
	}

	//clean up any game objects
	delete p1;

	//clean up textures
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(run);


	//clear font and text
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);
	//SDL_DestroyTexture(textTexture);

	//clean up renderer and window properly (aka clean up dynamic memory)
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//shut down subsystems and cleanup any setup it did earlier in sdl_init
	SDL_Quit();

	system("pause");

	return 0;
}
