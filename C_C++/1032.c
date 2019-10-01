#include <stdio.h>
#include <string.h>
int checkcol(char table[9][9], int col)
{
    char boolean[9] = {[0 ... 8] = 0};
    for (int i = 0; i < 9; i++)
    {
        if (table[i][col] == '0')
            continue;
        if (boolean[table[i][col] - '1'] == 0)
            boolean[table[i][col] - '1'] = 1;
        else
            return 0;
    }
    return 1;
}
int checkrow(char table[9][9], int row)
{
    char boolean[9] = {[0 ... 8] = 0};
    for (int i = 0; i < 9; i++)
    {
        if (table[row][i] == '0')
            continue;
        if (boolean[table[row][i] - '1'] == 0)
            boolean[table[row][i] - '1'] = 1;
        else
            return 0;
    }
    return 1;
}
int checkbox(char table[9][9], int row, int col)
{
    char boolean[9] = {[0 ... 8] = 0};
    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
    {
        for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++)
        {
            if (table[i][j] == '0')
                continue;
            if (boolean[table[i][j] - '1'] == 0)
                boolean[table[i][j] - '1'] = 1;
            else
                return 0;
        }
    }
    return 1;
}
int main(void)
{
    char table[9][9];
    int max = 81;
    int i = 0;
    int amount;
    scanf("%d", &amount);
    while (i < max)
    {
        char in;
        if ((in = getchar()) && (in >= '0' && in <= '9'))
        {
            table[i / 9][i % 9] = in;
            i++;
        }
    }
    for (int ind = 0; ind < amount; ind++)
    {
        char board[9][9];
        memcpy(board, table, 81);
        int boolean = 1;
        i = 0;
        while (i < max)
        {
            char in;
            if ((in = getchar()) && (in >= '0' && in <= '9'))
            {
                if (board[i / 9][i % 9] == '0')
                {
                    board[i / 9][i % 9] = in;
                    if (!(checkbox(board, i / 9, i % 9) && checkcol(board, i % 9) && checkrow(board, i / 9)))
                        boolean = 0;
                }
                else
                {
                    if (board[i / 9][i % 9] != in)
                        boolean = 0;
                }
                i++;
            }
        }
        if (boolean)
            printf("%d\n", ind + 1);
    }
    puts("END");
    return 0;
}