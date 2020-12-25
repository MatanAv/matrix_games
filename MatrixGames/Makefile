CC = gcc
OBJS = main.o menu.o numGame.o  picGame.o generalFunctions.o
EXEC = prog
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c menu.h numGame.h picGame.h
menu.o: menu.c menu.h numGame.h picGame.h
numGame.o: numGame.c numGame.h
picGame.o: picGame.c picGame.h
generalFunctions.o: generalFunctions.c generalFunctions.h

clean: 
	rm -f $(EXEC) $(OBJS)
