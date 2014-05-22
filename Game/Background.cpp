/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update jeu. mai  22 17:00:04 2014 sofian casier
*/

#include "Background.hh"

Background::Background(double x, double y, double z, Type type, std::string texture) : AObject(x, y, z, type, texture)
{

}

Background::Background(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture) : AObject(xp, yp, zp, xr, yr, zr, texture)
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
/*
    _geometry.pushVertex(glm::vec3((this->x/2 * 0.5), (this->y/2) * -0.5, this->z));
    _geometry.pushVertex(glm::vec3((this->x/2 * 0.5), (this->y/2) * 0.5, this->z));
    _geometry.pushVertex(glm::vec3((this->x/2 * 0.5) * -1, (this->y/2) * 0.5, this->z));
    _geometry.pushVertex(glm::vec3((this->x/2 * 0.5) * -1, (this->y/2) * -0.5, this->z));*/
    _geometry.pushVertex(glm::vec3(7.5, -7.5, 0));
    _geometry.pushVertex(glm::vec3(7.5, 7.5, 0));
    _geometry.pushVertex(glm::vec3(-7.5, 7.5, 0));
    _geometry.pushVertex(glm::vec3(-7.5, -7.5, 0));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build(); 
    return (true);
}

void Background::update(gdl::Clock const &clock, gdl::Input &input)
{
/*  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed); */
}

void Background::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
