/*
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Sat Jun 14 15:17:19 2014 Koszyczek Laurent
//
*/

#include <unistd.h>
#include "GameEngine.hpp"

void            GameEngine::Fight_mus()
{
  if (_music_fight == false)
    {
      Mix_Chunk *music;
      Mix_Chunk *fight_music;
      Mix_Music *fight;

      if (_map_chosen == 1)
	fight = Mix_LoadMUS("includes/music/fight_1.wav");
      if (_map_chosen == 2)
	fight = Mix_LoadMUS("includes/music/fight_2.wav");
      if (_map_chosen == 3)
	fight = Mix_LoadMUS("includes/music/fight_3.wav");
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
  IA *temp2;
  int c;

  if (_input.getKey(SDLK_ESCAPE, true) || _input.getInput(SDL_QUIT, true))
    {
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
      _shader.setUniform("view", transformation);
      if (_pause_cond == false)
        {
          _pause_cond = true;
          return false;
        }
      else
        {
          _pause_cond = false;
          _pause = NULL;
        }
    }
  Fight_mus();
  if (_input.getInput(SDLK_F3, true))
    {
      _angle -= 0.5;
      if (_angle <= -10)
        _angle = -10;
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, _angle, 20), glm::vec3(0, 0, 0), glm::vec3(_rotation, 1, _rotation));
      _shader.setUniform("view", transformation);
    }
  if (_input.getInput(SDLK_F4, true))
    {
      _angle += 0.5;
      if (_angle >= 10)
        _angle = 10;
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, _angle, 20), glm::vec3(0, 0, 0), glm::vec3(_rotation, 1, _rotation));
      _shader.setUniform("view", transformation);
    }
  if (_input.getInput(SDLK_F5, true))
    {
      _rotation += 0.1;
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, _angle, 20), glm::vec3(0, 0, 0), glm::vec3(_rotation, 1, _rotation));
      _shader.setUniform("view", transformation);
    }
  if (_input.getInput(SDLK_F6, true))
    {
      _rotation -= 0.1;
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, _angle, 20), glm::vec3(0, 0, 0), glm::vec3(_rotation, 1, _rotation));
      _shader.setUniform("view", transformation);
    }
  if (_input.getInput(SDLK_F10, true))
    {
      _angle = 0;
      _rotation = 0;
      glm::mat4 transformation;
      transformation = glm::lookAt(glm::vec3(0, _angle, 20), glm::vec3(0, 0, 0), glm::vec3(_rotation, 1, _rotation));
      _shader.setUniform("view", transformation);
    }
  //temp = _objects.back();
  //temp->update(clock, _input);
  /*if (_input.getInput(SDLK_b, true) && _play1->getNbBombe() < _play1->getMaxNbBombe())
    {
    PlaceBombe(clock, _play1);
    /*
    std::cout << "les position de visé : " << _play1->getX() << " " << _play1->getY()  << " " << _play1->getZ() << std::endl;
    temp = new Bombe(glm::vec3(_play1->getX(), _play1->getY(), _play1->getZ()), glm::vec3(0, 0, 0), "./includes/images/bombe.tga");
    std::cout << "bombe test ..." << std::endl;
    if (temp->initialize() == false)
    return (false);
    Mix_Chunk *bomb;
    bomb = Mix_LoadWAV("includes/music/put_bomb.wav");
    Mix_PlayChannel(1, bomb, 0);
    temp->setTime(100);
    temp->setPlayerSeter(1);
    _bombes.push_back(temp);
    _play1->setNbBombe(_play1->getNbBombe()+1);*/
  for (size_t i = 0; i < _bombes.size(); ++i)
    {
      int size = (getLen(_mapcols[0]) / 2);
      _bombes[i]->update(_clock, _input);
      if (_mapcols[((int)_bombes[i]->getY()*-1) + size][(int)_bombes[i]->getX() + size] == '0')
        _mapcols[((int)_bombes[i]->getY()*-1) + size][(int)_bombes[i]->getX() + size] = '4';
      if (_bombes[i]->getTime() <= 0)
	     {
	         int sizeexplo;
          //sizeexplo = (whichPlayerFromID(_bombes[i]->getPlayerSeter()))->getSizeExplo();
          this->Bombing(_clock, i, 2);
          _mapcols[((int)_bombes[i]->getY()*-1) + size][(int)_bombes[i]->getX() + size] = '0';
	     }
    }

  for (size_t i = 0; i < _explosion.size(); ++i)
    {
      _explosion[i]->update(_clock, _input);
      if (_explosion[i]->getTime() <= 0)
	_explosion.erase(_explosion.begin()+i);
    }
  if (_input.getInput(SDLK_t, true))
    _save->writeInFile(_mapcols);

  if (_play1 != NULL)
  {
  _play1->update(clock, _input, _mapcols);
  if (_play1->poseBomb == true && _play1->getNbBombe() < _play1->getMaxNbBombe())
    {
      _play1->poseBomb = false;
      PlaceBombe(clock, _play1);
    }
  }
  if (nb_player == 2 && _play2 != NULL)
  {
    _play2->update(clock, _input, _mapcols);
  if (_play2->poseBomb == true && _play2->getNbBombe() < _play2->getMaxNbBombe())
    {
      _play2->poseBomb = false;
      PlaceBombe(clock, _play2);
    }
  }

  for (size_t i = 0; i < _robot.size(); ++i)
    {
      _robot[i]->update(clock, _input, _mapcols);
      if (_robot[i]->poseBomb == true)
        {
          temp2 = _robot[i];
          _robot[i]->poseBomb = false;
          std::cout << "l'ia va poser une bombe son id : " << temp2->getID() << std::endl;
          PlaceBombeIA(clock, temp2);
        }
    }
  for (size_t i = 0; i < _bonux.size(); ++i)
    _bonux[i]->update(clock, _input, _mapcols);
  return true;
}
