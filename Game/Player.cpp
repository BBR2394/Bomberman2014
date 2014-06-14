//
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
// Last update Sat Jun 14 15:10:44 2014 Koszyczek Laurent
//

#include "AObject.hpp"
#include "Player.hh"

Player::Player(glm::vec3 pos, Type type, std::string texture) : AObject(pos, type, texture, 0.0025)
{
  _texture_name = texture;
  setKeyPlayer(SDLK_DOWN, SDLK_UP, SDLK_LEFT, SDLK_RIGHT, SDLK_i, SDLK_o, SDLK_b);
}

Player::Player(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture, 0.0025)
{
  setKeyPlayer(SDLK_DOWN, SDLK_UP, SDLK_LEFT, SDLK_RIGHT, SDLK_i, SDLK_o, SDLK_b);
}

Player::~Player()
{

}

void	Player::setKeyPlayer(int k1, int k2, int k3, int k4, int k5, int k6, int k7)
{
  _key[0] = k1;
  _key[1] = k2;
  _key[2] = k3;
  _key[3] = k4;
  _key[4] = k5;
  _key[5] = k6;
  _key[6] = k7;
}

bool	Player::initialize()
{
  _speed = 10.0f;
  if (_texture.load("./includes/images/player.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }

  _target.x = getX();
  _target.y = getY() - 1;
  _target.z = getZ();
  _nbBombe = 0;
  _sizeExplo = 2;
  _maxNbBombe = 1;
  poseBomb = false;
  std::cout << "suite a la création du joueur la position de la cible est : " << _target.x << " " << _target.y << " " << _target.z << " " << std::endl;
  
  _model.load("./assets/marvin.fbx");
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
  int		size;

  size = (getLen(map[0]) / 2);
  if (dir == _key[0]) //DOwn
    {
      if (map[((int)((getY() - size) * -1) + 1)] == 0)
	return 0;
      if (map[(int)((getY() - size) * -1) + 1][(int)getX() + size] == '0')
	return (1);
    }
  else if (dir == _key[1]) // UP
    {
      if (((int)((getY() - size) * -1)) - 1 < 0)
	return 0;
      if (map[(int)((getY() - size) * -1) - 1][(int)getX() + size] == '0')
	return (1);
    }
  else if (dir == _key[2]) //Left
    {
      if ((getX() + size - 1) < 0)
	return 0;
      if (map[(int)((getY() - size) * -1)][(int)getX() + size - 1] == '0')
	return (1);
    }
  else if (dir == _key[3]) // right
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
  int size;

  size = (getLen(map[0]) / 2);
  translate_player = 1;
  map[((int)getY()*-1) + size][(int)getX() + size] = '0';
  if (input.getInput(_key[0], true) && checkCollision(map, _key[0])) // DOwn
    {
      translate(glm::vec3(0, -1 * translate_player, 0));
      _target.x = getX();
      _target.y = getY()-1;
    }
  if (input.getInput(_key[1], true) && checkCollision(map, _key[1])) // UP
    {
      translate(glm::vec3(0, translate_player, 0));
      repet++;
      _target.x = getX();
      _target.y = getY() + 1;
    }
  if (input.getInput(_key[2], true) && checkCollision(map, _key[2])) // left
    {
      translate(glm::vec3(-1 * translate_player, 0, 0));
      _target.x = getX() - 1;
      _target.y = getY();
      repet++;
    }
  if (input.getInput(_key[3], true) && checkCollision(map, _key[3])) //right
    {
      translate(glm::vec3(translate_player, 0, 0));
      _target.y = getY();
      _target.x = getX() + 1;
      repet++;
    }
  if (input.getInput(_key[4], true)) // key i
    {
      _target.z--;
      translate(glm::vec3(0, 0, -1 * translate_player));
      repet++;
    }
  if (input.getInput(_key[5], true)) // key o
    {
      _target.z++;
      translate(glm::vec3(0, 0, translate_player));
      repet++;
    }
  if (input.getInput(_key[6], true && this->getNbBombe() < this->getMaxNbBombe())) //key b
    poseBomb = true;
  map[((int)getY()*-1) + size][(int)getX() + size] = _idMap;
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
  _model.draw(shader, getTransformationPlayer(), GL_QUADS);
}

int Player::getXTarget()
{
  return (_target.x);
}

int Player::getYTarget()
{
  return (_target.y);
}

int Player::getZTarget()
{
  return (_target.z);
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

void Player::setIDnMap(int id, char idm)
{
  _idPlayer = id;
  _idMap = idm;
}

int Player::getID()
{
    return (_idPlayer);
}
