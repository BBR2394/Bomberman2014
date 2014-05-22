/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update jeu. mai  22 17:00:54 2014 sofian casier
*/

#include "Cursor.hh"

Cursor::Cursor(double x, double y, double z, Type type, std::string texture) : AObject(x, y, z, type, texture)
{

}

Cursor::Cursor(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture) : AObject(xp, yp, zp, xr, yr, zr, texture)
{

}

Cursor::~Cursor()
{

}

bool	Cursor::initialize()
{
  _speed = 10.0f;
  if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build(); 
    return (true);
}

void Cursor::update(gdl::Clock const &clock, gdl::Input &input)
{

}

void Cursor::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
