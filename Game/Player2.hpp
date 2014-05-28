//
// Player.hpp for  in /home/bbr/rendu/test_pour_cpp_bomberman
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Mon May 19 18:05:39 2014 Bertrand-Rapello Baptiste
// Last update Wed May 28 15:13:58 2014 Koszyczek Laurent
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
  Player2(glm::vec3 pos, Type type, std::string texture);
  Player2(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Player2();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif
