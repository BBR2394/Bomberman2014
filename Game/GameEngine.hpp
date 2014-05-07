/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mer. mai  07 11:06:14 2014 sofian casier
*/

#pragma once

#include <iostream>
#include <Game.hh>
#include <SdlContext.hh>
#include "AObject.hpp"

class GameEngine : public gdl::Game
{

public:

  GameEngine();
  bool initialize();
  bool update();
  void draw();
  ~GameEngine();

private:

  gdl::SdlContext _context;
  gdl::Clock _clock;
  gdl::Input _input;
  gdl::BasicShader _shader;
  std::vector<AObject*> _objects;
};
