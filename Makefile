CC = gcc
TARGET = game
CFLAGS = -v
SRC = $(wildcard */*.c) main.c
OBJ = $(SRC:.c=.o)
INC =  -I/Users/gehnmart/.brew/include #$(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs) -lSDL2_image

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(INC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(INC) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)