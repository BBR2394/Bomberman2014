/*
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Fri May 30 11:28:38 2014 Bertrand-Rapello Baptiste
//
*/

#include <unistd.h>
#include "GameEngine.hpp"

void		GameEngine::Fight_mus()
{
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
}
bool		GameEngine::Playing(gdl::Clock const &clock, int nb_player)
{
	Bombe *temp;
	int c;

	if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
		return false;
	Fight_mus();
	//temp = _objects.back();
	//temp->update(clock, _input);
        if (_input.getInput(SDLK_b, true))
          {
	  std::cout << "les position de visé : " << _play1->getXTarget() << " " << _play1->getYTarget()  << " " << _play1->getZTarget() << std::endl;
            temp = new Bombe(glm::vec3(_play1->getXTarget(), _play1->getYTarget(), _play1->getZTarget()), glm::vec3(0, 0, 0), "./includes/images/bombe.tga");
	    std::cout << "bombe test ..." << std::endl;
            if (temp->initialize() == false)
              return (false);
            temp->setTime(100);
            _bombes.push_back(temp);
          }

        for (size_t i = 0; i < _bombes.size(); ++i)
          {
            _bombes[i]->update(_clock, _input);
            if (_bombes[i]->getTime() <= 0)
              {
                temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
                if (temp->initialize() == false)
                  return (false);
                temp->setTime(10);
                _explosion.push_back(temp);
		c = 0;
                while (c <= _play1->getSizeExplo())
                  {
                    temp = new Bombe(glm::vec3(_bombes[i]->getX()+c, _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
                    if (temp->initialize() == false)
                      return (false);
                    temp->setTime(10);
                    _explosion.push_back(temp);
                    c++;
                  }
                c = 0;
                while (c <= _play1->getSizeExplo())
                  {
                    temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY()+c, _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
                    if (temp->initialize() == false)
                      return (false);
                    temp->setTime(10);
                    _explosion.push_back(temp);
                    c++;
                  }

                c = 0;
                while (c <= _play1->getSizeExplo())
                  {
                    temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY()-c, _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
                    if (temp->initialize() == false)
                      return (false);
                    temp->setTime(10);
                    _explosion.push_back(temp);
                    c++;
                  }
                c = 0;
                while (c <= _play1->getSizeExplo())
                  {
                    temp = new Bombe(glm::vec3(_bombes[i]->getX()-c, _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
                    if (temp->initialize() == false)
                      return (false);
                    temp->setTime(10);
                    _explosion.push_back(temp);
                    c++;
                  }
                //_play1->setSizeExplo(c++);
		
                _bombes.erase(_bombes.begin()+i);
              }
          }

        for (size_t i = 0; i < _explosion.size(); ++i)
          {
            _explosion[i]->update(_clock, _input);
            if (_explosion[i]->getTime() <= 0)
              _explosion.erase(_explosion.begin()+i);
          }
	if (_input.getInput(SDLK_t, true))
		_save->writeInFile();
	_play1->update(clock, _input, _mapcols);
	if (nb_player == 2)
		_play2->update(clock, _input);


	return true;
}
