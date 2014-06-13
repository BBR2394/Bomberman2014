
#ifndef IA_HH_
# define IA_HH_

# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include "AObject.hpp"
# include "Player.hh"

class IA : public AObject
{
private:
  bool poseBomb;
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;
  int _x_target;
  int _y_target;
  int _z_target;
  int _nbBombe;
  int _sizeExplo;
  int _maxNbBombe;
  std::string _strat;
  long _counter;
  int _id;

public:
  IA(int x, int y);
  IA(glm::vec3 pos, Type type, std::string texture);
  IA(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~IA();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input, char **map);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  void setStrategy(std::string strategie);
  void setID(int id);
  int getID();
  int checkCollision(char **map, int dir);
  int getLen(char *map);
};

#endif