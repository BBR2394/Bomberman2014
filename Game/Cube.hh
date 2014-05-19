//
// Cube.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:19:07 2014 Koszyczek Laurent
// Last update Mon May 19 17:58:54 2014 Koszyczek Laurent
//

#ifndef _CUBE_HH_
# define _CUBE_HH_

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
