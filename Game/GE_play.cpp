/*
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Thu May 15 17:29:56 2014 Bertrand-Rapello Baptiste
//
*/

#include "GameEngine.hpp"

bool		GameEngine::Playing(gdl::Clock const &clock)
{
	AObject *temp;

	if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
		return false;
	if (_music_fight == false)
	{
		_Sound->StopMusic();
		_music_fight = true;
		_Fight = new Sound("./includes/music/fight_1.wav", 22050);
		_Fight->launch_music();
	}
	temp = _objects.back();
	temp->update(clock, _input);
	return true;
}
