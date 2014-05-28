/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Wed May 28 14:37:34 2014 Koszyczek Laurent
*/

#include "Menu.hh"

Menu::Menu(std::string texture)
{
  _texture_name = texture;
}

Menu::Menu(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture)
{
  _texture_name = texture;
}

Menu::~Menu()
{

}

bool    Menu::initialize()
{
      _speed = 10.0f;
if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(14, -19, 0.5));
    _geometry.pushVertex(glm::vec3(14, 19, 0.5));
    _geometry.pushVertex(glm::vec3(-14, 19, 0.5));
    _geometry.pushVertex(glm::vec3(-14, -19, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

bool  Menu::Change_texture(std::string texture)
{
  _texture_name = texture;
if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    return (true);
}

void  Menu::update(gdl::Clock const &clock, gdl::Input &input)
{    
}

void    Menu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
