CC=g++
BINARY=bin/MyGame
CFLAGS= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
OBJECTS=src/main.o
CFILES=src/main.cpp

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -rf bin/
	rm $(OBJECTS)
