/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Sun Jun 15 00:27:01 2014 Koszyczek Laurent
*/

#include "Background.hh"

Background::Background(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture)
{

}

Background::Background(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture)
{

}

Background::~Background()
{

}

bool	Background::initialize()
{
  _speed = 10.0f;
  if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  _geometry.pushVertex(glm::vec3(((this->_x/2) * -1), (this->_y/2), 0.25));
  _geometry.pushVertex(glm::vec3((this->_x/2), (this->_y/2), 0.25));
  _geometry.pushVertex(glm::vec3((this->_x/2), ((this->_y/2) * -1), 0.25));
  _geometry.pushVertex(glm::vec3(((this->_x/2) * -1), ((this->_y/2) * -1), 0.25));
  std::cout << this->_x/2 << " " << this->_y/2 << std::endl;
  std::cout << this->getX() << " " << this->getY() << std::endl;
  /* _geometry.pushVertex(glm::vec3(7.5, -7.5, -0.5));
    _geometry.pushVertex(glm::vec3(7.5, 7.5, -0.5));
    _geometry.pushVertex(glm::vec3(-7.5, 7.5, -0.5));
    _geometry.pushVertex(glm::vec3(-7.5, -7.5, -0.5));
  */
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 0.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.build();

    return (true);
}

void Background::update(gdl::Clock const &clock, gdl::Input &input)
{
  // no update needed
}

void Background::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void Background::setSize(int x, int y, int z)
{
  std::cout << x << " " << y << " " << z << std::endl;
  this->_x = x;
  this->_y = y;
  this->_z = z;
}

int Background::getX() const
{
  return (this->_x);
}

int Background::getY() const
{
  return (this->_y);
}

int Background::getZ() const
{
  return (this->_z);
}

void Background::setType(int typ)
{
  this->_type = typ;
}

int Background::getType() const
{
  return (this->_type);
}

