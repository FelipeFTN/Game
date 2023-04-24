CC=g++
BINARY=bin/Game
CFLAGS= -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
OBJECTS=src/main.o src/ball/ball.o src/ball/setter.o src/ball/getter.o src/map/map.o
CFILES=src/main.cpp src/ball/ball.cpp src/ball/setter.cpp src/ball/getter.cpp src/map/map.cpp

$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -rf bin/
	rm $(OBJECTS)
