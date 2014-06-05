/*
// Player.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:40:20 2014 Koszyczek Laurent
// Last update Fri May 30 10:25:59 2014 Bertrand-Rapello Baptiste
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
  int _x_target;
  int _y_target;
  int _z_target;
  int _nbBombe;
  int _sizeExplo;
  int _maxNbBombe;

  int		checkCollision(char **map, int dir);
  int		getLen(char *map);

public:
  Player();
  Player(int x, int y);
  Player(glm::vec3 pos, Type type, std::string texture);
  Player(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~Player();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input, char **map);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  int getXTarget();
  int getYTarget();
  int getZTarget();
  void setSizeExplo(int size);
  int getSizeExplo();
int getNbBombe();
  void setNbBombe(int nb);
  int getMaxNbBombe();
  void setMaxNbBombe(int nb);
};

#endif
