//
// main.cpp for ma in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 15:55:25 2014 sofian casier
// Last update Mon May  5 18:13:19 2014 sofian casier
//

#include <cstdlib>
#include "GameEngine.hpp"

int main()

{
  GameEngine engine;

  if (engine.initialize() == false)
    {
      std::cout << "failure on init" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
