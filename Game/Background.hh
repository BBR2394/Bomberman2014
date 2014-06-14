/*
// Background.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:37:15 2014 Koszyczek Laurent
// Last update Sun Jun 15 00:26:00 2014 Koszyczek Laurent
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
  int _x;
  int _y;
  int _z;
  int _type;

public:
  Background();
  Background(int x, int y);
  Background(glm::vec3 pos, Type type, std::string texture);
  Background(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Background();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  void setSize(int x, int y, int z);
  void setType(int typ);
  int getX() const;
  int getY() const;
  int getZ() const;
  int getType() const;
};

#endif
