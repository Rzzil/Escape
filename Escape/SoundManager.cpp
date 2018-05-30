#include "SoundManager.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
	//delete all sound effects properly
	for (soundListing listing : sounds)
	{
		Mix_FreeChunk(listing.sound);
	}
}

void SoundManager::loadSound(string name, string file) {
	soundListing listing;
	listing.name = name;
	listing.sound = Mix_LoadWAV(file.c_str());

	//add sound listing to our list of sounds
	sounds.push_back(listing);
}
void SoundManager::playSound(string name) {
	//look for sound in list
	//foreach loop: for each Soundlisting which I'll temporarily call listing in sounds
	for (soundListing listing : sounds)
	{
		//if this listing matches search name, play it
		if (listing.name == name) {
			//params: which channel to play on (-1 takes first free channel), sound to play, how many times to loop this sound (0 means play once, -1 infinite loop :O)
			Mix_PlayChannel(-1, listing.sound, 0);
			break; //exit the loop so we don't waste any more time here
		}
	}
}

//initalising our static soundManager
SoundManager SoundManager::soundManager;