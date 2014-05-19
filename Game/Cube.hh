//
// Cube.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:19:07 2014 Koszyczek Laurent
// Last update Mon May 19 18:12:41 2014 sofian casier
//

#ifndef _CUBE_HH_
# define _CUBE_HH_

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

class Cube : public AObject
{

private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:
  Cube();
  Cube(int x, int y);
  Cube(double x, double y, double z, Type type, std::string texture);
  Cube(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
