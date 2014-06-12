/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update jeu. juin  12 20:52:08 2014 sofian casier
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
#include "IA.hh"
#include "CubeDestr.hh"
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
  bool createMap_2(int x, int y, int nb_player);
  bool createMap_3(int x, int y, int nb_player);
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
  bool  Set_Two_Players();
  bool  Set_One_Player();
  int	begin_sec_video();
  bool  Choose_your_map();
  bool  Create_select_map();
  bool  Update_Select();
  bool  Map_choice();
  void  set_Arg(char *argv);
  bool  ReturnToMenu();
  bool    Go_To_Pause();
  bool PlaceBombe(gdl::Clock const &clock, Player *player);
  bool Bombing(gdl::Clock const &clock);

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
  std::vector<IA*>    _robot;
  std::vector<AObject*> _cubeDestr;
  Menu                  *_menu;
  Menu                   *_pause;
  Cursor                  *_cursor;
  Cursor                  *_cursor_map;
  bool                  _pause_cond;
  bool                  _cond_video;
  int                   _index_cursor;
  int                   _index_pause;
  int                   _select_map;
  bool                   _check_select_map;
  int		                 _scene;
  bool                  _music_fight;
  bool                  _launch;
  Save                  *_save;
  int                     _map_chosen;
  int                     _game_type;
  char			           **_mapcols;
  int                     _nbtour;
  float                 _angle;
  float                 _rotation;
};

#endif
