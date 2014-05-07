/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mer. mai  07 13:47:50 2014 sofian casier
*/

#include "Menu.hpp"

bool	Menu::initialize()
{
	_menu = new Rectangle();
	return (true);
}

void	Menu::draw()
{

}

void	Menu::update(gdl::Clock const &clock, gdl::Input &input)
{
	(void)clock;
	(void)input;
}