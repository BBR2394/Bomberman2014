/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update mer. mai  07 13:47:58 2014 sofian casier
*/

#ifndef	_MENU_
# define _MENU_

#include "AObject.hpp"

class Menu : public AObject
{
public:
	bool	initialize();
	void	draw();
	void	update(gdl::Clock const &clock, gdl::Input &input);

private:
	Rectangle	*_menu;
};

#endif