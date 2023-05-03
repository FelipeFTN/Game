make clean
make install
export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
make
./bin/Game
