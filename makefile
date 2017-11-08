
all: main.c 
		gcc main.c `pkg-config --cflags --libs sdl2 jack` -o main

clean:
		rm main

