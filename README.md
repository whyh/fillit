# fillit
### (fitit)

An objective was to create the program to solve the pazzle.

## The pazzle
Given a number of tetris-like details, fit them in the smallest possible square in a reasonable amount of time. Tetriminos are quaranteed to
- be a classic piece of Tetris composed of 4 blocks
- exactly fit in a 4 by 4 chars square
- touch at least one other block on any of his 4 sides
Program processes up tp 26 details. You can find examples of valid input [here](tetriminos/)

## How to use
Run `make` and `./fillit tetriminos/mediocre.fillit`

## Co-author
[bkuksa](https://github.com/Marazm12346) -- `validation` and `shape recognition` of the tetriminos
