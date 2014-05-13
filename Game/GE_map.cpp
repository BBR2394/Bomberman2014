//
// GE_map.cpp for  in /home/bbr/rendu/cpp_bomberman/modif_a_voir
// 
// Made by Bertrand-Rapello Baptiste
// Login   <bertra_l@epitech.net>
// 
// Started on  Tue May 13 15:26:33 2014 Bertrand-Rapello Baptiste
// Last update Tue May 13 15:27:16 2014 Bertrand-Rapello Baptiste
//

#include "GameEngine.hpp"

bool                    GameEngine::createMap(int x, int y)
{
  int   c, d, e;
  AObject *temp;

  for (size_t i = 0; i < _objects.size(); i++)
    delete _objects[i];
  c = (x/2) * -1;
  d = ((y/2) * -1);
  while (c < x/2)
    {
      temp = new Cube(c, ((y/2) * -1), 3, 0, 0, 0);
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      temp = new Cube(c, y/2, 3, 0, 0, 0);
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      c++;
    }
  while (d < (y/2))
    {
      temp = new Cube((x/2)-1, d, 3, 0, 0, 0);
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      temp = new Cube((x/2) * -1, d, 3, 0, 0, 0);
      if (temp->initialize() == false)
        return (false);
      this->_objects.push_back(temp);
      if (d%2 == 0)
        {
          e = ((x/2) * -1)+ 2;
          while (e <= ((x/2) - 2))
            {
              temp = new Cube(e, d , 3, 0, 0, 0);
              if (temp->initialize() == false)
                return (false);
              this->_objects.push_back(temp);
              e = e + 2;
            }
        }
      d++;
    }
  std::cout << this->_objects.size() << std::endl;
}
