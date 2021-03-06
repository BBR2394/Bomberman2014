/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Sun Jun 15 18:06:07 2014 Koszyczek Laurent
*/

#include "Bombe.hh"

/*
Bombe::Bombe(double x, double y, double z, Type type, std::string texture) : AObject(x, y, z, type, texture)
{

}
*/
Bombe::Bombe(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture, 1.0)
{

}

/*
Bombe::Bombe(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture) : AObject(xp, yp, zp, xr, yr, zr, texture)
{

}
*/
Bombe::~Bombe()
{

}

bool	Bombe::initialize()
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

void Bombe::setTime(int time)
{
    _time = time;
}

void Bombe::update(gdl::Clock const &clock, gdl::Input &input)
{
    _time--;
    //std::cout << _time << std::endl;
}

void Bombe::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  //_texture.bind();
  //  _geometry.draw(shader, getTransformation(), GL_QUADS);
  _model.draw(shader, getTransformationPlayer(), GL_QUADS);
}

int Bombe::getTime() const
{
    return (_time);
}

void Bombe::setPlayerSeter(int id)
{
    _player = id;
}

int Bombe::getPlayerSeter() const
{
    return (_player);
}

