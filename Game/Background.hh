//
// Background.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:37:15 2014 Koszyczek Laurent
// Last update Mon May 19 17:39:58 2014 Koszyczek Laurent
//

#ifndef _BACKGROUND_HH_
# define _BACKGROUND_HH_

# include	"AObject.hpp"

class Background : public AObject
{
private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int x;
  int y;
  int z;

public:
  Background();
  Background(int x, int y);
  Background(double x, double y, double z, Type type, std::string texture);
  Background(int xp, int yp, int zp, int xr, int yr, int zr, std::string textur\
	     e);
  virtual ~Background();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
