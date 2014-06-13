/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Wed Jun 11 11:36:17 2014 Bertrand-Rapello Baptiste
*/

#include "AObject.hpp"
#include "Player.hh"
/*Cube::Cube()
{
}*/

Player::Player(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture)
{
    _texture_name = texture;
}

Player::Player(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture)
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

  _x_target = getX();
  _y_target = getY() - 1;
  _z_target = getZ();
  _nbBombe = 0;
  _sizeExplo = 2;
  _maxNbBombe = 1;
  _idPlayer = 1;
  poseBomb = false;
  std::cout << "suite a la création du joueur la position de la cible est : " << _x_target << " " << _y_target << " " << _z_target << " " << std::endl;


  //_model.load("./assets/marvin.fbx");
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
  
  //std::cout << "la montre " << clock.getElapsed() << std::endl;
  translate_player = 1;
  map[((int)getY()*-1) + 7][(int)getX() + 7] = '0';
  if (input.getInput(SDLK_DOWN, true) && checkCollision(map, SDLK_DOWN))
    {
      translate(glm::vec3(0, -1 * translate_player, 0));
      _x_target = getX();
      _y_target = getY()-1;
    }
  if (input.getInput(SDLK_UP, true) && checkCollision(map, SDLK_UP))
    {
      translate(glm::vec3(0, translate_player, 0));
      repet++;
      _x_target = getX();
      _y_target = getY() + 1;
    }
  if (input.getInput(SDLK_LEFT, true) && checkCollision(map, SDLK_LEFT))
    {
      translate(glm::vec3(-1 * translate_player, 0, 0));
      _x_target = getX() - 1;
      _y_target = getY();
      repet++;
    }
  if (input.getInput(SDLK_RIGHT, true) && checkCollision(map, SDLK_RIGHT))
    {
      translate(glm::vec3(translate_player, 0, 0));
      _y_target = getY();
      _x_target = getX() + 1;
      repet++;
    }
  if (input.getInput(SDLK_i, true))
    {
      _z_target--;
      translate(glm::vec3(0, 0, -1 * translate_player));
      repet++;
    }
  if (input.getInput(SDLK_o, true) )
    {
      _z_target++;
      translate(glm::vec3(0, 0, translate_player));
      repet++;
    }
  if (input.getInput(SDLK_b, true && this->getNbBombe() < this->getMaxNbBombe()))
    poseBomb = true;

  map[((int)getY()*-1) + 7][(int)getX() + 7] = '6';
  if (repet > 0)
    repet--;
}


void Player::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
   //glm::mat4 test = getTransformation();
   //test = glm::vec4( 1.0, 1.0, 0.0, 0.2);
  // printf("test x %d y %d z %d w %d\n", test.x, test.y, test.z, test.w);
  _model.draw(shader, getTransformation(), GL_QUADS);
}

int Player::getXTarget()
{
  return (_x_target);
}

int Player::getYTarget()
{
  return (_y_target);
}

int Player::getZTarget()
{
  return (_z_target);
}

void Player::setSizeExplo(int size)
{
  _sizeExplo = size;
}

int Player::getSizeExplo()
{
  return (_sizeExplo);
}

int Player::getNbBombe()
{
  return (_nbBombe);
}

void Player::setNbBombe(int nb)
{
  _nbBombe = nb;
}

int Player::getMaxNbBombe()
{
  return (_maxNbBombe);
}

void Player::setMaxNbBombe(int nb)
{
  _maxNbBombe = nb;
}

int Player::getID()
{
    return (_idPlayer);
}