
#include <iostream>
#include "Save.hpp"

Save::Save(std::string fileName)
{
	std::ofstream save(fileName.c_str(), std::ios::out | std::ios::trunc);
	if (!save)
	{
		std::cout << "Error on open Save" << std::endl;
		save.close();
	}
 }

Save::~Save()
{

}

void Save::setSize(int x, int y, int z, int type)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
	this->_type = type;
}

void Save::setNbPlayer(int nb)
{
	this->_nbPlayer = nb;
}

void Save::writeInFile(char **map)
{
	int j,i;
	j = 0;
	std::ofstream save("Save", std::ios::out | std::ios::trunc);
	if (!save)
		{
			std::cout << "Error on open Save" << std::endl;
			save.close();
		}
		save << "x |" << " y " << "| z |" << " type |" << " nb player" << std::endl;
		save << _x << " " << _y << " " << this->_z << this->_type << this->_nbPlayer << std::endl;
	while (map[j])
    {
      i = 0;
      while (map[j][i])
      {
      	save << map[j][i++];
      }
      save << std::endl;
      j++;
    }
}
