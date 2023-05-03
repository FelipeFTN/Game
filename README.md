# Game (with no name)

Game is a simple C++ game built using Raylib. It is a two-players game where the players controls a ball and has the objective to remove the other player from the field.<br>
<img src="assets/game.png" width="200" height="200">

## Table of Contents

1. [Installation](#installation)
2. [How to Play](#how-to-play)
3. [Contributing](#contributing)
4. [License](#license)

## Installation

### Plug & Play (Recommended)
To install the game, follow these steps:

1. Download the latest release of the game from the [releases page](https://github.com/FelipeFTN/Game/releases).<br>
2. Extract the zip file in your machine.<br>
3. Run the executable file generated _Game.exe_ or `$ ./Game` in case you downloaded the Linux or Mac version.<br>
4. Enjoy!

### Building by your own
For this process to work, you will need a few tools, which you may already have, since this method is usually chosen by more advanced players.<br>
Make sure you have [GNU Make](https://www.gnu.org/software/make/) and [GNU Compiler Collection](https://gcc.gnu.org/) (GCC & G++) installed in your computer.<br>
All checked? Right, let's do it!<br>
Just go over the Game's root directory and do on your terminal:
```bash
    ## Building from Makefile
    $ make install && make
```
As simples as that, you can easily run your game with `$ ./bin/Game` or `sh Game.sh`.
In case of any error, we highly recommend to export some libs to Path:
```bash
    $ export LD_LIBRARY_PATH=./lib/raylib/lib:$LD_LIBRARY_PATH
```
This should do it! Let us know in case of any error during your execution :)

## How to Play

Once you have installed the game, follow these steps to play:<br>

Use the arrow keys to move the player-2 up, down, left, or right.<br>
Use the WASD keys to move the player-1 up, down, left, or right.<br>
Use physics to your advantage.<br>
Take your opponent off the field to win.<br>

## Contributing

We welcome contributions to the game! If you would like to contribute, please follow these steps:

Fork the repository to your GitHub account.<br>
Create a new branch for your changes.<br>
Make your changes and commit them to the new branch.<br>
Push the new branch to your forked repository.<br>
Submit a pull request to the main repository.<br>

## License

The game is licensed under the [MIT License](https://github.com/FelipeFTN/Game/blob/master/LICENSE). Feel free to use and modify the game as you wish!
