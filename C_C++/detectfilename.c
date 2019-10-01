#include <stdio.h>
int main()
{
    char path[100],buf[100],*p;
    int  i = 0;
    gets(path);
    p = path;
    while(*(p) != '\0')
    {
        if(*p == '\\' )
            i = 0;
        else
            buf[i++] = *p;
        p++;
    }
    buf[i] = '\0';
    puts(buf);
    return 0;
}