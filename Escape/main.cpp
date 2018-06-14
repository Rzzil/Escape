#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>
#include <list>
#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "SoundManager.h"
#include "InputHandler.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "GlobalGameState.h"
#include "MenuScreenState.h"

using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;



int main(int argc, char **argv)
{
	//initiate SDL with the subsystems you want to use ie SDL_INIT_VIDEO
	//we're initaliasing all of them (sound, input, video etc)
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "SDL Fail initialised!!!\n";
		return -1; //failed, dont continue rest of main code
	}
	else
	{
		cout << "SDL initialised success!!!\n";
	}

	//NEED TO INIT SDL_Image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "sdl image did not load: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//INIT MIXER
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "mixer didn't initialise" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//create window, params are: window title, window pos x, pos y, width, height, window flags
	window = SDL_CreateWindow("Escape", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);

	if (window != NULL) {
		cout << "Window created!" << endl;
	}
	else
	{
		cout << "Failed to create window!" << endl;
		return -1;
	}

	//create renderer to help draw stuff to the screen
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer != NULL)
	{
		cout << "Renderer created!" << endl;
	}
	else
	{
		cout << "Renderer FAILED!" << endl;
		return -1;
	}
	//get global game state to reference this renderer for global access
	GlobalGameState::renderer = renderer;

	//INIT sdl ttf
	if (TTF_Init() != 0)
	{
		//if failed, complain about it
		cout << "SDL TTF FAILED!" << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	GlobalGameState::gameStateMachine.pushState(new MenuScreenState());

	Mix_Music* music = Mix_LoadMUS("assets/BackGround.ogg");
	if (music == NULL) {
		cout << "Music failed to load!!!" << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	//play music
	//params: music, how many times to play song(-1 means infinite loop)
	Mix_PlayMusic(music, -1);

	SoundManager::soundManager.loadSound("Action", "assets/skillSound.wav");
	bool loop = true;
	while (loop) {

		GlobalGameState::gameStateMachine.update();
		GlobalGameState::gameStateMachine.render();

		if (GlobalGameState::quitGame || GlobalGameState::gameStateMachine.gameStates.empty())
			loop = false;
	}
	//clean up any extra screen game states
	GlobalGameState::gameStateMachine.clearAll();

	//stop music from playing
	Mix_PauseMusic();
	//delete song memory
	Mix_FreeMusic(music);

	//clean up renderer and window properly (aka clean up dynamic memory)
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//shut down subsystems and cleanup any setup it did earlier in sdl_init
	SDL_Quit();

	system("pause");

	return 0;
}
