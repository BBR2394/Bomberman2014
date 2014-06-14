/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Sun Jun 15 00:28:02 2014 Koszyczek Laurent
*/

#ifndef _ARENA_BACK_HPP_
# define _ARENA_BACK_HPP_

#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "AObject.hpp"

class Arena : public AObject
{
  private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;

public:

  Arena(std::string texture);
  Arena(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Arena();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  bool    Change_texture(std::string texture);
};

#endif
