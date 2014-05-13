//
// GE_menu.cpp for GE in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Tue May 13 15:26:17 2014 sofian casier
// Last update Tue May 13 15:26:48 2014 sofian casier
//

#include "GameEngine.hpp"

bool		GameEngine::Create_Menu()
{
  AObject *_menu = new Menu(0, 0, -5, AObject::MENU);
  /*  _menu->setXcurs(-3.3);
  _menu->setYcurs(-1);
  _menu->setZcurs(0); */
  if (_menu->initialize() == false)
    return (false);
  _objects.push_back(_menu);
  _cursor = new Cube(-3.8, -1, 0, AObject::CURSOR);
  if (_cursor->initialize() == false)
    return (false);
  _objects.push_back(_cursor);
  return (true);
}
