/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update ven. mai  16 12:56:21 2014 sofian casier
*/

#ifndef   __GAMEENGINE__
#define   __GAMEENGINE__

#include <stdlib.h>
#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include <SDL2/SDL_mixer.h>
#include "AObject.hpp"
#include "Sound.hpp"

class GameEngine : public gdl::Game
{

public:

  GameEngine();
  ~GameEngine();
  bool initialize();
  bool update();
  void draw();
  bool  Menu_choice();
  GameEngine &getEngine() const;
  bool createMap(int x, int y);
  void    launch_title_music();
  bool    Create_Menu();
  bool    Playing(gdl::Clock const &clock);
  
private:

  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  gdl::BasicShader      _shader;
  std::vector<AObject*> _objects;
  Menu                  *_menu;
  Cursor                  *_cursor;
  int                   _index_cursor;
  Sound                 *_Sound;
  Sound                 *_Fight;
  Sound                 *_Ready;
  int			              _scene;
  bool                  _music_fight;
};

#endif
