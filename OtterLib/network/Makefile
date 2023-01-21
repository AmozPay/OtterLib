##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##


all: 
	make -C ./client &&\
	make -C ./server &&\
	mv ./client/r-type_client ./ &&\
	mv ./server/r-type_server ./


clean:
	make clean -C ./client &&
	make clean -C ./server

fclean: 
	make clean -C ./client &&\
	make clean -C ./server &&\
	rm -f ./r-type_client &&\
	rm -f ./r-type_server

re: 
	make re -C ./client && make re -C ./server

auteur:
	echo $(USER) > auteur
