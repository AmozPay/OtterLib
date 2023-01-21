##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	../src/UdpServer/main.cpp\
				../src/UdpServer/UdpServer.cpp

ISRC		=	../include/UdpServer

OBJ			=	$(SRC:.cpp=.o)

NAME		=	r-type_server

CPPFLAGS	= 	-I $(ISRC) -Wall -Wextra -g3

CXX 		= 	g++

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache g++
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

perso: $(OBJ)
	$(CXX) $(ISRC) $(OBJ) -o $(NAME)

p: perso clean

fcp: fclean

cp: clean

auteur:
	echo $(USER) > auteur
