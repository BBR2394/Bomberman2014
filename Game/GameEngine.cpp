/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
// Last update Thu May 22 17:31:29 2014 Bertrand-Rapello Baptiste
*/

#include <unistd.h>
#include "GameEngine.hpp"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
	for (size_t i = 0; i < _objects.size(); i++)
		delete _objects[i];
}

bool			GameEngine::initialize()
{
  if (!_context.start(1000, 800, "My bomberman!"))
    {
      std::cout << "error on start context" << std::endl; 
      return false;
    }
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) || !_shader.build())
    {
      std::cout << "shader failed" << std::endl;
      return (false);
    }
  if ((Mix_Init(MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MP3)) == -1)
    {
      std::cout << "Error on SDL Audio Init" << std::endl;
      return false;
    }
  if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096) == -1)
    {
      std::cout << "Error on Open Audio" << std::endl;
      return (false);
    }
  Mix_Chunk *musique;
  musique = Mix_LoadWAV("includes/music/test_chuck.wav");
  if (!musique)
    {
      std::cout << "Error on Loading Audio" << std::endl;
      return (false);
    }
  Mix_PlayChannel(1, musique, 0);
  _play1 = NULL;
  _play2 = NULL;
  _music_fight = false;
  _scene = 0;
  _index_cursor = 0;
  _save = new Save("./file");
  _floor = new Background(0, 0, 1, 0, 0, 0, "./includes/images/ground.tga");
  _floor->setSize(10, 11, 3);
  if (_floor->initialize() == false)
    return (false);
  glm::mat4 projection;
  glm::mat4 transformation;
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  if ((this->Create_Menu()) == false)
    return (false);
  return (true); 
}

bool			GameEngine::update()
{
  static int nb_player = 0;

  if (_scene == 0)
    {
      if (this->Menu_choice() == false)
	return (false);
    }
  else if (_scene == 1) 
    {
      size_t	i;
      i = 0;
      while  (i < _objects.size())
       delete _objects[i++];
      _objects.erase (_objects.begin(), _objects.begin()+i);
      _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
      _save->setNbPlayer(1);
      _floor->setType(2);
      this->createMap(_floor->getX(), _floor->getY(), 1);
      _scene = 2;
      for (size_t i = 0; i < _map.size(); ++i)
	_map[i]->draw(_shader, _clock);
      nb_player = 1;
    }
  else if (_scene == 3)
    {
      size_t i;
      i = 0;
      while  (i < _objects.size())
	delete _objects[i++];
      _objects.erase (_objects.begin(), _objects.begin()+i);
      _floor->setType(1);
      this->createMap(_floor->getX(), _floor->getY(), 2);
      _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
      _save->setNbPlayer(2);
      _scene = 2;
      for (size_t i = 0; i < _map.size(); ++i)
	_map[i]->draw(_shader, _clock);
      nb_player = 2;
    }
  else if (_scene == 2)
    {
      if ((this->Playing(_clock, nb_player) == false))
        return false;
    }
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  /*  if (_scene != 0)
    {
      for (size_t i = 0; i < _objects.size(); ++i)
        _objects[i]->update(_clock, _input);
	}*/
  return (true);
}

void			GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  if (_scene == 2)
    {
      for (size_t i = 0; i < _map.size(); ++i)
	_map[i]->draw(_shader, _clock);
      //for (size_t i = 0; i < _players.size(); ++i)                                               
      //_players[i]->draw(_shader, _clock);                                                      
      if (_play1 != NULL)
	_play1->draw(_shader, _clock);
      if (_play2 != NULL)
	_play2->draw(_shader, _clock);
      _floor->draw(_shader, _clock);
      for (size_t i = 0; i < _bombes.size(); ++i)
	_bombes[i]->draw(_shader, _clock);
    }
  _context.flush();
}
