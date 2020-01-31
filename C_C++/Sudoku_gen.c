#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#define UNASSIGNED 0
#define SIZE 9
#define SRSIZE 3
uint8_t pattern[9];
void fillpattern();
extern void printBoard(uint8_t board[SIZE][SIZE]);
void fillDiagonal(uint8_t board[SIZE][SIZE]);
bool solveSudoku(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t col);
int solutionSudoku(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t col);
bool isSafe(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t col, uint8_t num);
extern bool checkRow(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t num);
extern bool checkCollum(uint8_t board[SIZE][SIZE], uint8_t col, uint8_t num);
extern bool checkBox(uint8_t board[SIZE][SIZE], uint8_t startRow, uint8_t startCol, uint8_t num);
void randomPick(uint8_t board[SIZE][SIZE],uint8_t diff);
void generate_sudoku(uint8_t board[SIZE][SIZE],unsigned int seed)
{
    srand(seed);
    fillpattern();
    fillDiagonal(board);
    solveSudoku(board,0,0);
    randomPick(board,9);
}
int main(int argc, char *argv[])
{
    uint8_t board[SIZE][SIZE] = { UNASSIGNED }; 
    generate_sudoku(board,time(NULL));
    printBoard(board);
    putchar('\n');
    printf("%d",solutionSudoku(board,0,0));
    system("pause");
    return 0;
}

void fillpattern()
{
    uint8_t num[9] = {1,2,3,4,5,6,7,8,9};
    uint8_t n = 0;
    while(n < 9)
    {
        uint8_t i = rand() % 9;
        if(num[i] != 0)
        {
            pattern[n] = num[i];
            num[i] = 0;
            n++;
        }
    }
}

// void printBoard(uint8_t board[SIZE][SIZE])
// {
//     for (uint8_t i = 0; i < SIZE; i++)
//     {
//         for (uint8_t j = 0; j < SIZE; j++)
//         {
//             printf("%d ", board[i][j]);
//         }
//         printf("\n");
//     }
// }

void fillDiagonal(uint8_t board[SIZE][SIZE])
{
    for(uint8_t start = 0 ; start < SRSIZE; start++)
    {
        for (uint8_t i = 0; i < SRSIZE; i++)
        {
            for (uint8_t j = 0; j < SRSIZE; j++)
            {
                uint8_t n ;
                do
                {
                    n = rand() % 10;
                } while (checkBox(board,start * SRSIZE,start * SRSIZE,n));
                board[start * SRSIZE + i][start * SRSIZE + j] = n;
            }
        }
    }
}

bool solveSudoku(uint8_t board[SIZE][SIZE],uint8_t row, uint8_t col)
{
    if(col >= SIZE)
    {
        row += 1;
        col = 0;
    }
    if(row >= SIZE)
        return true;
    if(board[row][col] == UNASSIGNED)
    {
        for(uint8_t n = 0;n < SIZE ; n++)
        {
            uint8_t num = pattern[n];
            if(isSafe(board,row,col,num))
            {
                board[row][col] = num;
                if(solveSudoku(board,row,col+1))
                    return true;
            }
        }
        board[row][col] = UNASSIGNED;
        return false;
    }
    return solveSudoku(board,row,col+1);
}

bool isSafe(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t col, uint8_t num)
{
    return !(checkRow(board, row, num) || checkCollum(board, col, num) || checkBox(board, row - row % SRSIZE, col - col % SRSIZE, num));
}

// bool checkRow(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t num)
// {
//     for (uint8_t col = 0; col < SIZE; col++)
//     {
//         if (board[row][col] == num)
//             return true;
//     }
//     return false;
// }

// bool checkCollum(uint8_t board[SIZE][SIZE], uint8_t col, uint8_t num)
// {
//     for (uint8_t row = 0; row < SIZE; row++)
//     {
//         if (board[row][col] == num)
//             return true;
//     }
//     return false;
// }

// bool checkBox(uint8_t board[SIZE][SIZE], uint8_t startRow, uint8_t startCol, uint8_t num)
// {
//     for (uint8_t i = 0; i < SRSIZE; i++)
//     {
//         for (uint8_t j = 0; j < SRSIZE; j++)
//         {
//             if (board[startRow + i][startCol + j] == num)
//                 return true;
//         }
//     }
//     return false;
// }

void randomPick(uint8_t board[SIZE][SIZE],uint8_t diff)
{
    uint8_t pick = 0, rep = 0 , row , col , temp;
    while(rep < diff && (pick < diff * 2 * SIZE || rand() % (diff * (SIZE * SIZE - pick))))
    {
        do{
            row = rand() % 9;
            col = rand() % 9;
        }while (board[row][col] == UNASSIGNED);
        temp = board[row][col]; 
        board[row][col] = 0;
        if(solutionSudoku(board,0,0) != 1)
        {
            board[row][col] = temp;
            rep++;
        }
        else
        {
            pick++;
        }
    }
    printf("pick Empty = %d\n",pick);
}

int solutionSudoku(uint8_t board[SIZE][SIZE], uint8_t row, uint8_t col)
{
    int sol = 0;
    if(col >= SIZE)
    {
        row += 1;
        col = 0;
    }
    if(row >= SIZE)
        return 1;
    if(board[row][col] == UNASSIGNED)
    {
        for(uint8_t n = 0;n < SIZE ; n++)
        {
            uint8_t num = pattern[n];
            if(isSafe(board,row,col,num))
            {
                board[row][col] = num;
                sol += solutionSudoku(board,row,col+1);
            }
            board[row][col] = UNASSIGNED;
        }
        return sol;
    }
    sol += solutionSudoku(board,row,col+1);
    return sol;
}
