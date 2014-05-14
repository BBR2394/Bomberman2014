/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:40:26 2014 sofian casier
** Last update mer. mai  14 14:43:49 2014 sofian casier
*/

#ifndef _GAME_
# define _GAME_

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

class Menu : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  gdl::Geometry           _cursor;
  float _speed;

public:

  double  getXcurs() const;
  double  getYcurs() const;
  double  getZcurs() const;
  void    setXcurs(double);
  void    setYcurs(double);
  void    setZcurs(double);
  int   _position_menu;
  Menu();
  Menu(double x, double y, double z, Type type, std::string texture);
  virtual ~Menu();
  virtual bool initialize();
  void  setPositionMenu(int);
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  int     getPosition() const;
 };

#endif
