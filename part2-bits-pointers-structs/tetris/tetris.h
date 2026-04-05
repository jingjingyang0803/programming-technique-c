/*
EXERCISE: Tetris

The Tetris game is played on a grid that is 10 squares wide, 20 squares high and
closed at the bottom, left and right. The grid is initially empty. During the
game blocks of different shapes are dropped one by one from above (where the
grid is open). The goal is to place the tiles so that they form full grid rows
(each square in a row is filled with a part of some block). Such rows are
removed from the grid as soon as they become filled. When a row is removed, the
contents of all rows above it will be moved one step down.
*/

#ifndef TETRIS_H
#define TETRIS_H

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

/* Updates the grid by removing all full rows and moving the contents of all
   rows above them one step down. The topmost rows are filled with spaces. */
void paivita(char grid[GRID_HEIGHT][GRID_WIDTH]);

#endif /* TETRIS_H */
