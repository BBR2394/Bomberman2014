## Makefile for bolber in /home/casier_s/libbomber
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Tue May  6 15:15:22 2014 sofian casier
## Last update Sun Jun 15 17:43:18 2014 Koszyczek Laurent
##

NAME		=		Bomberman

CXX		=		g++

RM		=		rm -rf

INCS		=		-I includes/

SRCS		=		Game/main.cpp		\
				Game/AObject.cpp	\
				Game/GameEngine.cpp	\
				Game/GE_menu.cpp	\
				Game/GE_play.cpp	\
				Game/GE_map.cpp		\
				Game/Menu.cpp		\
				Game/Cube.cpp		\
				Game/Player.cpp		\
				Game/Cursor.cpp		\
				Game/Background.cpp	\
				Game/Save.cpp		\
				Game/Bombe.cpp		\
				Game/sec_video.cpp	\
				Game/Bonus.cpp		\
				Game/IA.cpp		\
				Game/CubeDestr.cpp	\
				Game/GE_Bombing.cpp	\
				Game/Arena_back.cpp	\
				Game/Explosion.cpp	\
				Game/End.cpp		\

OBJS		=		$(SRCS:.cpp=.o)

LIB_GDL		=		-Llibs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl -L libs/ -lSDL2_mixer -lrt -lvlc

all		:		$(NAME)

$(NAME)		:		$(OBJS)
				$(CXX) -o $(NAME) $(OBJS) $(INCS) $(LIB_GDL)
				@echo 'Compilation Bomberman : DONE'

clean		:
				@$(RM) $(OBJS) *~ *# $(SRCS_D)*~ $(SRCS_D)*#
				@echo 'Cleaning directory : DONE'

fclean		:		clean
				@$(RM) $(NAME)
				@echo 'Full Cleaning directory : DONE'

re		:		fclean all
				@echo 'Recompilation : Done'

.cpp.o		:
				$(CXX) $(INCS) $(CXXFLAGS) $(INCS_GDL) $(LIB_GDL) -c $< -o $(<:.cpp=.o)

.PHONY		:		all clean fclean re
