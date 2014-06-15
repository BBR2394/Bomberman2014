/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:40:26 2014 sofian casier
** Last update dim. juin  15 14:54:03 2014 sofian casier
*/

#ifndef _END_HH_
# define _END_HH_

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

class End : public AObject
{
  private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:

  End(std::string texture);
  End(glm::vec3 pos, Type type, std::string texture);
  virtual ~End();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  bool    Change_texture(std::string texture);
};

#endif
