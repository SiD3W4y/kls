CC = gcc

CFLAGS= -std=c99
SRC=src
OBJ = obj

SOURCE=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SOURCE))



$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJS)
	$(CC) $(OBJS) -o kls

clean:
	rm $(OBJ)/*
	rm kls
	

