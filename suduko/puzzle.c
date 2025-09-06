#include "suduko.h"

Square *** setupPuzzle(int **puzzle)
{
    Square ***suduko;
    int i,j;
    suduko = (Square***)malloc(sizeof(Square**)*9);
    
    /*loop rows*/
    for (i = 0; i < 9; i++)
    {
        suduko[i] = (Square***)malloc(sizeof(Square**)*9);        
        /*loop columns*/
        for (j = 0; j < 9; j++)
        {
            suduko[i][j] = (Square***)malloc(sizeof(Square)*9);

            suduko[i][j]->number = puzzle[i][j];

            suduko[i][j]->row = i;
            suduko[i][j]->column = j;

            if (suduko[i][j]->number != 0)
                suduko[i][j]->code = POSSIBLE; // all numbers are possible
            else
                suduko[i][j]->code = 0x0; // no numbers are possible
            }
    }
}



int **createPuzzle()
{
    int **puzzle;
    int i, j;
    int array[9][9] = {0, 1, 9,     0, 0, 2,   0, 0, 0,
                       4, 7, 0,     6, 9, 0,   0, 0, 1,
                       0, 0, 0,     4, 0, 0,   0, 9, 0,

                       8, 9, 4,     5, 0, 7,   0, 0, 0,
                       0, 0, 0,     0, 0, 0,   0, 0, 0,
                       0, 0, 0,     2, 0, 1,   9, 5, 8,

                       0, 5, 0,     0, 0, 6,    0, 0, 0,
                       6, 0, 0,     0, 2, 8,    0, 7, 9,
                       0, 0, 0,     1, 0, 0,    8, 6, 0};

    puzzle = (int **)malloc(sizeof(int *) * 9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int *)malloc(sizeof(int) * 9);
        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(int **puzzle)
{
    int i, j;
    printf("------Sudoku Puzzle-----\n");
    for (i = 0; i < 9; i++)
    {   
        printf("| ");
        for (j = 0; j < 9; j++)
        {
            printf("%d ", puzzle[i][j]);
            if ((j + 1) % 3 == 0)
            {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0)
        {
            printf("------------------------\n");
        }
    }
}

