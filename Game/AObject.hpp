/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:40:26 2014 sofian casier
// Last update Mon May 19 17:55:44 2014 Koszyczek Laurent
*/

#ifndef _AOBJECT_HH__
# define _AOBJECT_HH__

# include <Game.hh>
# include <Clock.hh>
# include <Input.hh>
# include <SdlContext.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <BasicShader.hh>
# include <Model.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include "Cube.hh"

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
  AObject(int x, int y);
  AObject(double x, double y, double z, Type type, std::string texture);
  AObject(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
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
  int   sizex;
  int   sizey;
  std::string _texture_name;
};

/*class Cube : public AObject
{

private:

  gdl::Texture _texture;
  gdl::Geometry _geometry;
  float _speed;

public:
  Cube();
  Cube(int x, int y);
  Cube(double x, double y, double z, Type type, std::string texture);
  Cube(int xp, int yp, int zp, int xr, int yr, int zr, std::string texture);
  virtual ~Cube();
  virtual bool initialize();
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  };*/

#endif
