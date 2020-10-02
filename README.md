# fillit
### Solves the puzzle with brute-force


Used just 3 standard C library functions
```c
ssize_t read(int fd, void *buf, size_t count);
void    *malloc(size_t size);
void    free(void *ptr);
```

## The pazzle
Given a number of tetris-like details, fit them in the smallest possible square in a reasonable amount of time. Tetriminos are quaranteed to
- be a classic piece of Tetris composed of 4 blocks
- exactly fit in a 4 by 4 chars square
- touch at least one other block on any of his 4 sides
Program processes up tp 26 details. Find examples of valid input [here](tetriminos/)

## How to use
Download, run `make` and `./fillit tetriminos/mediocre.fillit`

## Co-author
[bkuksa](https://github.com/kuksa-bog) - validation and shape recognition of tetriminos
