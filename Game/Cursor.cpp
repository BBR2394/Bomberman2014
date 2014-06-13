/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update ven. juin  13 11:51:25 2014 sofian casier
*/

#include "Cursor.hh"

Cursor::Cursor(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture)
{

}

Cursor::Cursor(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture)
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
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
