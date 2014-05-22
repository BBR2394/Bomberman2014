/*
// Player.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:40:20 2014 Koszyczek Laurent
** Last update jeu. mai  22 17:01:55 2014 sofian casier
*/

#ifndef _PLAYER_HH_
# define _PLAYER_HH_

# include	"AObject.hpp"

class Player : public AObject
{
private:
  gdl::Model	_model;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;

public:
  Player();
  Player(int x, int y);
  Player(double x, double y, double z, Type type, std::string texture);
  Player(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture);
  virtual ~Player();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
