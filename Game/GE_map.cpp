/*
//
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
** Last update lun. mai  26 16:11:15 2014 sofian casier
//
*/

#include "GameEngine.hpp"

bool                    GameEngine::createMap(int x, int y, int nb_player)
{
  double   c, d, e, lmtx, lmty;
  int i;
  AObject *temp;

  if (x%2 == 0)
    x++;
  if (y%2 == 0)
    y++;
  i = 0;
  lmtx = x/2;
  c = lmtx * -1;
  lmty = y/2;
  d = lmty * -1;
  //if (y%2 != 0)
  //lmty++;
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
      if ((i%2 == 0) && _floor->getType() == 1)
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
  /*
    temp = new Background(0, 0, 3, 0, 0, 0, "./includes/images/ground.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
  */
  _play1 = new Player((lmtx*-1)+1, lmty - 1, 4, 0, 0, 0, "./includes/images/player.tga");
  if (_play1->initialize() == false)
    return (false);

  if (nb_player == 2)
    {
      _play2 = new Player2(lmtx-1, lmty-1, 4, 0, 0, 0, "./includes/images/player.tga");
      if (_play2->initialize() == false)
	return (false);
    }
  return (true);
}
