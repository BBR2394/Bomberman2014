/*
// video.cpp for sof in /home/casier_s/cpp_bomberman
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Wed May 28 17:23:56 2014 sofian casier
** Last update lun. juin  02 15:57:24 2014 sofian casier
//
*/

#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include <unistd.h>
#include "GameEngine.hpp"

int     GameEngine::begin_sec_video()
{

  libvlc_instance_t * inst;
  libvlc_media_player_t *mp;
  libvlc_media_t *m;
  char const *vlc_argv[] = 
  {
    "--no-video-title-show",
    "no-audio",
  };
  inst = libvlc_new (0, vlc_argv);
  m = libvlc_media_new_path(inst, "./includes/Video_bomber/Bomber");
  mp = libvlc_media_player_new_from_media(m);
  libvlc_media_release (m);
  libvlc_media_player_play(mp);
  sleep(12);
  libvlc_media_player_release (mp);
  libvlc_release (inst);
  return 0;
}