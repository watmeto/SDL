CC = cc
LIB = -lSDL -lSDLmain -lSDL -lSDL_image -lSDL_ttf
OUT = hello
SRC = main.c
all:
	$(CC) $(SRC) $(LIB) -o $(OUT)

l: all
	./$(OUT)
