#include "suduko.h"

int main()
{
    int **puzzle;
    Square *** suduko;

    puzzle = createPuzzle();
    printPuzzle(puzzle);
    seetupPuzzle(puzzle);
    
    return 0;
}