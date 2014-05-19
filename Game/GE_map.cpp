/*
//
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Mon May 19 18:18:44 2014 Koszyczek Laurent
//
*/

#include "GameEngine.hpp"

bool                    GameEngine::createMap(int x, int y)
{
  int   c, d, e, lmtx, lmty, i;
  AObject *temp;

  i = 0;
  lmtx = x/2;
  c = lmtx * -1;
  lmty = y/2;
  d = lmty * -1;
  if (y%2 != 0)
    lmty++;
  while (i < x)
    {
      temp = new Cube(c, d, 3, 0, 0, 0, "./includes/images/cube_bis.tga");
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      temp = new Cube(c, lmty, 3, 0, 0, 0, "./includes/images/cube_bis.tga");
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      c++;
      i++;
    }
  i = 1;
  d++;
  c--;
  while (i < y)
    {
      temp = new Cube(c, d, 3, 0, 0, 0, "./includes/images/cube_bis.tga");
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      temp = new Cube(lmtx * -1, d, 3, 0, 0, 0, "./includes/images/cube_bis.tga");
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      if ((i%2 == 0))
        {
          e = (lmtx * -1)+2;
          while (e <= (lmtx - 2))
            {
              temp = new Cube(e, d, 3, 0, 0, 0, "./includes/images/cube_bis.tga");
              if (temp->initialize() == false)
                return (false);
              this->_objects.push_back(temp);
              e = e + 2;
            }
        }
      i++;
      d++;
    }

    temp = new Background(0, 0, 3, 0, 0, 0, "./includes/images/ground.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
  temp = new Player(4, 4, 4, 0, 0, 0, "./includes/images/player.tga");
  if (temp->initialize() == false)
    return (false);
  this->_objects.push_back(temp);
  return (true);
}


