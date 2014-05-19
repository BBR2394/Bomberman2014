//
// Cube.hpp for cube in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Tue May 13 14:36:04 2014 sofian casier
** Last update lun. mai  19 15:53:37 2014 sofian casier
//

#pragma once

#include "AObject.hpp"

class Cube : public AObject
{
public:
	Cube()
	{
	  _texture.load("./assets/SunTexture.tga");
		_geometry.setColor(glm::vec4(1, 0, 0, 1)); // on set la color d'une premiere face
		_geometry.pushVertice(glm::vec3(0.5, -0.5, 0.5));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, 0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.setColor(glm::vec4(0, 1, 0, 1));
		_geometry.pushVertice(glm::vec3(0.5, -0.5, -0.5));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, -0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.setColor(glm::vec4(0, 0, 1, 1));
		_geometry.pushVertice(glm::vec3(0.5, -0.5, -0.5));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, 0.5));
		_geometry.pushVertice(glm::vec3(0.5, -0.5, 0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.setColor(glm::vec4(0, 1, 1, 1));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, -0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.setColor(glm::vec4(1, 0, 1, 1));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, 0.5));
		_geometry.pushVertice(glm::vec3(0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, -0.5));
		_geometry.pushVertice(glm::vec3(-0.5, 0.5, 0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.setColor(glm::vec4(1, 1, 0, 1));
		_geometry.pushVertice(glm::vec3(0.5, -0.5, -0.5));
		_geometry.pushVertice(glm::vec3(0.5, -0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, 0.5));
		_geometry.pushVertice(glm::vec3(-0.5, -0.5, -0.5));
		_geometry.pushUv(glm::vec2(0.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 0.0f));
		_geometry.pushUv(glm::vec2(1.0f, 1.0f));
		_geometry.pushUv(glm::vec2(0.0f, 1.0f));
		_geometry.build();
	}

	virtual ~Cube()
	{}

	virtual void draw(gdl::AShader &shader)
	{
		shader.bind();
		glActiveTexture(GL_TEXTURE0);
		_texture.bind(); // on bind la texture avant le draw
		_geometry.draw(shader, _transformation, GL_QUADS); // la geometry est composee de quads
	}

	private:
		gdl::Geometry	_geometry; // la geometry a dessiner
};
