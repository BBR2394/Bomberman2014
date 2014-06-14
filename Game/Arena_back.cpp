/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update sam. juin  14 17:50:13 2014 sofian casier
*/

#include "Arena_back.hpp"

Arena::Arena(std::string texture)
{
  _texture_name = texture;
}

Arena::Arena(glm::vec3 pos, glm::vec3 angle, std::string texture) : AObject(pos, angle, texture)
{
  _texture_name = texture;
}

Arena::~Arena()
{

}

bool    Arena::initialize()
{

if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(25, -20, 10.5));
    _geometry.pushVertex(glm::vec3(25, 20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, -20, 10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(25, -20, -10.5));
    _geometry.pushVertex(glm::vec3(25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(-25, -20, -10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(25, -20, -10.5));
    _geometry.pushVertex(glm::vec3(25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(25, 20, 10.5));
    _geometry.pushVertex(glm::vec3(25, -20, 10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(-25, -20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(-25, -20, -10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(25, 20, 10.5));
    _geometry.pushVertex(glm::vec3(25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, -10.5));
    _geometry.pushVertex(glm::vec3(-25, 20, 10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(25, -20, -10.5));
    _geometry.pushVertex(glm::vec3(25, -20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, -20, 10.5));
    _geometry.pushVertex(glm::vec3(-25, -20, -10.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

bool  Arena::Change_texture(std::string texture)
{
  _texture_name = texture;
if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the rectangle texture" << std::endl;
      return (false);
    }
    return (true);
}

void  Arena::update(gdl::Clock const &clock, gdl::Input &input)
{    
}

void    Arena::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
