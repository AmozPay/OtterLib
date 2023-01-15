##
## EPITECH PROJECT, 2020
## MY MAKEFILES
## File description:
## the ultimate makefile
##

vpath %.cpp src
vpath %.cpp tests

vpath %.hpp include

.RECIPEPREFIX =	-


NAME	=	Core
OBJECT	=	obj
SOURCES	=	src

###################
## Compil option ##
###################

CC      =       g++
CFLAG   =	-W -Wall -Wextra \
                -Wno-unused-variable \
                -Wno-unused-function \
                -Wno-unused-parameter \
		-std=c++20 -g3 \

###########
## imput ##
###########

MAIN = main.cpp

FILE = registry.cpp \
	EntityManager.cpp \

DIR_INCLUDE = -I include

DIR_LIB =
SRC_LIB =

BLACK_LIST_SRC = 


###########
### OBJ ###
###########

ALL_OBJ =       $(patsubst %.cpp, $(OBJECT)/%.o, $(SRC))

SRC	=	$(filter-out $(BLACK_LIST_SRC), $(FILE))

FULL = 

SRC	+=


SRC_TEST	=	$(patsubst %.cpp, $(SOURCES)/%.cpp, $(FILE))

SRC_TEST	+=	$(wildcard tests/*.cpp)

##SRC_TEST += $(shell find ./src -type f -name "*.cpp" | grep -v "main.cpp")

############
### RULE ###
############

.PHONY: all re clean folder fclean 
.DEFAULT: all

all:	 $(NAME)
-@echo	-e "\e[32mlinking all compliete\e[39m"

$(NAME): Folder Form_preCompil $(ALL_OBJ)
-@$(CC) -o $(NAME)  $(ALL_OBJ) $(DIR_INCLUDE) -g3 ##-shared -fPIC
-@echo	-e "\e[32mlinking compliete\e[39m"

Folder:	|	$(OBJECT)

clean:
-@echo -e "\e[33m-->Cleaning time\e[00m"
-rm -f ./$(OBJECT)/*.o

fclean:	clean
-rm -rf $(OBJECT)
-rm -f $(NAME)

re:	clean all

###################
### INTERN RULE ###
###################
        ##dialogue rule
Form_preCompil:
-@echo -e "\n\e[1;94mCompilation start\e[0m"

        ##dir generate
$(OBJECT):
-@echo -e "\e[95mOBJ Directory Generate\e[0m"
-@mkdir -p $(OBJECT)

       ##target: $() = destiantion final; depandance: $(sources)/ = fichier de base
$(OBJECT)/%.o	: %.c
-@$(CC) -c -o $@ $< $(CFLAG)  -g
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"

$(OBJECT)/%.o	: %.cpp
-@$(CC) -c -o $@ $< $(CFLAG) $(DIR_INCLUDE) -g
-@echo -e "\t\e[36mCompilate \e[3;97;4m$@\e[00m; \e[1;92mSUCCES\e[00m"


tests_run: fclean $(SRC_TEST)
-$(CC) -o unit_tests $(SRC_TEST) -I include $(CFLAGS) -lcriterion --coverage
-./unit_tests
-@gcovr -b --exclude tests
-@gcovr --exclude tests

clean_tests:
-rm -rf *.gcda
-rm -rf *.gcno
-rm -rf unit_tests
