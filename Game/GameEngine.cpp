/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update dim. juin  15 19:30:54 2014 sofian casier
*/

#include <unistd.h>
#include "GameEngine.hpp"

void        GameEngine::set_Arg(char *arg)
{
  std::string video(arg);
  if ((video.compare("-V") != 0) && (video.compare("-v") != 0))
    _cond_video = true;
  else
    _cond_video = false;
}

GameEngine::GameEngine()
{
  _angle = 0;
  _rotation = 0;
  _zoom = 20;
  _menu = NULL;
  _cursor = NULL;
  _cursor_map = NULL;
  _play1 = NULL;
  _play2 = NULL;
  _scene = 0;
  _index_cursor = 0;
  _index_pause = 0;
  _select_map = 0;
  _save = new Save("Save");
  _map_chosen = 0;
  _check_select_map = false;
  _game_type = 0;
  _launch = false;
  _pause_cond = false;
  _pause = NULL;
  _end_of_game = false;
  _end = NULL;
}

bool      GameEngine::ReturnToMenu()
{
  if (_play1 == NULL || _play2 == NULL)
  {
   delete _play1;
   if (_play2 != NULL)
    delete _play2;
  for (size_t i = 0; i < _bombes.size(); i++)
    delete _bombes[i];
  for (size_t i = 0; i < _robot.size(); i++)
    delete _robot[i];
  for (size_t i = 0; i < _bonux.size(); i++)
    delete _bonux[i];
  for (size_t i = 0; i < _explosion.size(); i++)
    delete _explosion[i];
  for (size_t i = 0; i < _map.size(); i++)
    delete _map[i];
  for (size_t i = 0; i < _cubeDestr.size(); i++)
    delete _cubeDestr[i];
  if (_floor)
    delete _floor;

  _play1 = NULL;
  _play2 = NULL;
  _map.erase(_map.begin(), _map.end());
  _bombes.erase(_bombes.begin(), _bombes.end());
  _bonux.erase(_bonux.begin(), _bonux.end());
  _explosion.erase(_explosion.begin(), _explosion.end());
  _cubeDestr.erase(_cubeDestr.begin(), _cubeDestr.end());
  _robot.erase(_robot.begin(), _robot.end());
  _objects.erase(_objects.begin(), _objects.end());
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
  _end = NULL;
  _scene = 0;
  _index_cursor = 0;
  _index_pause = 0;
  _select_map = 0;
  _map_chosen = 0;
  _game_type = 0;
  _angle = 0;
  _rotation = 0;
  _end_of_game = false;
  _check_select_map = false;
  _pause_cond = false;
  _launch = false;
  _cursor = NULL;
  _cursor_map = NULL;
  _pause = NULL;
  _arena = NULL;
  glm::mat4 transformation;
  transformation = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.setUniform("view", transformation);
  if ((this->Create_Menu()) == false)
    return (false);
  return (true);
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
  if (_cond_video == true)
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
  _floor->setType(1);
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

bool      GameEngine::Set_One_Player()
{
  _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
  _save->setNbPlayer(1);
  if (_map_chosen == 1)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/ground.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(1);
      this->createMap(_floor->getX(), _floor->getY(), 1);
    }
  if (_map_chosen == 2)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/back_grass.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(2);
      this->createMap_2(_floor->getX(), _floor->getY(), 1);
    }
  if (_map_chosen == 3)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/water_map.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(1);
      this->createMap_3(_floor->getX(), _floor->getY(), 1);
    }
  _scene = 3;
  _menu = NULL;
  _cursor = NULL;
  _game_type = 0;
  _launch = true;
  return true;
}

bool      GameEngine::Set_Two_Players()
{
  if (_map_chosen == 1)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/ground.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(1);
      this->createMap(_floor->getX(), _floor->getY(), 2);
    }
  if (_map_chosen == 2)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/back_grass.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(2);
      this->createMap_2(_floor->getX(), _floor->getY(), 2);
    }
  if (_map_chosen == 3)
    {
      _floor = new Background(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), "./includes/images/water_map.tga");
      _floor->setSize(15, 15, 3);
      if (_floor->initialize() == false)
	return (false);
      _floor->setType(1);
      this->createMap_3(_floor->getX(), _floor->getY(), 2);
    }
  _save->setSize(_floor->getX(), _floor->getY(), 1, 2);
  _save->setNbPlayer(2);
  _scene = 3;
  _menu = NULL;
  _cursor = NULL;
  _game_type = 0;
  _launch = true;
  return (true);
}

bool      GameEngine::Go_To_Pause()
{
  if (_pause == NULL)
  {
    _pause = new Menu(glm::vec3(0, 0, -5), AObject::MENU, "./includes/images/bomberman_pause_1.tga");
    if (_pause->initialize() == false)
      return (false);
  }
  if (_input.getInput(SDLK_ESCAPE, true) || _input.getInput(SDL_QUIT, true))
    {
      _pause_cond = false;
      _pause = NULL;
    }
    if (_input.getInput(SDLK_RIGHT, true))
    {
      _index_pause = 1;
      _pause->Change_texture("./includes/images/bomberman_pause_2.tga");
    }
    if (_input.getInput(SDLK_LEFT, true))
    {
      _index_pause = 0;
      _pause->Change_texture("./includes/images/bomberman_pause_1.tga");
    }
    if (_input.getInput(SDLK_RETURN, true))
    {
      _pause_cond = false;
      _pause = NULL;
      if (_index_pause == 0)
        return true;
      else
        return false;
    }
    if (_input.getInput(SDLK_F1, true))
      return false;
  return true;
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
  {
    if (ReturnToMenu() == false)
      return false;
    sleep(1);
  }
      if (_scene == 3)
  {
    if ((this->Create_loading()) == false)
      return (false);
  }
    }
  else if (_game_type == 1) 
    {
      if ((Set_One_Player()) == false)
        return false;
      nb_player = 1;
    }
  else if (_game_type == 2)
    {
      if ((Set_Two_Players()) == false)
        return false;
      nb_player = 2;
    }
  else if (_scene == 3 && _launch == true)
    {
      if (_pause_cond == true)
      {
    if ((Go_To_Pause()) == false)
    {
      if (ReturnToMenu() == false)
       return false;
     sleep(1);
   }
 }
 else
  if ((Playing(_clock, nb_player)) == false && _pause_cond == false)
  {
    if (ReturnToMenu() == false)
      return false;
    sleep(3);
  }
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
  if (_pause != NULL)
    _pause->draw(_shader, _clock);
  if (_scene == 3 && _launch == true && _pause_cond == false)
    {
      if (_arena != NULL)
        _arena->draw(_shader, _clock);
      for (size_t i = 0; i < _objects.size(); ++i)
        _objects[i]->draw(_shader, _clock);
      for (size_t i = 0; i < _map.size(); ++i)
	_map[i]->draw(_shader, _clock);
      if (_play1 != NULL)
	     _play1->draw(_shader, _clock);
      if (_play2 != NULL)
	_play2->draw(_shader, _clock);
    _floor->draw(_shader, _clock);
      for (size_t i = 0; i < _robot.size(); ++i)
        _robot[i]->draw(_shader, _clock);
      for (size_t i = 0; i < _bombes.size(); ++i)
	_bombes[i]->draw(_shader, _clock);
      for (size_t i = 0; i < _explosion.size(); ++i)
	{
	  Mix_Chunk *bomb_sound;
	  bomb_sound = Mix_LoadWAV("includes/music/sound_bomb_1.wav");
	  Mix_VolumeChunk(bomb_sound, MIX_MAX_VOLUME);
	  Mix_PlayChannel(1, bomb_sound, 0);
	  _explosion[i]->draw(_shader, _clock);
	}
  for (size_t i = 0; i < _cubeDestr.size(); ++i)
   _cubeDestr[i]->draw(_shader, _clock);
      for (size_t i = 0; i < _bonux.size(); ++i)
      {
        if (_bonux[i]->getWatch() == true)
        {
          int size;

    	   _bonux[i]->draw(_shader, _clock);
         size = getLen(_mapcols[0]) / 2;
         _mapcols[((int)_bonux[i]->getY()*-1) + size][(int)_bonux[i]->getX() + size] = '3';
        }
      }
    }
    if (_end != NULL)
    {
      _end->draw(_shader, _clock);
      _context.flush();
      sleep(4);
      _end = NULL;
    }
    else
      _context.flush();
}
