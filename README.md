# CPPND: Capstone Asteroid Game
![Asteroid Game Demo](demo.gif)

This is the Capstone project for the Udacity C++ Nanodegree Program. The game is base version of Asteroid game. 
The intention of the game is to destroy the asteroids flying in the space. For the purpose the player is equipped 
with space ship and bullets fired from  the space ship. The space ship is displayed as a red triangle and asteroid
as blue square and bullets are coloured green. When the bullet hits the asteroid, it gets destroyed. The game is 
finished when the player destroys all the asteroids.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./asteroids`.