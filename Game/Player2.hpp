//
// Player.hpp for  in /home/bbr/rendu/test_pour_cpp_bomberman
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon May 19 18:05:39 2014 Bertrand-Rapello Baptiste
// Last update Tue May 27 12:42:11 2014 Koszyczek Laurent
//

#ifndef PLAYER2_HPP_
# define PLAYER2_HPP_

#include "AObject.hpp"

class Player2 : public AObject
{

 private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

 public:
  Player2();
  Player2(int x, int y);
  Player2(double x, double y, double z, Type type, std::string texture);
  Player2(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
  virtual ~Player2();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
