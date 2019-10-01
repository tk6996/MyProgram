#include <stdio.h>
#include <stdlib.h>
typedef struct Pos
{
    int x;
    int y;
} Pos;
void printTable(char **table, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            putchar((table[i][j]) ? table[i][j] : ' ');
        }
        putchar('\n');
    }
}
int isBlock(Pos c[4], int x, int y)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (x == c[i].x && y == c[i].y)
            return 1;
    }
    return 0;
}
void move(char **table, Pos c[], int j, char in, int N)
{
    switch (in)
    {
    case 'N':
        if (c[j].y > 0 && !isBlock(c, c[j].x, c[j].y - 1))
            c[j].y--;
        break;
    case 'E':
        if (c[j].x < N - 1 && !isBlock(c, c[j].x + 1, c[j].y))
            c[j].x++;
        break;
    case 'S':
        if (c[j].y < N - 1 && !isBlock(c, c[j].x, c[j].y + 1))
            c[j].y++;
        break;
    case 'W':
        if (c[j].x > 0 && !isBlock(c, c[j].x - 1, c[j].y))
            c[j].x--;
        break;
    }
    table[c[j].y][c[j].x] = '1' + j;
}
int main()
{
    int N, round;
    scanf("%d %d", &N, &round);
    char **table = (char **)malloc(N * sizeof(char *));
    for (size_t i = 0; i < N; i++)
        table[i] = (char *)calloc(N, sizeof(char));
    Pos c[] = {{N - 1, 0}, {N - 1, N - 1}, {0, N - 1}, {0, 0}};
    table[c[0].y][c[0].x] = '1', table[c[1].y][c[1].x] = '2', table[c[2].y][c[2].x] = '3', table[c[3].y][c[3].x] = '4';
    //printTable(table, N);
    char m[4][round];
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < round; j++)
        {
            char in;
            scanf(" %c", &in);
            m[i][j] = in;
        }
    }
    for (size_t i = 0; i < round; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            move(table, c, j, m[j][i], N);
        }
    }
    //printTable(table,N);
    int p[4] = {}, max = -1;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (table[i][j] == 0)
            {
                puts("No");
                goto skip;
            }
            p[table[i][j] - '1']++;
            if (max < p[table[i][j] - '1'])
                max = p[table[i][j] - '1'];
        }
    }
    int countwin = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (p[i] == max)
            countwin++;
    }
    printf("%d %d\n", countwin, max);
    for (size_t i = 0; i < 4; i++)
    {
        if (p[i] == max)
            printf("%d\n", i + 1);
    }
skip:
    /////////////////////////////////////
    for (size_t i = 0; i < N; i++)
    {
        free(table[i]);
    }
    free(table);
    return 0;
}