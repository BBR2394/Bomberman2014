/*
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
** Last update mer. mai  14 14:19:39 2014 sofian casier
//
*/

#include "GameEngine.hpp"

bool		GameEngine::Playing()
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
	if (_input.getInput(SDLK_DOWN, true))
    	temp->translate(glm::vec3(0, -1, 0));
  	if (_input.getInput(SDLK_UP, true))
    	temp->translate(glm::vec3(0, 1, 0));
	if (_input.getInput(SDLK_LEFT, true))
		temp->translate(glm::vec3(-1, 0, 0));
	if (_input.getInput(SDLK_RIGHT, true))
		temp->translate(glm::vec3(1, 0, 0));
	if (_input.getInput(SDLK_a, true))
		temp->translate(glm::vec3(0, 0, -1));
	if (_input.getInput(SDLK_z, true))
		temp->translate(glm::vec3(0, 0, 1));
	
	return true;
}