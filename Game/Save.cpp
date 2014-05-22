
#include <iostream>
#include "Save.hpp"

Save::Save(std::string fileName)
{
	//this->_fd = 
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

void Save::writeInFile()
{
	std::cout << "les differentes informations : " << this->_x << " " << this->_y << " " << this->_z << " " << this->_type << " nb player : " << this->_nbPlayer << std::endl;
}