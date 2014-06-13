
#include <iostream>
#include "GameEngine.hpp"

bool    GameEngine::PlaceBombe(gdl::Clock const &clock, Player *player)
{
	Bombe *temp;

	std::cout << "les position de visé : " << player->getX() << " " << player->getY()  << " " << player->getZ() << std::endl;
  	temp = new Bombe(glm::vec3(player->getX(), player->getY(), player->getZ()), glm::vec3(0, 0, 0), "./includes/images/bombe.tga");
  	if (temp->initialize() == false)
  	    return (false);
	Mix_Chunk *bomb;
   	bomb = Mix_LoadWAV("includes/music/put_bomb.wav");
   	Mix_PlayChannel(1, bomb, 0);
   	temp->setTime(100);
   	temp->setPlayerSeter(player->getID());
   	player->setNbBombe(player->getNbBombe()+1);
   	std::cout << "id du player : " << player->getID() << std::endl;
   _bombes.push_back(temp);
}

bool GameEngine::PlaceBombeIA(gdl::Clock const &clock, IA *ia)
{
	Bombe *temp;

	std::cout << "les position de visé : " << ia->getX() << " " << ia->getY()  << " " << ia->getZ() << std::endl;
  	temp = new Bombe(glm::vec3(ia->getX(), ia->getY(), ia->getZ()), glm::vec3(0, 0, 0), "./includes/images/bombe.tga");
  	if (temp->initialize() == false)
  	    return (false);
	Mix_Chunk *bomb;
   	bomb = Mix_LoadWAV("includes/music/put_bomb.wav");
   	Mix_PlayChannel(1, bomb, 0);
   	temp->setTime(100);
   	temp->setPlayerSeter(ia->getID());
   	ia->setNbBombe(ia->getNbBombe()+1);
   	std::cout << "id du player : " << ia->getID() << std::endl;
   _bombes.push_back(temp);	
}
bool	GameEngine::Bombing(gdl::Clock const &clock, size_t i)
{
  Bombe *temp;
  int c;
  int i2;

  i2 = 0;
  temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
  if (temp->initialize() == false)
    return (false);
  temp->setTime(10);
  _explosion.push_back(temp);
  c = 1;
  while (c <= _play1->getSizeExplo())
    {
      temp = new Bombe(glm::vec3(_bombes[i]->getX()+c, _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
      if (temp->initialize() == false)
	     return (false);
      if (checkCollision(temp) != 2)
	{
	  temp->setTime(10);
	  _explosion.push_back(temp);
	  c++;
	  std::cout << "normalement un objet a ete detruit" << std::endl;
	}
      else
	{
	  delete temp;
	  c = 100;
	}
    }
  c = 1;
  while (c <= _play1->getSizeExplo())
    {
      temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY()+c, _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
      if (temp->initialize() == false)
	return (false);
      if (checkCollision(temp) != 2)
	{
	  temp->setTime(10);
	  _explosion.push_back(temp);
	  c++;
	  std::cout << "normalement un objet a ete detruit" << std::endl;
	}
      else
	{
	  delete temp;
	  c = 100;
	}
    }
  c = 1;
  while (c <= _play1->getSizeExplo())
    {
      temp = new Bombe(glm::vec3(_bombes[i]->getX(), _bombes[i]->getY()-c, _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
      if (temp->initialize() == false)
        return (false);
      if (checkCollision(temp) != 2)
	{
	  temp->setTime(10);
	  _explosion.push_back(temp);
	  c++;
	  std::cout << "normalement un objet a ete detruit" << std::endl;
	}
      else
	{
	  delete temp;
	  c = 100;
	}
    }
  c = 1;
  while (c <= _play1->getSizeExplo())
    {
      temp = new Bombe(glm::vec3(_bombes[i]->getX()-c, _bombes[i]->getY(), _bombes[i]->getZ()), glm::vec3(0, 0, 0), "./includes/images/explosion.tga");
      if (temp->initialize() == false)
	return (false);
      if (checkCollision(temp) != 2)
	{
	  temp->setTime(10);
	  _explosion.push_back(temp);
	  c++;
	  std::cout << "normalement un objet a ete detruit" << std::endl;
	}
      else
	{
	  delete temp;
	  c = 100;
	}
      
    }
    
  //else if (_bombes.getPlayerSeter() == 2)
  //	_play2->setNbBombe(_play2->getNbBombe()-1);
  std::cout << "a l'explosion, l'id du joueur est :" << _bombes[i]->getPlayerSeter() << std::endl;

  if (_bombes[i]->getPlayerSeter() == 1)
    _play1->setNbBombe(_play1->getNbBombe()-1);
  else
    {
      while (i2 < _robot.size())
    	{
	  ++i2;
	  if (_bombes[i]->getPlayerSeter() == _robot[i2]->getID())
	    _robot[i2]->setNbBombe(_robot[i2]->getNbBombe()-1);
        }
    }
  printMap();
  _bombes.erase(_bombes.begin()+i);
  return (true);
}

int GameEngine::getLen(char *map)
{
  int i;

  i = 0;
  while (map[i] != '\0')
    i++;
  return (i);
}

int GameEngine::destroyObject(AObject *obj, char id, int size)
{
  std::cout << "l'id est egale a "<< id << std::endl;
  if (id == '6')
  {
    delete _play1;
    _play1 = NULL;
    return (1);
  }
  else if (id == '2')
    {
      //bruit destructin boite
      for (size_t i = 0; i < _cubeDestr.size(); ++i)
      {
        if (_cubeDestr[i]->getX() == obj->getX() && _cubeDestr[i]->getY() == obj->getY())
        {
          std::cout << "j'ai efface un objet" << std::endl;
          _cubeDestr.erase(_cubeDestr.begin()+i);
          return (1);
        }
      }
    return (0);
    }
    else if (id == '1')
      return (0);
    else if (id == '8')
    {
      for (size_t i = 0; i < _robot.size(); ++i)
      {
        if (_robot[i]->getX() == obj->getX() && _robot[i]->getY() == obj->getY())
        {
          std::cout << "j'ai efface un bot" << std::endl;
          _robot.erase(_robot.begin()+i);
          return (1);
        }
      }
    }
return (0);
}

int GameEngine::checkCollision(AObject *obj)
{
  // std::cout << "pos x " << getX() << "pos y \n" << getY());
  int   size;

  size = (getLen(_mapcols[0]) / 2);

     // if (_mapcols[((int)((obj->getY() - size) * -1) + 1)] == 0)
       //  return 0;
std::cout << "check collision 1 " << std::endl;
      if (_mapcols[((int)obj->getY()*-1) + size][(int)obj->getX() + size] != '0')
        {
          std::cout << "check collision 2 " << std::endl;
          if (destroyObject(obj, _mapcols[((int)obj->getY()*-1) + size][(int)obj->getX() + size], size) == 1)
          {
            std::cout << "check collision 3 " << std::endl;
            std::cout << "j'ai modifie une case " << _mapcols[((int)obj->getY()*-1) + size][(int)obj->getX() + size] << std::endl;
            _mapcols[((int)obj->getY()*-1) + size][(int)obj->getX() + size] = '0';
            return (0);
          }
          else
            return (2);
        }
  return (0);
}
