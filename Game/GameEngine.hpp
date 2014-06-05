/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mar. juin  03 23:49:45 2014 sofian casier
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
#include "Bombe.hh"
#include "Bonus.hpp"
#include "Save.hpp"

class GameEngine : public gdl::Game
{

public:

  GameEngine();
  ~GameEngine();
  bool initialize();
  bool update();
  void draw();
  GameEngine &getEngine() const;
  bool createMap(int x, int y, int nb_player);
  bool    Menu_choice();
  bool  Launch_mus();
  void    launch_title_music();
  void  Fight_mus();
  bool    Create_Menu();
  int    Go_To_Menu();
  bool    Create_loading();
  bool    Playing(gdl::Clock const &clock, int nb_player);
  bool    Update_Menu();
  void	printMap();
  void  Set_Two_Players();
  void  Set_One_Player();
  int	begin_sec_video();
  bool  Choose_your_map();
  bool  Create_select_map();
  bool  Update_Select();
  bool  Map_choice();

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
  std::vector<Bombe*> _bombes;
  std::vector<Bombe*> _explosion;
  std::vector<Bonus*> _bonux;
  Menu                  *_menu;
  Cursor                  *_cursor;
  Cursor                  *_cursor_map;
  int                   _index_cursor;
  int                   _select_map;
  bool                   _check_select_map;
  int		                 _scene;
  bool                  _music_fight;
  bool                  _launch;
  Save                  *_save;
  int                     _map_chosen;
  int                     _game_type;
  char			           **_mapcols;
  int _nbtour;
};

#endif
