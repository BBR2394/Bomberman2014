/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update ven. mai  09 18:50:33 2014 sofian casier
*/

#ifndef   __GAMEENGINE__
#define   __GAMEENGINE__

#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hpp"

class GameEngine : public gdl::Game
{

public:

  GameEngine();
  ~GameEngine();
  bool initialize();
  bool update();
  void draw();
  GameEngine &getEngine() const;

private:

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