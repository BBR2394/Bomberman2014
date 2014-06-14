/*
// Cube.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:19:07 2014 Koszyczek Laurent
// Last update Sun Jun 15 00:28:51 2014 Koszyczek Laurent
*/

#ifndef _BOMBE_HH_
# define _BOMBE_HH_

# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
#include "AObject.hpp"

class Bombe : public AObject
{

private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int _time;
  int _player;

public:
  Bombe();
  Bombe(int x, int y);
  //Bombe(double x, double y, double z, Type type, std::string texture);
  //Bombe(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture);
  Bombe(glm::vec3 pos, Type type, std::string texture);
  Bombe(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Bombe();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  void setTime(int time);
  int getTime() const;
  void setPlayerSeter(int);
  int getPlayerSeter() const;
};

#endif
