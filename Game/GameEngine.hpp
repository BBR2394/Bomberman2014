/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update lun. mai  26 17:51:28 2014 sofian casier
*/

#ifndef   __GAMEENGINE__
#define   __GAMEENGINE__

#include <stdlib.h>
#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include <SDL2/SDL_mixer.h>
#include "Menu.hh"
#include "Player.hh"
#include "Player2.hpp"
#include "Background.hh"
#include "Menu.hh"
#include "Cube.hh"
#include "Cursor.hh"
#include "AObject.hpp"
#include "Save.hpp"

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
  bool createMap(int x, int y, int nb_player);
  void    launch_title_music();
  bool    Create_Menu();
  bool    Create_loading();
  bool    Playing(gdl::Clock const &clock, int nb_player);
  int    Go_To_Menu();
  bool    Update_Menu();

private:

  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  gdl::BasicShader      _shader;
  std::vector<AObject*> _objects;
  std::vector<AObject*> _map;
  Background            *_floor;
  Player                *_play1;
  Player2               *_play2;
  std::vector<AObject*> _bombes;
  Menu                  *_menu;
  Cursor                  *_cursor;
  int                   _index_cursor;
  int		        _scene;

  bool                  _music_fight;
  Save                  *_save;
};

#endif
