#include <stdio.h>
int main(void)
{
    const char *pattern = "CE Boost Up 7";
    char buf[100];
    scanf("%[^\n]s",buf);
    int i = 0;
    int correct = 1;
    while (pattern[i] != '\0' && buf[i] != '\0')
    {
        if(pattern[i] != buf[i]) 
        {
            correct = 0;
            break;
        }
        i++;  
    }
    if(pattern[i] != '\0' || buf[i] != '\0') correct = 0;
    printf("%s",correct ? "Yes !" : "No !");
    return 0;
}