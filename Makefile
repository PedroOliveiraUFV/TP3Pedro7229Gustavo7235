# Comando para executar:
# mingw32-make
# ./programa

CC = gcc
CFLAGS = -Wall -IHeaders

SRC_DIR = Source
OBJ_DIR = Source
BIN = programa

SRCS = main.c \
       Source/CentrodePesquisa.c \
       Source/PokeLista.c \
       Source/Pokemon.c 


OBJS = $(SRCS:.c=.o)

all: programa

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS)

Sources\%.o: Sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: programa
	./programa testes/arquivo.txt

clean:
	-del /q *.o Sources\*.o programa