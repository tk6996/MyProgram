#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    short attribute[26] = {[0 ... 25] = 0};
    while (1)
    {
        char args[2][7];
        switch ((char)getchar())
        {
        case '=' :
            scanf("%s %s",args[0],args[1]);
            attribute[args[0][0]-'A'] =(short)strtol(args[1],'\0',10);
            break;
        case '#' :
            scanf("%s",args[0]);
            printf("%d\n",attribute[args[0][0]-'A']);
            break;
        case '+' :
            scanf("%s %s",args[0],args[1]);
            attribute[args[0][0]-'A']+=attribute[args[1][0]-'A'];
            break;
        case '-' :
            scanf("%s %s",args[0],args[1]);
            attribute[args[0][0]-'A']-=attribute[args[1][0]-'A'];
            break;
        case '*' :
            scanf("%s %s",args[0],args[1]);
            attribute[args[0][0]-'A']*=attribute[args[1][0]-'A'];
            break;
        case '/' :
            scanf("%s %s",args[0],args[1]);
            attribute[args[0][0]-'A']/=attribute[args[1][0]-'A'];
            break;
        case '!' :
            putchar('!');
            return 0;
        default:
            break;
        }
    }    
    return 0;
}