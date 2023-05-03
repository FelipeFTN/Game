CC=g++
BINARY=bin/Game
CFLAGS=-Llib -lraylib -lm -lpthread -ldl -lrt -Ilib
OBJECTS=src/main.o src/ball/ball.o src/ball/setter.o src/ball/getter.o src/map/map.o
CXXFILES=src/main.cpp src/ball/ball.cpp src/ball/setter.cpp src/ball/getter.cpp src/map/map.cpp

# Raylib
LINUX_RAYLIB=lib/raylib-4.5.0_linux_amd64
WINDOWS_RAYLIB=lib/raylib-4.5.0_win64_mingw-w64
MACOS_RAYLIB=lib/raylib-4.5.0_macos
RAYLIB_FILES=lib/*.so.** lib/*.so lib/*.a lib/*.h

# Export to PATH
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	RAYLIB_PACKAGE := $(LINUX_RAYLIB)
	PACKAGE_TYPE = tar.gz
	EXTRACTOR = tar -xzvf
	export LD_LIBRARY_PATH := /usr/local/lib:$(LD_LIBRARY_PATH)
else ifeq ($(UNAME), Windows_NT)
	RAYLIB_PACKAGE := $(WINDOWS_RAYLIB)
	PACKAGE_TYPE = zip
	EXTRACTOR = unzip -q
	export PATH := /c/raylib:$(PATH)
else ifeq ($(UNAME), Darwin)
	RAYLIB_PACKAGE := $(MACOS_RAYLIB)
	PACKAGE_TYPE = tar.gz
	EXTRACTOR = tar -xzvf
	export DYLD_LIBRARY_PATH := /usr/local/lib:$(DYLD_LIBRARY_PATH)
endif

# Compile Game
$(BINARY): $(OBJECTS)
	mkdir -p bin/
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.cpp
	$(CC) -c $^ -o $@ $(CFLAGS)

install:
	# Raylib
	$(EXTRACTOR) $(RAYLIB_PACKAGE).$(PACKAGE_TYPE) -C lib/
	mv $(RAYLIB_PACKAGE)/include/* lib/
	mv $(RAYLIB_PACKAGE)/lib/* lib/
	rm -rf $(RAYLIB_PACKAGE)

clean:
	rm -rf $(RAYLIB_FILES)
	rm -rf bin/
	rm $(OBJECTS)
