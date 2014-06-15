/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update dim. juin  15 20:29:49 2014 sofian casier
*/

#include "End.hh"

End::End(std::string texture)
{
  _texture_name = texture;
}

End::End(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture)
{
  _texture_name = texture;
}

End::~End()
{

}

bool    End::initialize()
{
      _speed = 10.0f;
if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(9, -12, 0.5));
    _geometry.pushVertex(glm::vec3(9, 12, 0.5));
    _geometry.pushVertex(glm::vec3(-9, 12, 0.5));
    _geometry.pushVertex(glm::vec3(-9, -12, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

bool  End::Change_texture(std::string texture)
{
  _texture_name = texture;
if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    return (true);
}

void  End::update(gdl::Clock const &clock, gdl::Input &input)
{    
}

void    End::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}