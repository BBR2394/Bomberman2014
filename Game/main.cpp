/*
// main.cpp for ma in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 15:55:25 2014 sofian casier
// Last update Sun Jun 15 17:45:22 2014 Koszyczek Laurent
*/

#include <iostream>
#include <cstdlib>
#include "GameEngine.hpp"

int main(int argc, char **argv, char **envp)
{
  if (envp == NULL || getenv("PATH") == NULL)
    {
      std::cout << "Error in the environment. Aborting" << std::endl;
      return (-1);
    }

    GameEngine engine;
    if (argc >= 2)
      engine.set_Arg(argv[1]);
    if (engine.initialize() == false)
    {
      std::cout << "failure on init" << std::endl;
      return (EXIT_FAILURE);
    }
  while (engine.update() == true)
    engine.draw();
  return EXIT_SUCCESS;
}
