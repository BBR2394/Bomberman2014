/*
// GE_menu.cpp for GE in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Tue May 13 15:26:17 2014 sofian casier
** Last update lun. mai  19 15:50:35 2014 sofian casier
//
*/

#include "GameEngine.hpp"

bool      GameEngine::Menu_choice()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getInput(SDLK_DOWN, true))
    {
      if (_index_cursor < 3)
  {
    _index_cursor++;
    _cursor->translate(glm::vec3(2.2, 0, 0));
  }
    }
  if (_input.getInput(SDLK_UP, true))
    {
      if (_index_cursor > 0)
  {
    _index_cursor--;
    _cursor->translate(glm::vec3(-2.2, 0, 0));
  }
    }
  if (_input.getInput(SDLK_SPACE, true))
    {
      if (_index_cursor == 0)
  {
    std::cout << "C'est parti pour un jeu solo!" << std::endl;
    _scene = 1;
  }
      if (_index_cursor == 1)
  std::cout << "C'est parti pour continuer le jeu!" << std::endl;
      if (_index_cursor == 2)
  std::cout << "C'est parti pour un jeu multi!" << std::endl;
    }
  return (true);
}

bool		GameEngine::Create_Menu()
{
  AObject *_menu = new Menu(0, 0, -5, AObject::MENU, "./includes/images/accueil.tga");
  if (_menu->initialize() == false)
    return (false);
  _objects.push_back(_menu);
  _cursor = new Cursor(-3.8, -1, 0, AObject::CURSOR, "./includes/images/cursor_head.tga");
  if (_cursor->initialize() == false)
    return (false);
  _objects.push_back(_cursor);
  return (true);
}
