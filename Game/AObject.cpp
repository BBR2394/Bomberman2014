/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Tue May 13 14:44:35 2014 sofian casier
*/

#include "AObject.hpp"

AObject::AObject() : _position(5, 5, 0), _rotation(0, 0, 0), _scale(1, 1, 1)
{
}

/*AObject::AObject(int x, int y): _position(x, y, 0), _rotation(0,0,0), _scale(1, 1, 1)
{
}*/

AObject::AObject(double x, double y, double z, Type type): _position(x, y, z), _rotation(0, 0, -90), _scale(1, 1, 1)
{
  _type = type;
}

AObject::AObject(int xp, int yp, int zp, int xr, int yr, int zr): _position(xp, yp, zp), _rotation(xr,yr,zr), _scale(1, 1, 1)
{

}


AObject::~AObject()
{
}

void      AObject::setXcurs(double x)
{
  _xcurs = x;
}

void      AObject::setYcurs(double y)
{
  _ycurs = y;
}

void      AObject::setZcurs(double z)
{
  _zcurs = z;
}

bool	AObject::initialize()
{

}

void	AObject::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4 AObject::getTransformation()
{
  glm::mat4 transform(1);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);

}

AObject::Type      AObject::getType() const
{
  return (this->_type);
}
