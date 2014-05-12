/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update lun. mai  12 16:08:46 2014 sofian casier
*/

#ifndef   __GAMEENGINE__
#define   __GAMEENGINE__

#include <stdlib.h>
#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hpp"

Uint8  *sounddata;
Uint32 soundlength;
Uint32 soundpos;

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
  void    launch_title_music();
  
private:

 Uint8 * _sounddata;
 Uint32 _soundlength;
 Uint32 _soundpos;
  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  gdl::BasicShader      _shader;
  std::vector<AObject*> _objects;
  Menu                  *_menu;
  Cube                  *_cursor;
  int                   _index_cursor;
};

#endif