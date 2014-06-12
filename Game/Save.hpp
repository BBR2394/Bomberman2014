
#ifndef SAVE_HPP_
# define SAVE_HPP_

#include <fstream>
#include <iostream>

class Save
{
public:
	Save(std::string);
	~Save();
	void setSize(int , int , int, int);
	void setNbPlayer(int);
	void writeInFile(char** map);

private:
	std::ofstream _save_file;
	int _x;
	int _y;
	int _z;
	int _type;
	int _nbPlayer;
};

#endif 