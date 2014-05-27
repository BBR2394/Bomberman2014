/*
// GE_menu.cpp for GE in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Tue May 13 15:26:17 2014 sofian casier
** Last update mar. mai  27 17:27:56 2014 sofian casier
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

  if (_input.getInput(SDLK_SPACE, true) || _input.getInput(SDLK_RETURN, true))
  {
    if (_index_cursor == 0)
    {
     
      std::cout << "C'est parti pour un jeu solo!" << std::endl;
      _scene = 2;
      if ((this->Create_loading()) == false)
        return (false);
    }
    if (_index_cursor == 1)
    {
     std::cout << "C'est parti pour un jeu multi!" << std::endl;
     _scene = 4;
     if ((this->Create_loading()) == false)
      return (false);
  }
  if (_index_cursor == 2)
    std::cout << "C'est parti pour continuer le jeu!" << std::endl;
  if (_index_cursor == 3)
    return false;
  Mix_Chunk *music;
  music = Mix_LoadWAV("includes/music/choice_menu.wav");
  Mix_PlayChannel(1, music, 0);
  _cursor = NULL;
}
  return (true);
}

bool    GameEngine::Update_Menu()
{
  _cursor = new Cursor(-3.8, -1, 0, AObject::CURSOR, "./includes/images/cursor_head_2.tga");
  if (_cursor->initialize() == false)
    return (false);
  _menu->Change_texture("./includes/images/title_menu_screen.tga");
  return (true);
}

int    GameEngine::Go_To_Menu()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return -1;
  if (_input.getInput(SDLK_RETURN, true))
  {
    Mix_Chunk *music;
    music = Mix_LoadWAV("includes/music/strike.wav");
    Mix_PlayChannel(1, music, 0);
    _scene = 1;
    return (1);
  }
  return (0);
}

bool		GameEngine::Create_Menu()
{
  _menu = new Menu(0, 0, -5, AObject::MENU, "./includes/images/title_new_screen.tga");
  if (_menu->initialize() == false)
    return (false);
  return (true);
}

bool    GameEngine::Create_loading()
{
  _menu = new Menu(0, 0, -5, AObject::MENU, "./includes/images/loading.tga");
  if (_menu->initialize() == false)
    return (false);
  return (true);
}