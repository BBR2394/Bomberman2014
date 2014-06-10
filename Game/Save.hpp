
#ifndef SAVE_HPP_
# define SAVE_HPP_

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
	int _x;
	int _y;
	int _z;
	int _type;
	int _nbPlayer;
};

#endif 