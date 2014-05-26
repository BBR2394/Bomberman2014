/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update lun. mai  26 14:43:08 2014 sofian casier
*/

#include "Menu.hh"

Menu::Menu()
{
  _position_menu = 0;
}

Menu::Menu(double x, double y, double z, Type type, std::string texture) : AObject(x, y, z, type, texture)
{
  _position_menu = 0;
  _texture_name = texture;
}

Menu::~Menu()
{

}

bool    Menu::initialize()
{
      _speed = 10.0f;
if (_texture.load("./includes/images/title_new_screen.tga") == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(14, -17.5, 0.5));
    _geometry.pushVertex(glm::vec3(14, 17.5, 0.5));
    _geometry.pushVertex(glm::vec3(-14, 17.5, 0.5));
    _geometry.pushVertex(glm::vec3(-14, -17.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

void  Menu::setPositionMenu(int pos)
{
  _position_menu = pos;
}

void  Menu::update(gdl::Clock const &clock, gdl::Input &input)
{    
}

double    Menu::getXcurs() const
{
  return (_xcurs);
}

double    Menu::getYcurs() const
{
  return (_ycurs);
}

double    Menu::getZcurs() const
{
  return (_zcurs);
}

int   Menu::getPosition() const
{
  return (_position_menu);
}

void    Menu::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
