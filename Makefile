##
## Makefile for bolber in /home/casier_s/libbomber
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Tue May  6 15:15:22 2014 sofian casier
## Last update Tue May 13 15:27:30 2014 sofian casier
##

NAME		=		Bomberman

CXX		=		g++

RM		=		rm -rf

INCS		=		-I includes/

SRCS		=		Game/main.cpp		\
				Game/AObject.cpp	\
				Game/GameEngine.cpp	\
				Game/GE_menu.cpp	\
				Game/Menu.cpp		\
				Game/Cube.cpp		\
				Game/Sound.cpp		\

OBJS		=		$(SRCS:.cpp=.o)

LIB_GDL		=		-Llibs -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -g -ldl

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
