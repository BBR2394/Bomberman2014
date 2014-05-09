/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:40:26 2014 sofian casier
** Last update ven. mai  09 18:45:16 2014 sofian casier
*/

#ifndef _GAME_
# define _GAME_

#include <Game.hh>
#include <Clock.hh>
#include <Input.hh>
#include <SdlContext.hh>
#include <Geometry.hh>
#include <Texture.hh>
#include <BasicShader.hh>
#include <Model.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class GameEngine;

class AObject
{
public:

  typedef enum s_type
  {
    MENU = 0,
    CURSOR = 1,
    WALL = 2,
    BOMB = 3
  }       Type;
  AObject();
  AObject(double x, double y, double z, Type type);
  virtual ~AObject();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  void translate(glm::vec3 const &v);
  void rotate(glm::vec3 const& axis, float angle);
  void scale(glm::vec3 const& scale);
  glm::mat4 getTransformation();
  Type  getType() const;
  void    setXcurs(double);
  void    setYcurs(double);
  void    setZcurs(double);

  double                  _ycurs;
  double                  _zcurs;
  double                  _xcurs;
  glm::vec3 _position;
protected:

  Type      _type;
  glm::vec3 _rotation;
  glm::vec3 _scale;  

};

class Cube : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:

//  Cube();
  Cube(double x, double y, double z, Type type);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
};

class Menu : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  gdl::Geometry           _cursor;
  float _speed;

public:

  double  getXcurs() const;
  double  getYcurs() const;
  double  getZcurs() const;
  void    setXcurs(double);
  void    setYcurs(double);
  void    setZcurs(double);
  int   _position_menu;
  Menu();
  Menu(double x, double y, double z, Type type);
  virtual ~Menu();
  virtual bool initialize();
  void  setPositionMenu(int);
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  int     getPosition() const;
 };

#endif
