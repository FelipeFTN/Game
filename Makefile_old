CC=g++
BINARY=bin/Game
CFLAGS=-L./lib/raylib/lib -I./lib/raylib/include -lraylib -lm -lpthread -ldl -lrt
OBJECTS=src/main.o src/ball/ball.o src/ball/setter.o src/ball/getter.o src/map/map.o
CXXFILES=src/main.cpp src/ball/ball.cpp src/ball/setter.cpp src/ball/getter.cpp src/map/map.cpp

# Raylib
LINUX_RAYLIB=lib/raylib/raylib-4.5.0_linux_amd64
WINDOWS_RAYLIB=lib/raylib/raylib-4.5.0_win64_mingw-w64
MACOS_RAYLIB=lib/raylib/raylib-4.5.0_macos
RAYLIB_FILES=lib/raylib/include lib/raylib/lib

# Export to PATH
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	RAYLIB_PACKAGE := $(LINUX_RAYLIB)
	PACKAGE_TYPE = tar.gz
	EXTRACTOR = tar -xzvf
else ifeq ($(UNAME), Windows_NT)
	RAYLIB_PACKAGE := $(WINDOWS_RAYLIB)
	PACKAGE_TYPE = zip
	EXTRACTOR = unzip -q
else ifeq ($(UNAME), Darwin)
	RAYLIB_PACKAGE := $(MACOS_RAYLIB)
	PACKAGE_TYPE = tar.gz
	EXTRACTOR = tar -xzvf
endif

# Compile Game
$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

install:
	# Raylib
	$(EXTRACTOR) $(RAYLIB_PACKAGE).$(PACKAGE_TYPE) -C lib/raylib/
	mkdir -p lib/raylib/include
	mkdir -p lib/raylib/lib
	mv $(RAYLIB_PACKAGE)/include/* lib/raylib/include
	mv $(RAYLIB_PACKAGE)/lib/* lib/raylib/lib
	export LD_LIBRARY_PATH=./lib/raylib/lib:$LD_LIBRARY_PATH
	rm -rf $(RAYLIB_PACKAGE)

clean:
	rm -rf $(RAYLIB_FILES)
	rm -rf bin/
	rm $(OBJECTS)
