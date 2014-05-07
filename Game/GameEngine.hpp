/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mer. mai  07 14:42:12 2014 sofian casier
*/

#pragma once

#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include "Menu.hpp"
#include "AObject.hpp"

class GameEngine : public gdl::Game
{

public:

  GameEngine();
  ~GameEngine();
  bool initialize();
  bool update();
  void draw();

private:

  gdl::SdlContext       _context;
  gdl::Clock            _clock;
  gdl::Input            _input;
  gdl::BasicShader      _shader;
  std::vector<AObject*> _objects;
  Menu                  _menu;
};
