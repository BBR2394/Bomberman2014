//
// Cursor.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:38:53 2014 Koszyczek Laurent
// Last update Mon May 19 17:39:40 2014 Koszyczek Laurent
//

#ifndef _CURSOR_HH_
# define _CURSOR_HH_

# include	"AObject.hpp"

class Cursor : public AObject
{
private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:
  Cursor();
  Cursor(int x, int y);
  Cursor(double x, double y, double z, Type type, std::string texture);
  Cursor(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
  virtual ~Cursor();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
