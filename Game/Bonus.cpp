
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
}

void Bonus::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture.bind();
   _geometry.draw(shader, getTransformation(), GL_QUADS);
   //glm::mat4 test = getTransformation();
   //test = glm::vec4( 1.0, 1.0, 0.0, 0.2);
  // printf("test x %d y %d z %d w %d\n", test.x, test.y, test.z, test.w);
    _model.draw(shader, getTransformation(), GL_QUADS);
}