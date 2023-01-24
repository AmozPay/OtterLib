##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC			=	./src/Deserializer/Deserializer.cpp\
				./src/main.cpp

ISRC 		=	-I ./include/Serializable\
				-I ./include/Serializer\
				-I ./include/Deserializer

OBJ			=	$(SRC:.cpp=.o)

NAME		=	serialization

CPPFLAGS	= 	$(ISRC) -Wall -Wextra -g3 

CXX 		= 	clang

ifneq ("$(wildcard /bin/ccache)","")
  CXX := ccache clang
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) -lboost_serialization -lstdc++
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
