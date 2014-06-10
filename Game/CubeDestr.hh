
#ifndef CUBEDESTR_HH_
# define CUBEDESTR_HH_

#include "AObject.hpp"

class CubeDestr : public AObject
{
private:
  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:
  CubeDestr();
  CubeDestr(int x, int y);
  CubeDestr(glm::vec3 pos, Type type, std::string texture);
  CubeDestr(glm::vec3 pos, glm::vec3 r, std::string texture);
  virtual ~CubeDestr();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif