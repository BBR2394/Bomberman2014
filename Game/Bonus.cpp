
#include "AObject.hpp"
#include "Bonus.hpp"

Bonus::Bonus(glm::vec3 pos, glm::vec3 r, std::string texture) : AObject(pos, r, texture)
{

}

Bonus::~Bonus()
{
	
}


bool	Bonus::initialize()
{
  if (_texture.load("./includes/images/player.tga") == false)
    {
      std::cerr << "Cannot load the cube texture" << std::endl;
      return (false);
    }
_counter = 0;
_toWatch = false;
    _geometry.setColor(glm::vec4(1, 1, 1, 1));
    _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.25));
    _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.25));
    _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.25));
    _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.25));

    _geometry.pushUv(glm::vec2(0.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 0.0f));
    _geometry.pushUv(glm::vec2(1.0f, 1.0f));
    _geometry.pushUv(glm::vec2(0.0f, 1.0f));
    _geometry.build();
	return (true);
}
void Bonus::update(gdl::Clock const &clock, gdl::Input &input, char **map)
{
if (_counter >= 1000)
{
  _toWatch = true;
}
else
_counter++;
}

void Bonus::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
   _geometry.draw(shader, getTransformation(), GL_QUADS);
    _model.draw(shader, getTransformation(), GL_QUADS);
}

bool Bonus::getWatch() const
{
  return (_toWatch);
}
