/*
// Player.hh for bomberman in /home/koszyc_l/Documents/blih/cpp_bomberman/Game
// 
// Made by Koszyczek Laurent
// Login   <koszyc_l@epitech.net>
// 
// Started on  Mon May 19 17:40:20 2014 Koszyczek Laurent
// Last update Sat Jun 14 15:11:05 2014 Koszyczek Laurent
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
  glm::vec3	_target;
  int		_key[7];
  int		_nbBombe;
  int		_sizeExplo;
  int		_maxNbBombe;
  int		_idPlayer;
  char _idMap;

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
  virtual void setKeyPlayer(int k1, int k2, int k3, int k4, int k5, int k6, int k7);
  int getXTarget();
  int getYTarget();
  int getZTarget();
  void setSizeExplo(int size);
  int getSizeExplo();
  int getNbBombe();
  void setNbBombe(int nb);
  int getMaxNbBombe();
  void setMaxNbBombe(int nb);
  int getID();
  void setIDnMap(int id, char idm);

  bool poseBomb;
};

#endif
