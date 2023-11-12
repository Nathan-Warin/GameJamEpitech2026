##
## EPITECH PROJECT, 2022
## Bootstrap_ls
## File description:
## Makefile
##

OBJ 	= 	$(SRC:.cpp=.o)
SRC     = 	src/main.cpp \
			src/game.cpp	\
			src/Menu.cpp	\

CC 	= g++
INCLUDE = -I./include
LFLAG = -g -g3 -Wextra -Wall -Werror -W -std=c++20 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
BIN = moustachio

all : build_all

build_all: $(OBJ)
	@$(CC) $(LFLAG) -o $(BIN) $(SRC) $(INCLUDE)

clean:
	@rm -f $(OBJ)
	@rm -f lib/$(OBJ)

fclean : clean
	@$(RM) $(BIN)

re : fclean all
