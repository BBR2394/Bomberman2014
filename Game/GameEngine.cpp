/*
// GameEngine.hpp for game in /home/casier_s/libbomber
// 
// Made by sofian casier
// Login   <casier_s@epitech.net>
// 
// Started on  Mon May  5 17:45:27 2014 sofian casier
** Last update lun. mai  12 16:15:52 2014 sofian casier
*/

#include "GameEngine.hpp"

Uint8  *sounddata;
Uint32 soundlength;
Uint32 soundpos;

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
	for (size_t i = 0; i < _objects.size(); i++)
		delete _objects[i];
}

void			mixaudio(void * userdata, Uint8 * stream, int len)
 {
 	Uint32 tocopy = soundlength - soundpos > len ? len : soundlength - soundpos; 
   /* Copie des données sonores dans le tampon audio... */
   memcpy(stream, sounddata + soundpos, tocopy); 
   /* Mise à jour de la position de lecture */
   soundpos += tocopy;
 }

void			GameEngine::launch_title_music()
{
	SDL_AudioSpec desired, obtained, soundfile;
	SDL_AudioCVT cvt;
	desired.format = AUDIO_U16SYS;
	desired.channels = 2;
	desired.samples = 512;
	desired.callback = &mixaudio;
	desired.userdata = NULL;
	if ((SDL_Init(SDL_INIT_AUDIO)) == -1)
	{
		std::cout << "Error on SDL Audio Init" << std::endl;
		exit(-1);
	}
	if (SDL_OpenAudio(&desired, &obtained) != 0)
	{
		std::cout << "Error on SDL Open Audio" << std::endl;
		exit(-1);
	}
	if (SDL_LoadWAV("./includes/music/title_screen.wav", &soundfile, &sounddata, &soundlength) == NULL)
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
   tmp = malloc(soundlength * cvt.len_mult);
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
   tmp2 = malloc(cvt.len_cvt);
   sounddata = (Uint8*)tmp2;
   memcpy(sounddata, cvt.buf, cvt.len_cvt);
   free(cvt.buf);
   soundlength = cvt.len_cvt;
   soundpos = 0;
   SDL_PauseAudio(0);
}

bool			GameEngine::initialize()
{
	if (!_context.start(800, 600, "My bomberman!"))
	{
		std::cout << "error on start context" << std::endl; 
		return false;
	}
	glEnable(GL_DEPTH_TEST);
	if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) || !_shader.build())
	{
		std::cout << "shader failed" << std::endl;
		return (false);
	}
	_index_cursor = 0;
	glm::mat4 projection;
	glm::mat4 transformation;
	projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	transformation = glm::lookAt(glm::vec3(0, 0, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	_shader.bind();
	_shader.setUniform("view", transformation);
	_shader.setUniform("projection", projection);
	AObject *_menu = new Menu(0, 0, -5, AObject::MENU);
/*	_menu->setXcurs(-3.3);
	_menu->setYcurs(-1);
	_menu->setZcurs(0); */
	if (_menu->initialize() == false)
		return (false);
	_objects.push_back(_menu);
	_cursor = new Cube(-3.8, -1, 0, AObject::CURSOR);
	if (_cursor->initialize() == false)
		return (false);
	_objects.push_back(_cursor);
	this->launch_title_music();
/*	AObject *cube = new Cube();
   void *tmp2;
	AOtmp2be2 = new Cube(4, 8);		
	sounddata = (Uint8*)tmp2;
	if (cube2->initialize() == false)
		return (false);
		soundlength = cvt.len_cvt;
		SDL_PauseAudio(0);
	_objects.push_back(cube2);
	if (cube->initialize() == false)
		return (false);
	_objects.push_back(cube);*/
	return (true); 
}

bool			GameEngine::Menu_choice()
{
	if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
		return false;
	if (_input.getInput(SDLK_DOWN, true))
	{
		if (_index_cursor < 3)
		{
			_index_cursor++;
			_cursor->translate(glm::vec3(2.2, 0, 0));
		}
	}
	if (_input.getInput(SDLK_UP, true))
	{
		if (_index_cursor > 0)
		{
		_index_cursor--;
			_cursor->translate(glm::vec3(-2.2, 0, 0));
		}
	}
	if (_input.getInput(SDLK_SPACE, true))
	{
		if (_index_cursor == 0)
			std::cout << "C'est parti pour un jeu solo!" << std::endl;
		if (_index_cursor == 1)
			std::cout << "C'est parti pour continuer le jeu!" << std::endl;
		if (_index_cursor == 2)
			std::cout << "C'est parti pour un jeu multi!" << std::endl;
	}
	return (true);
}

bool			GameEngine::update()
{
	if 	(this->Menu_choice() == false)
		return (false);
	_context.updateClock(_clock);
	_context.updateInputs(_input);
//	for (size_t i = 0; i < _objects.size(); ++i)
//		_objects[i]->update(_clock, _input);
	return (true);
}

void			GameEngine::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shader.bind();
	for (size_t i = 0; i < _objects.size(); ++i)
		_objects[i]->draw(_shader, _clock);
	_context.flush();
}
