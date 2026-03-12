CC=gcc

OBJ=main.o parser.o execute.o builtins.o pipes.o redirection.o history.o

myshell: $(OBJ)
	$(CC) -o myshell $(OBJ)

main.o: main.c shell.h
	$(CC) -c main.c

parser.o: parser.c shell.h
	$(CC) -c parser.c

execute.o: execute.c shell.h
	$(CC) -c execute.c

builtins.o: builtins.c shell.h
	$(CC) -c builtins.c

pipes.o: pipes.c shell.h
	$(CC) -c pipes.c

redirection.o: redirection.c shell.h
	$(CC) -c redirection.c

history.o: history.c shell.h
	$(CC) -c history.c

clean:
	rm -f *.o myshell
