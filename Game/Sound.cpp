/*
// AObject.cpp for AO in /home/casier_s/cpp_bomberman/Game
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May  7 10:22:40 2014 sofian casier
** Last update mer. mai  14 14:15:20 2014 sofian casier
*/

#include "Sound.hpp"

Uint8  *sounddata;
Uint32 soundlength;
Uint32 soundpos;

Sound::Sound()
{

}

Sound::~Sound()
{

}

Sound::Sound(std::string filename, int freq)
{
	_freq = freq;
	_filename = filename;
}

void      Sound::StopMusic()
{
  SDL_CloseAudio();
}

void			mixaudio(void * userdata, Uint8 * stream, int len)
{
  Uint32 tocopy = soundlength - soundpos > len ? len : soundlength - soundpos; 
  memcpy(stream, sounddata + soundpos, tocopy); 
  soundpos += tocopy;
}

void			Sound::launch_music()
{
  SDL_AudioSpec desired, obtained, soundfile;
  SDL_AudioCVT cvt;

  desired.freq = _freq;
  desired.format = AUDIO_U16SYS;
  desired.channels = 2;
  desired.samples = 512;
  desired.callback = &mixaudio;
  desired.userdata = NULL;
  if (SDL_OpenAudio(&desired, &obtained) != 0)
    {
      std::cout << "Error on SDL Open Audio" << std::endl;
      exit(-1);
    }
  if (SDL_LoadWAV(_filename.c_str(), &soundfile, &sounddata, &soundlength) == NULL)
    {
      std::cout << "Error on loading music file" << std::endl;
      exit(-1);
    }
  if (SDL_BuildAudioCVT(&cvt, soundfile.format, soundfile.channels, soundfile.freq, 
			obtained.format, obtained.channels, obtained.freq) < 0)
    {
      std::cout << "Error on Build Audio" << std::endl;
      exit(-1);
    }
  void *tmp;
  tmp = new int[soundlength * cvt.len_mult];
  cvt.buf = (Uint8*)tmp;
  cvt.len = soundlength;
  memcpy(cvt.buf, sounddata, soundlength);
  if (SDL_ConvertAudio(&cvt) != 0)
    {
      std::cout << "Error on conver Audio" << std::endl;
      exit(-1);

    }
  SDL_FreeWAV(sounddata);
  void *tmp2;
  tmp2 = new int[cvt.len_cvt];
  sounddata = (Uint8*)tmp2;
  memcpy(sounddata, cvt.buf, cvt.len_cvt);
  free(cvt.buf);
  soundlength = cvt.len_cvt;
  soundpos = 0;
  SDL_PauseAudio(0);
}