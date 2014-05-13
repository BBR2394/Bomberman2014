/*
** Sound.hpp for sound in /home/casier_s/cpp_bomberman/Game
**
** Made by sofian casier
** Login   <casier_s@epitech.net>
**
** Started on  mar. mai  13 14:58:16 2014 sofian casier
** Last update mar. mai  13 15:15:26 2014 sofian casier
*/

#ifndef _SOUND_
# define _SOUND_
/*
Uint8  *sounddata;
Uint32 soundlength;
Uint32 soundpos;
*/

#include "AObject.hpp"

class Sound
{
public:
	Sound();
	Sound(std::string , int);
	virtual ~Sound();
	void	launch_title_music();

private:
	std::string _filename;
	int		_freq;
};

#endif