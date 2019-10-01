#include<stdio.h>
int main()
{
    char d;
    int i=1;
    while(d!='P')
    {
        scanf("%c",&d);
        if(d=='R'&&i!=4) i++;
        if(d=='L'&&i!=1) i--;
    }
    printf("%d",i);
}
