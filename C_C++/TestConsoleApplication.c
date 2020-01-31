#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#define gotoxy(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y})
/*
FOREGROUND_BLUE	= Text color contains blue.
FOREGROUND_GREEN = Text color contains green.
FOREGROUND_RED = Text color contains red.
FOREGROUND_INTENSITY = Text color is intensified.
BACKGROUND_BLUE = Background color contains blue.
BACKGROUND_GREEN = Background color contains green.
BACKGROUND_RED = Background color contains red.
BACKGROUND_INTENSITY = Background color is intensified.
COMMON_LVB_LEADING_BYTE = Leading byte.
COMMON_LVB_TRAILING_BYTE = Trailing byte.
COMMON_LVB_GRID_HORIZONTAL = Top horizontal.
COMMON_LVB_GRID_LVERTICAL = Left vertical.
COMMON_LVB_GRID_RVERTICAL = Right vertical.
COMMON_LVB_REVERSE_VIDEO = Reverse foreground and background attributes.
COMMON_LVB_UNDERSCORE = Underscore.*/
#define setTextAttribute(attr) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr)
void printBoard(uint8_t board[9][9]);
int main()
{
    uint8_t board[9][9] = {0};
    printBoard(board);
}
void printBoard(uint8_t board[9][9])
{
    uint8_t horizonbar[] = {205, 205, 205, 205, 205, 205, 205, 205, 205, 0};
    printf("\xc9"
           "%s"
           "\xcb"
           "%s"
           "\xcb"
           "%s"
           "\xbb"
           "\n",
           horizonbar, horizonbar, horizonbar);
    for (uint8_t k = 0; k < 3; k++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            putchar(186);
            for (uint8_t i = 0; i < 3; i++)
            {
                putchar(' ');
                putchar(board[j + 3 * k][0 + i * 3] + '0');
                putchar(' ');
                putchar(' ');
                putchar(board[j + 3 * k][1 + i * 3] + '0');
                putchar(' ');
                putchar(' ');
                putchar(board[j + 3 * k][2 + i * 3] + '0');
                putchar(' ');
                putchar(186);
            }
            putchar('\n');
            if (j == 2)
                continue;
            putchar(186);
            for (uint8_t i = 0; i < 3; i++)
            {
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(' ');
                putchar(186);
            }
            putchar('\n');
        }
        if (k == 2)
            continue;
        printf("\xcc"
               "%s"
               "\xce"
               "%s"
               "\xce"
               "%s"
               "\xb9"
               "\n",
               horizonbar, horizonbar, horizonbar);
    }
    printf("\xc8"
           "%s"
           "\xca"
           "%s"
           "\xca"
           "%s"
           "\xbc"
           "\n",
           horizonbar, horizonbar, horizonbar);
}