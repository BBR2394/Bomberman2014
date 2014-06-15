/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Sun Jun 15 17:58:42 2014 Koszyczek Laurent
*/

#include "Explosion.hh"

Explosion::Explosion(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture)
{

}

Explosion::~Explosion()
{

}

bool	Explosion::initialize()
{
  _speed = 10.0f;
  _model.load("./assets/bombe.fbx");
  if (_texture.load(_texture_name.c_str()) == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
    _geometry.pushVertex(glm::vec3(0.25, -0.25, 0.25));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, 0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(0.25, -0.25, -0.25));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, -0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(0.25, -0.25, -0.25));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, 0.25));
    _geometry.pushVertex(glm::vec3(0.25, -0.25, 0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, -0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, 0.25));
    _geometry.pushVertex(glm::vec3(0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, -0.25));
    _geometry.pushVertex(glm::vec3(-0.25, 0.25, 0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.pushVertex(glm::vec3(0.25, -0.25, -0.25));
    _geometry.pushVertex(glm::vec3(0.25, -0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, 0.25));
    _geometry.pushVertex(glm::vec3(-0.25, -0.25, -0.25));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

void Explosion::setTime(int time)
{
    _time = time;
}

void Explosion::update(gdl::Clock const &clock, gdl::Input &input)
{
    _time--;
}

void Explosion::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

int Explosion::getTime() const
{
    return (_time);
}

void Explosion::setPlayerSeter(int id)
{
    _player = id;
}

int Explosion::getPlayerSeter() const
{
    return (_player);
}

