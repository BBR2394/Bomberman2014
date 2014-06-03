/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mer. juin  04 00:08:35 2014 sofian casier
*/

#include <unistd.h>
#include "GameEngine.hpp"

GameEngine::GameEngine()
{
  _menu = NULL;
  _cursor = NULL;
  _cursor_map = NULL;
  _play1 = NULL;
  _play2 = NULL;
  _scene = 0;
  _index_cursor = 0;
  _select_map = 0;
  _save = new Save("./file");
  _map_chosen = 0;
  _check_select_map = false;
  _game_type = 0;
  _launch = false;
}

GameEngine::~GameEngine()
{
	for (size_t i = 0; i < _objects.size(); i++)
		delete _objects[i];
}

bool      GameEngine::Launch_mus()
{
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
  Mix_Music *musique;
  musique = Mix_LoadMUS("includes/music/title.wav");
  if (!musique)
  {
    std::cout << "Error on Loading Audio" << std::endl;
    return (false);
  }
  Mix_PlayMusic(musique, -1);
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2.5);
  _music_fight = false;
  return (true);
}

bool			GameEngine::initialize()
{
  begin_sec_video();
  if (!_context.start(1000, 800, "Bomberman EpiK"))
  {
    std::cout << "error on start context" << std::endl; 
    return false;
  }
  Launch_mus();
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) || !_shader.build())
  {
    std::cout << "shader failed" << std::endl;
    return (false);
  }
  _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/ground.tga");
  _floor->setSize(15, 15, 3);
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

void      GameEngine::Set_One_Player()
{
  _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
  _save->setNbPlayer(1);
  _floor->setType(1);
  this->createMap(_floor->getX(), _floor->getY(), 1);
  _scene = 3;
  _menu = NULL;
  _cursor = NULL;
  _game_type = 0;
  _launch = true;
}

void      GameEngine::Set_Two_Players()
{
  _floor->setType(1);
  this->createMap(_floor->getX(), _floor->getY(), 2);
  _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
  _save->setNbPlayer(2);
  _scene = 3;
  _menu = NULL;
  _cursor = NULL;
  _game_type = 0;
  _launch = true;
}

bool			GameEngine::update()
{
  static int nb_player = 0;

  if (_scene == 0)
  {
    if (this->Go_To_Menu() == 1)
      Update_Menu();
    if (this->Go_To_Menu() == -1)
      return (false);
  }
  else if (_scene == 1)
  {
    if (this->Menu_choice() == false)
     return (false);
 }
 else if (_scene == 10)
 {
  if ((Choose_your_map()) == false)
    return false;
  if (_scene == 3)
  {
    if ((this->Create_loading()) == false)
      return (false);
  }
  }
  else if (_game_type == 1) 
  {
    Set_One_Player();
    nb_player = 1;
  }
  else if (_game_type == 2)
  {
    Set_Two_Players();
    nb_player = 2;
  }
  else if (_scene == 3 && _launch == true)
  {
    if ((this->Playing(_clock, nb_player) == false))
      return false;
  }
_context.updateClock(_clock);
_context.updateInputs(_input);
return (true);
}

void			GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  if (_menu != NULL)
    _menu->draw(_shader, _clock);
  if (_cursor != NULL)
    _cursor->draw(_shader, _clock);
  if (_cursor_map != NULL)
    _cursor_map->draw(_shader, _clock);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  if (_scene == 3 && _launch == true)
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
      for (size_t i = 0; i < _explosion.size(); ++i)
        _explosion[i]->draw(_shader, _clock);
    }
  _context.flush();
}