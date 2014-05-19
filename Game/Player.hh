//
// Player.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:40:20 2014 Koszyczek Laurent
// Last update Mon May 19 17:40:57 2014 Koszyczek Laurent
//

#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include	"AObject.hpp"

class Player : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:
  Player();
  Player(int x, int y);
  Player(double x, double y, double z, Type type, std::string texture);
  Player(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
  virtual ~Player();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
