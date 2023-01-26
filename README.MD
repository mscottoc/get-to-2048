# Overview

I have made my own version of the game 2048. In the game there is a 4 x 4 grid of tiles that either are empty or have a number divisible by two. You can combine tiles by moving all tiles on the board in one direction. If two tiles with the same number collide, they combine in to one tile with double the value. The goal of the game is to get a tile to reach 2048, but if you fill the board and can no longer combine tiles you lose. I used an object oriented method of programing in this project by making each tile in the grid a Tile object.

I chose to make a simple game in c++ in order to tune my skills in it as it had been a while since I had used the language.

I had difficulty figuring out how to make a grid and assign objects on the grid a spot without overlapping. In the end I decided to make a 2 dimensional array of Tile objects and only having a certain number of them be active. I also had difficulty with the tiles being combined with the incorrect tiles. It turned out that when a tile had already combined with another tile, the new value would match with the next active tile in the row/column so they would combine for a second time in one turn. This was both in consistent with the original game and with itself as it would only combine twice if the lower value combination happened first, so I added a variable that would allow the program to know when a tile had already combined that turn so it would not happen twice in a turn.

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

I used VS Code as my IDE with the extensions C/C++, C/C++ Extension Pack, and Code Runner. As well as g++ for the complier.

As mentioned I made this project using C++. I also used the following libraries: iostream, string and sstream for displaying in the terminal and stdlib.h and ctime for pseudo random number generation.

# Useful Websites

- [play2048.co](https://play2048.co/)
- [W3Schools C++](https://www.w3schools.com/cpp/)
- [cplusplus.com - rand](https://cplusplus.com/reference/cstdlib/rand/)

# Future Work

* I would like to add a feature that checks if there are any current possible moves and gives you a game over if there are not. (currently it just checks if the board if full and without changes for two turns in a row)
* Adding a high score system
