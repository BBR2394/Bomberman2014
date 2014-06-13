#include "IA.hh"

IA::IA(glm::vec3 pos, Type type, std::string texture) : Player(pos, type, texture)
{

}

IA::IA(glm::vec3 pos, glm::vec3 r, std::string texture) : Player(pos, r, texture)
{

}

IA::~IA()
{

}

bool	IA::initialize()
{
  _speed = 10.0f;
  if (_texture.load("./includes/images/player.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
    poseBomb = false;
    _counter = 1;
 _geometry.setColor(glm::vec4(1, 0, 0, 0));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 0, 0, 0));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 0, 0, 0));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 0, 0, 0));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 0, 0, 0));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.setColor(glm::vec4(1, 0, 0, 0));
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

int IA::getLen(char *map)
{
  int   i;

  i = 0;
  while (map[i] != '\0')
    i++;
  return (i);
}

int IA::checkCollision(char **map, int dir)
{
  // std::cout << "pos x " << getX() << "pos y \n" << getY());
  int       size;

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

void	IA::update(gdl::Clock const &clock, gdl::Input &input, char **map)
{
int translate_ia;
static int alerte = 0;

translate_ia = 1;
//std::cout << "la strategie " << this->_strat << std::endl;
    if (this->_strat == "attack")
        {
            map[((int)getY()*-1) + 7][(int)getX() + 7] = '0';
            //this->findVictim(map);
            if(checkCollision(map, SDLK_UP) == 1 && (_counter%100 == 0 || (alerte == 1 && _counter%10 == 0)))
                translate(glm::vec3(0, translate_ia, 0));
            else if (checkCollision(map, SDLK_LEFT) == 1 && _counter%100 == 0)
                translate(glm::vec3(-1 * translate_ia, 0, 0));
            else if (checkCollision(map, SDLK_RIGHT) == 1 && _counter%100 == 0)
                translate(glm::vec3(translate_ia, 0, 0));
            else if (checkCollision(map, SDLK_DOWN) == 1 && _counter%100 == 0)
                translate(glm::vec3(0, -1 * translate_ia, 0));
            else if (checkCollision(map, SDLK_UP) == 1 && (alerte == 1 && _counter%10 == 0)) 
              translate(glm::vec3(0, translate_ia, 0));
            else
                {
                   //std::cout << _counter << std::endl;
                }
            if (_nbBombe == 0 && alerte == 1)
                alerte = 0;
            if (_counter%500 == 0)
            {
               poseBomb = true;
               alerte = 1;
            }
            _counter++;
            map[((int)getY()*-1) + 7][(int)getX() + 7] = '8';
            //std::cout << "lia a travaillé " << std::endl;
	     }
}

void IA::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void IA::setStrategy(std::string strategie)
{
	this->_strat = strategie;
}

void IA::setID(int id)
{
    this->_id = id;
}

int IA::getID()
{
    return (_id);
}