
#ifndef BONUS_HPP_
# define BONUS_HPP_

class Bonus : public AObject
{
private:
  gdl::Model	_model;
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  int _counter;
  bool _toWatch;
public:
	Bonus(glm::vec3 pos, glm::vec3 r, std::string texture);
	~Bonus();
	virtual bool initialize();
  	virtual void update(gdl::Clock const &clock, gdl::Input &input, char **map);
  	virtual void draw(gdl::AShader &shader, gdl::Clock const &clock);
  bool getWatch() const;
};

#endif
