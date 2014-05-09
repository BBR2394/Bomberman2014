/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update ven. mai  09 15:02:16 2014 sofian casier
*/

#include "GameEngine.hpp"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
	for (size_t i = 0; i < _objects.size(); i++)
		delete _objects[i];
}

/*GameEngine		&getEngine() const
{
	return (*this);
} */

bool			GameEngine::initialize()
{
	if (!_context.start(800, 600, "My bomberman!"))
	{
		std::cout << "error on start context" << std::endl; 
		return false;
	}
	glEnable(GL_DEPTH_TEST);
	if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) || !_shader.build())
	{
		std::cout << "shader failed" << std::endl;
		return (false);
	}
	glm::mat4 projection;
	glm::mat4 transformation;
	projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	transformation = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	_shader.bind();
	_shader.setUniform("view", transformation);
	_shader.setUniform("projection", projection);

	AObject *menu = new Menu(0, 0, -5);
	if (menu->initialize() == false)
		return (false);
	_objects.push_back(menu); 
	_cursor = new Cube(-3.3, -1, 0);
	if (_cursor->initialize() == false)
		return (false);
	_objects.push_back(_cursor);
/*	AObject *cube = new Cube();
	AObject *cube2 = new Cube(4, 8);		
	if (cube2->initialize() == false)
		return (false);
	_objects.push_back(cube2);
	if (cube->initialize() == false)
		return (false);
	_objects.push_back(cube);*/
	return (true); 
}

bool			GameEngine::update()
{
	if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
		return false;
	_context.updateClock(_clock);
	_context.updateInputs(_input);
	for (size_t i = 0; i < _objects.size(); ++i)
		_objects[i]->update(_clock, _input);
	return true;
}
	
void			GameEngine::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shader.bind();
	for (size_t i = 0; i < _objects.size(); ++i)
		_objects[i]->draw(_shader, _clock);
	_context.flush();
}
