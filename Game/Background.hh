/*
// Background.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:37:15 2014 Koszyczek Laurent
** Last update jeu. mai  22 16:59:40 2014 sofian casier
*/

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
  Background(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture);
  virtual ~Background();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
