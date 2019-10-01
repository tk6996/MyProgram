#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eval(arg) #arg
enum Direction
{
    NORTH,EAST,SOUTH,WEST
};
typedef enum Direction Direction;
enum MoveDirection
{
    FD,RT,LT,BW
};
typedef enum MoveDirection MoveDirection;
struct Position
{
    int x;
    int y;
};
typedef struct Position Position;
struct Tutle
{
    Position pos;
    Direction dir;
};
typedef struct Tutle Tutle;
Tutle *ConstructorTutle()
{
    Tutle *this = malloc(sizeof(this));
    this->dir = EAST;
    this->pos.x = 0;
    this->pos.y = 0;
    return this;
}
int borderCheck(Position pos)
{
    return -50000<pos.x && pos.x<50000 && -50000<pos.y && pos.y<50000  ? 0 : -1; 
}
void moveTutle(Tutle *this,MoveDirection moveDir,int magnitude)
{
    switch (moveDir)
    {
    case FD : break;
    case RT : this->dir = (this->dir+1) % 4; break;
    case LT : this->dir = (this->dir+3) % 4; break;
    case BW : this->dir = (this->dir+2) % 4; break;
    default: break;
    }
    switch (this->dir)
    {
    case NORTH : (this->pos.y)+=magnitude; break;
    case EAST  : (this->pos.x)+=magnitude; break;
    case SOUTH : (this->pos.y)-=magnitude; break;
    case WEST  : (this->pos.x)-=magnitude; break;    
    default:
        break;
    }
}
MoveDirection castMD_string_to_enum(const char* string)
{
    if(strcmp(eval(FD),string) == 0) return FD;
    if(strcmp(eval(RT),string) == 0) return RT;
    if(strcmp(eval(LT),string) == 0) return LT;
    if(strcmp(eval(BW),string) == 0) return BW;
    return -1;
}
int main()
{
    int num;
    Tutle *tutle = ConstructorTutle();
    int magnitude;
    char command[3];
    scanf("%d",&num);
    for (int i = 0; i < num; i++)
    {
        scanf("%2s %d",command,&magnitude);
        moveTutle(tutle,castMD_string_to_enum(command),magnitude);
        if(borderCheck(tutle->pos)){
            puts("DEAD");
            return 0;
        }
    }
    printf("%d %d\n%c",tutle->pos.x,tutle->pos.y,"NESW"[tutle->dir]);
    return 0;
}