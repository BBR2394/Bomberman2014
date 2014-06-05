/*
//
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Wed May 28 15:12:49 2014 Koszyczek Laurent
//
*/

#include "GameEngine.hpp"

bool                    GameEngine::createMap(int x, int y, int nb_player)
{
  double   c, d, e, lmtx, lmty;
  int i;
  AObject *temp;
  Bonus *temp2;

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
  printf("y : %d, x %d\n", x, y);
  _mapcols = new char*[y + 2];
  for (int i = 0; i <= y ; ++i)
    _mapcols[i] = new char[x + 2];
  while (i < x)
  {
    _mapcols[0][i] = '1';
    _mapcols[y - 1][i] = '1';
    int k = 1;
    while (k < y - 1)
      _mapcols[k++][i] = '0';
    temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/cube_bis.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    temp = new Cube(glm::vec3(c, lmty, 3), glm::vec3(0, 0, 0), "./includes/images/cube_bis.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    c++;
    i++;
  }
  _mapcols[0][x] = '\0';
  i = 1;
  d++;
  c--;
  while (i < y - 1)
  {
    _mapcols[i][0] = '1';
    _mapcols[i][x - 1] = '1';
    _mapcols[i][x] = '\0';
    temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/cube_bis.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    temp = new Cube(glm::vec3((lmtx * -1), d, 3), glm::vec3(0, 0, 0), "./includes/images/cube_bis.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    if ((i%2 == 0) && _floor->getType() == 1)
    {
      e = (lmtx * -1)+2;
      while (e <= (lmtx - 2))
      {
        _mapcols[i][(int)(e + lmtx)] = '1';
	temp = new Cube(glm::vec3(e, d, 3), glm::vec3(0, 0, 0), "./includes/images/cube_bis.tga");
        if (temp->initialize() == false)
          return (false);
        this->_objects.push_back(temp);
        e = e + 2;
      }
    }
    i++;
    d++;
  }
  _mapcols[i++][x] = '\0';
  _mapcols[i] = 0;
  /*
    temp = new Background(0, 0, 3, 0, 0, 0, "./includes/images/ground.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
  */
  _mapcols[1][1] = '6';
  _play1 = new Player(glm::vec3((lmtx*-1)+1, lmty - 1, 4), glm::vec3(0, 0, 0), "./includes/images/player.tga");
    if (_play1->initialize() == false)
      return (false);

    if (nb_player == 2)
    {
      _play2 = new Player2(glm::vec3(lmtx-1, lmty-1, 4), glm::vec3(0, 0, 0), "./includes/images/player.tga");
      if (_play2->initialize() == false)
       return (false);
     _mapcols[1][y-2] = '7';
   }   


   temp2 = new Bonus(glm::vec3(-4, -4, 4), glm::vec3(0, 0, 0), "./includes/images/player.tga");
  if (temp2->initialize() == false)
       return (false);
  _bonux.push_back(temp2);
printMap();
   return (true);
 }

void                    GameEngine::printMap()
{
  int                   i;
  int                   j;


  j = 0;
  while (_mapcols[j])
    {
      i = 0;
      while (_mapcols[j][i])
        {
          printf("%c", _mapcols[j][i++]);
        }
      printf("\n");
      j++;
    }
}
