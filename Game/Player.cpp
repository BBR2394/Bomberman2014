/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Tue May 27 23:56:36 2014 Koszyczek Laurent
*/

#include "AObject.hpp"
#include "Player.hh"
/*Cube::Cube()
{
}*/

Player::Player(double x, double y, double z, Type type, std::string texture) : AObject(x, y, z, type, texture)
{
    _texture_name = texture;
}

Player::Player(double xp, double yp, double zp, double xr, double yr, double zr, std::string texture) : AObject(xp, yp, zp, xr, yr, zr, texture)
{

}

Player::~Player()
{

}

bool	Player::initialize()
{
  _speed = 10.0f;
  if (_texture.load("./includes/images/player.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
  _geometry.setColor(glm::vec4(0, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 1, 0, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(0, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(0, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(0, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(0, 0, 1, 1));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
    return (true);
}

int	Player::getLen(char *map)
{
  int	i;

  i = 0;
  while (map[i] != '\0')
    i++;
  return (i);
}

int	Player::checkCollision(char **map, int dir)
{
  // std::cout << "pos x " << getX() << "pos y \n" << getY());
  int		size;

  size = (getLen(map[0]) / 2);
  if (dir == SDLK_DOWN)
    {
      if (map[((int)((getY() - size) * -1) + 1)] == 0)
	return 0;
      if (map[(int)((getY() - size) * -1) + 1][(int)getX() + size] == '0')
	return (1);
    }
  else if (dir == SDLK_UP)
    {
      if (((int)((getY() - size) * -1)) - 1 < 0)
	return 0;
      if (map[(int)((getY() - size) * -1) - 1][(int)getX() + size] == '0')
	return (1);
    }
  else if (dir == SDLK_LEFT)
    {
      if ((getX() + size - 1) < 0)
	return 0;
      if (map[(int)((getY() - size) * -1)][(int)getX() + size - 1] == '0')
	return (1);
    }
  else if (dir == SDLK_RIGHT)
    {
      if (map[(int)((getY() - size) * -1)][(int)getX() + size + 1] == '0')
	return (1);
    }
  return (0);
}

void Player::update(gdl::Clock const &clock, gdl::Input &input, char **map)
{
    static int repet = 0;
    int translate_player;

    translate_player = 1;

    if (input.getInput(SDLK_DOWN, true) && checkCollision(map, SDLK_DOWN))
  {
    translate(glm::vec3(0, -1 * translate_player, 0));
}
  if (input.getInput(SDLK_UP, true) && checkCollision(map, SDLK_UP))
  {
    translate(glm::vec3(0, translate_player, 0));
    repet++;
    }
  if (input.getInput(SDLK_LEFT, true) && checkCollision(map, SDLK_LEFT))
  {
    translate(glm::vec3(-1 * translate_player, 0, 0));
    repet++;
    }
  if (input.getInput(SDLK_RIGHT, true) && checkCollision(map, SDLK_RIGHT))
  {
    translate(glm::vec3(translate_player, 0, 0));
    repet++;
    }
  if (input.getInput(SDLK_i, true))
  {
    translate(glm::vec3(0, 0, -1 * translate_player));
    repet++;
    }
  if (input.getInput(SDLK_o, true))
  {
    translate(glm::vec3(0, 0, translate_player));
    repet++;
    }
  if (input.getInput(SDLK_SPACE, true) && checkCollision(map, SDLK_SPACE))
  {
    std::cout << "une BOMBE" << std::endl;
    repet++;
    }
    if (repet > 0)
        repet--;
}

void Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
