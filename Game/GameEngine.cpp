/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update jeu. mai  22 16:51:36 2014 sofian casier
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
  _music_fight = false;
  _scene = 0;
  _index_cursor = 0;
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
      this->createMap(19, 18);
      _scene = 2;
      sleep(1);
    }
  else if (_scene == 2)
    {
      if ((this->Playing(_clock)) == false)
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
  _context.flush();
}
