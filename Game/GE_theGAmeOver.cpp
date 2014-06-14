
#include <iostream>
#include "GameEngine.hpp"

int GameEngine::theGameOver()
{
	if (_play1 != NULL)
	{
		std::cout << "Player 1 is the winner !! " << std::endl;
		sleep(10);
	}
	else if (_play2 != NULL)
	{
		std::cout << "Player 2 is the winner !! " << std::endl;
		sleep(10);
	}
	else
	{
		
	}
}