*This project has been created as part of the 42 curriculum by nthys, jepiscic.*

# RUSH - CONNECT4

## Description 
[Subject](https://cdn.intra.42.fr/pdf/pdf/176928/en.subject.pdf).
This C project aims to code a Connect 4 game allowing to play against an AI, 
with display of the grid state and the winner.

## Roles
nthys implemented the algorithm.
jepiscic implemented the initialisation and display.

## Instructions
Compile with `make` or `make all`.
`make clean` will remove .o files.
`make fclean` will execute `make clean` and remove the library binary.
`make re` is equivalent to `make fclean && make`.

The program takes two arguments: height and width, e.g. `./connect4 19 42` ; 
minimum size is 6 x 7.

## Norm
As 42 Norm isn't required in this assignment, we used some handy stuff like for loops 
and long functions.

## Allowed functions
- libft
- malloc(3), free(3), rand(3), srand(3), time(3)

## AI
The implemented AI uses alpha-beta pruning algorithm. It first computes the weight of each cell, 
i.e. the number of combinations (horizontal, vertical, diagonal) it is in.

## Display
The grid is made of Unicode box drawing characters for a pretty result.
ANSI escape sequences are used to efficiently display the grid and animate the placement of pawns. 
It allows to avoid reprinting the whole grid on each change:
- "\e[?25l" and "\e[?25h" respectively hide and show the terminal cursor.
- "\e[?1049h" and "\e[[?1049l" enable/disable the alternative buffer.
- "\e[2J" erases the entire screen.
- "\e[H" places the cursor on position (0, 0) (upper left).
- "\e[{line};{column}H" places the cursor on position (line, column). "\e[1;1H" is equivalent to "\e[H".
- "\e[{line/column}A-G" control the cursor position (right, left, up, down).
- Notice that cursor position is 1-indexed.

## Resources
- ["Connect Four", in *Wikipedia*](https://en.wikipedia.org/wiki/Connect_Four)
- ["Alpha-beta pruning", in *Wikipedia*](https://en.wikipedia.org/wiki/Alpha–beta_pruning)
- [ANSI escape sequences cheatsheet](https://gist.github.com/ConnerWill/d4b6c776b509add763e17f9f113fd25b)

