# Clear any previous installation
make clean

# Install dependencies
make install

# Compile the Game
make

# Export library to path
export LD_LIBRARY_PATH=./lib/raylib/lib:$LD_LIBRARY_PATH

# Run Game
./bin/Game
