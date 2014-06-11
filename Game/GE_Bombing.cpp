
#include <unistd.h>
#include "GameEngine.hpp"

bool    GameEngine::PlaceBombe(gdl::Clock const &clock, Player *player)
{
	Bombe *temp;
	std::cout << "les position de visé : " << _play1->getX() << " " << _play1->getY()  << " " << _play1->getZ() << std::endl;
  	temp = new Bombe(glm::vec3(_play1->getX(), _play1->getY(), _play1->getZ()), glm::vec3(0, 0, 0), "./includes/images/bombe.tga");
	std::cout << "bombe test ..." << std::endl;
  	if (temp->initialize() == false)
  	    return (false);
	Mix_Chunk *bomb;
   	bomb = Mix_LoadWAV("includes/music/put_bomb.wav");
   	Mix_PlayChannel(1, bomb, 0);
   	temp->setTime(100);
   	temp->setPlayerSeter(player->getID());
   	_bombes.push_back(temp);
   	_play1->setNbBombe(_play1->getNbBombe()+1);	
}

bool	GameEngine::Bombing(gdl::Clock const &clock)
{
	

}