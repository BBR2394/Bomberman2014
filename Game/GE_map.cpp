/*
//
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Sun Jun 15 22:58:11 2014 Bertrand-Rapello Baptiste
//
*/

#include "GameEngine.hpp"

bool                    GameEngine::Create_Arena_Back()
{

}

bool                    GameEngine::createMap(int x, int y, int nb_player)
{
  double   c, d, e, lmtx, lmty;
  int i;
  AObject *temp;
  Bonus *temp2;
  IA *temp3;

  if (x%2 == 0)
    x++;
  if (y%2 == 0)
    y++;
  i = 0;
  lmtx = x/2;
  c = lmtx * -1;
  lmty = y/2;
  d = lmty * -1;
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
  _play1 = new Player(glm::vec3((lmtx*-1)+1, lmty - 1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
  _play1->setIDnMap(1, '6');
    if (_play1->initialize() == false)
      return (false);
    

    temp = new CubeDestr(glm::vec3((lmtx*-1)+3, lmty - 1, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    temp = new CubeDestr(glm::vec3((lmtx*-1)+1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    _mapcols[3][1] = '2';
    _mapcols[1][3] = '2';

    if (nb_player == 2)
    {
      _play2 = new Player(glm::vec3(lmtx-1, lmty-1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
      _play2->setIDnMap(2, '7');
      if (_play2->initialize() == false)
       return (false);
     _mapcols[1][x-2] = '7';
     _play2->setKeyPlayer(SDLK_s, SDLK_z, SDLK_q, SDLK_d, SDLK_w, SDLK_x, SDLK_c);

    }
    temp = new CubeDestr(glm::vec3(lmtx-3, lmty - 1, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    temp = new CubeDestr(glm::vec3(lmtx-1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    _mapcols[1][x-4] = '2';
    _mapcols[3][x-2] = '2';

   //sur repere (3;2) normalement
   //_mapcols[5][10] = '8';

    temp3 = new IA(glm::vec3(lmtx -1, (lmty * -1)+1, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
    if (temp3->initialize() == false)
       return (false);
    _mapcols[y-2][x-2] = '8';
    temp3->setID(3);
    temp3->setStrategy("attack");
    _robot.push_back(temp3);

   temp2 = new Bonus(glm::vec3(-4, -4, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
  if (temp2->initialize() == false)
       return (false);
  _bonux.push_back(temp2);

  _arena = new Arena(glm::vec3(0, 0, 11), glm::vec3(0, 0, 0), "./includes/images/desert_back.tga");
  if (_arena->initialize() == false)
    return false;
    return (true);
 }

bool                    GameEngine::createMap_2(int x, int y, int nb_player)
{
  double   c, d, e, f, lmtx, lmty;
  int i;
  AObject *temp;
  Bonus *temp2;
  IA *temp3;

  if (x%2 == 0)
    x++;
  if (y%2 == 0)
    y++;
  i = 0;
  lmtx = x/2;
  c = lmtx * -1;
  lmty = y/2;
  d = lmty * -1;
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
      temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/grass.tga");
      if (temp->initialize() == false)
	return (false);
      this->_objects.push_back(temp);
      temp = new Cube(glm::vec3(c, lmty, 3), glm::vec3(0, 0, 0), "./includes/images/grass.tga");
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
      temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/grass.tga");
      if (temp->initialize() == false)
	return (false);
      this->_objects.push_back(temp);
      temp = new Cube(glm::vec3((lmtx * -1), d, 3), glm::vec3(0, 0, 0), "./includes/images/grass.tga");
      if (temp->initialize() == false)
	return (false);
      this->_objects.push_back(temp);
      if ((i%2 == 0) && _floor->getType() == 1)
	{
	  e = (lmtx * -1)+2;
	  while (e <= (lmtx - 2))
	    {
	      _mapcols[i][(int)(e + lmtx)] = '1';
	      temp = new Cube(glm::vec3(e, d, 3), glm::vec3(0, 0, 0), "./includes/images/grass.tga");
	      if (temp->initialize() == false)
		return (false);
	      this->_objects.push_back(temp);
	      e = e + 2;
	    }
	}
      else if (i%2 != 0)
        {
          f = (lmtx * -1)+3;
          while (f <= (lmtx - 3))
            {
              _mapcols[i][(int)(f + lmtx)] = '2';
              temp = new CubeDestr(glm::vec3(f, d, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox\
.tga");
              if (temp->initialize() == false)
                return (false);
              this->_cubeDestr.push_back(temp);
              f = f + 2;
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
  _play1 = new Player(glm::vec3((lmtx*-1)+1, lmty - 1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
  _play1->setIDnMap(1, '6');
  if (_play1->initialize() == false)
    return (false);

  temp = new CubeDestr(glm::vec3((lmtx*-1)+1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
  if (temp->initialize() == false)
    return (false);
  _cubeDestr.push_back(temp);
  _mapcols[3][1] = '2';

  if (nb_player == 2)
    {
      _play2 = new Player(glm::vec3(lmtx-1, lmty-1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
      _play2->setIDnMap(2, '7');
      if (_play2->initialize() == false)
	return (false);
      _play2->setKeyPlayer(SDLK_s, SDLK_z, SDLK_q, SDLK_d, SDLK_w, SDLK_x, SDLK_c);
      _mapcols[1][x-2] = '7';
    }
  temp = new CubeDestr(glm::vec3(lmtx-1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
  if (temp->initialize() == false)
    return (false);
  _cubeDestr.push_back(temp);
  _mapcols[3][x-2] = '2';

  //sur repere (3;2) normalement
  //_mapcols[5][10] = '8';

  temp3 = new IA(glm::vec3(lmtx -1, (lmty * -1)+1, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
  if (temp3->initialize() == false)
    return (false);
  _mapcols[y-2][x-2] = '8';
  temp3->setID(3);
  temp3->setStrategy("attack");
  _robot.push_back(temp3);

  temp2 = new Bonus(glm::vec3(-4, -4, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
  if (temp2->initialize() == false)
    return (false);
  _bonux.push_back(temp2);
  _arena = new Arena(glm::vec3(0, 0, 11), glm::vec3(0, 0, 0), "./includes/images/forest_back.tga");
  if (_arena->initialize() == false)
    return false;
  return (true);
}

bool                    GameEngine::createMap_3(int x, int y, int nb_player)
{
  double   c, d, e, lmtx, lmty;
  int i;
  AObject *temp;
  Bonus *temp2;
  IA *temp3;

  if (x%2 == 0)
    x++;
  if (y%2 == 0)
    y++;
  i = 0;
  lmtx = x/2;
  c = lmtx * -1;
  lmty = y/2;
  d = lmty * -1;
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
    temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/steel_map.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    temp = new Cube(glm::vec3(c, lmty, 3), glm::vec3(0, 0, 0), "./includes/images/steel_map.tga");
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
    temp = new Cube(glm::vec3(c, d, 3), glm::vec3(0, 0, 0), "./includes/images/steel_map.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    temp = new Cube(glm::vec3((lmtx * -1), d, 3), glm::vec3(0, 0, 0), "./includes/images/steel_map.tga");
    if (temp->initialize() == false)
      return (false);
    this->_objects.push_back(temp);
    if ((i%2 == 0) && _floor->getType() == 1)
    {
      e = (lmtx * -1)+2;
      while (e <= (lmtx - 2))
      {
        _mapcols[i][(int)(e + lmtx)] = '1';
  temp = new Cube(glm::vec3(e, d, 3), glm::vec3(0, 0, 0), "./includes/images/steel_map.tga");
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
  _play1 = new Player(glm::vec3((lmtx*-1)+1, lmty - 1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
  _play1->setIDnMap(1, '6');
    if (_play1->initialize() == false)
      return (false);

    temp = new CubeDestr(glm::vec3((lmtx*-1)+3, lmty - 1, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    temp = new CubeDestr(glm::vec3((lmtx*-1)+1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    _mapcols[3][1] = '2';
    _mapcols[1][3] = '2';

    if (nb_player == 2)
    {
      _play2 = new Player(glm::vec3(lmtx-1, lmty-1, 3), glm::vec3(90, 0, 0), "./includes/images/player.tga");
      _play2->setIDnMap(2, '7');
      if (_play2->initialize() == false)
	return (false);
      _play2->setKeyPlayer(SDLK_s, SDLK_z, SDLK_q, SDLK_d, SDLK_w, SDLK_x, SDLK_c);
     _mapcols[1][x-2] = '7';
   }
    temp = new CubeDestr(glm::vec3(lmtx-3, lmty - 1, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    temp = new CubeDestr(glm::vec3(lmtx-1, lmty - 3, 3), glm::vec3(0, 0, 0), "./includes/images/woodbox.tga");
    if (temp->initialize() == false)
      return (false);
    _cubeDestr.push_back(temp);
    _mapcols[1][x-4] = '2';
    _mapcols[3][x-2] = '2';

   //sur repere (3;2) normalement
   //_mapcols[5][10] = '8';

    temp3 = new IA(glm::vec3(lmtx -1, (lmty * -1)+1, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
    if (temp3->initialize() == false)
       return (false);
    _mapcols[y-2][x-2] = '8';
    temp3->setID(3);
    temp3->setStrategy("attack");
    _robot.push_back(temp3);

   temp2 = new Bonus(glm::vec3(-4, -4, 3), glm::vec3(0, 0, 0), "./includes/images/player.tga");
  if (temp2->initialize() == false)
       return (false);
  _bonux.push_back(temp2);
  _arena = new Arena(glm::vec3(0, 0, 11), glm::vec3(0, 0, 0), "./includes/images/water_back.tga");
  if (_arena->initialize() == false)
    return false;
   return (true);
 }
