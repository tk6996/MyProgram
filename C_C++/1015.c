#include <stdio.h>
#include <stdlib.h>
#define QUEUE_CAPACITY 10
typedef struct
{
    int x;
    int y;
} Position;
typedef struct
{
    Position data[QUEUE_CAPACITY];
    int head;
    int tail;
    int size;
} Queue;
Queue *constructorQueue(void)
{
    return calloc(1, sizeof(Queue));
}
void en_queue(Queue *this, Position val)
{
    if (this->size == QUEUE_CAPACITY)
        return;
    this->data[(this->tail)++] = val;
    this->tail %= QUEUE_CAPACITY;
    this->size++;
}
Position de_queue(Queue *this)
{
    Position val = this->data[(this->head)++];
    this->head %= QUEUE_CAPACITY;
    this->size--;
    return val;
}
Position front_queue(Queue *this)
{
    return this->data[this->head];
}
Position back_queue(Queue *this)
{
    return this->data[this->tail];
}
int check(int **table, int n, int y, int x)
{
    if (table[y][x] > 0)
    {
        int met = 0;
        int around = 0;
        unsigned char pass = 0;
        int choose = table[y][x];
        Queue *path = constructorQueue();
        Position pos = {.x = x, .y = y};
        en_queue(path, pos);
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (y + i < 0 || x + j < 0 || y + i >= n || x + j >= n)
                {
                    continue;
                }
                if (table[y + i][x + j] == choose)
                {
                    pass |= 0b1 << (i+1);
                    around++;
                }
            }
        }
        while (path->size)
        {
            for (int ind = 0, len = path->size; ind < len; ++ind)
            {
                Position cur = de_queue(path);
                if (table[cur.y][cur.x] == choose)
                {
                    ++met;
                    table[cur.y][cur.x] = 0;
                    if (cur.y > 0)
                    {
                        if (table[cur.y - 1][cur.x] == choose)
                        {
                            Position next = {.x = cur.x, .y = cur.y - 1};
                            en_queue(path, next);
                        }
                    }
                    if (cur.x > 0)
                    {
                        if (table[cur.y][cur.x - 1] == choose)
                        {
                            Position next = {.x = cur.x - 1, .y = cur.y};
                            en_queue(path, next);
                        }
                    }
                    if (cur.y < n - 1)
                    {
                        if (table[cur.y + 1][cur.x] == choose)
                        {
                            Position next = {.x = cur.x, .y = cur.y + 1};
                            en_queue(path, next);
                        }
                    }
                    if (cur.x < n - 1)
                    {
                        if (table[cur.y][cur.x + 1] == choose)
                        {
                            Position next = {.x = cur.x + 1, .y = cur.y};
                            en_queue(path, next);
                        }
                    }
                }
            }
        }
        free(path);
        return met == 3 && around == 3 && pass != 0b111 && (pass & 0b011 || pass & 0b101 || pass & 0b110) ? 1 : 0;
    }
    else
    {
        return 0;
    }
}
void printTable(int **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", table[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    int n;
    int count;
    scanf("%d", &n);
    int **col = malloc(sizeof(*col) * n);
    for (int i = 0; i < n; i++)
    {
        int *row = malloc(sizeof(row) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", row + j);
        }
        col[i] = row;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count += check(col, n, i, j);
            //printTable(col,n);
            //printf("\n%d\n\n",count);
        }
        free(col[i]);
    }
    free(col);
    printf("%d", count);
    return 0;
}