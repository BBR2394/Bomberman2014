/*
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Mon May 19 15:37:29 2014 sofian casier
//
*/

#include <unistd.h>
#include "GameEngine.hpp"

bool		GameEngine::Playing(gdl::Clock const &clock)
{
	AObject *temp;

	if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
		return false;
	if (_music_fight == false)
	{
	  Mix_Chunk *music;
	  Mix_Chunk *fight_music;
	  Mix_Music *fight;

	  fight = Mix_LoadMUS("includes/music/fight_1.wav");
	  Mix_PlayMusic(fight, -1);
	  music = Mix_LoadWAV("includes/music/ready.wav");
	  Mix_PlayChannel(1, music, 0);
	  sleep(2);
	  music = Mix_LoadWAV("includes/music/go.wav");
	  Mix_PlayChannel(1, music, 0);
	  _music_fight = true;
	}
	temp = _objects.back();
	temp->update(clock, _input);
	return true;
}
