#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *dfa(const char *key, int len)
{
    int *lps = malloc(sizeof(lps) * (len + 1));
    lps[0] = 0;
    int l = 0;
    int state = 1;
    while (state < len)
    {
        if (key[state] == key[l])
            lps[state++] = ++l;
        else if (l > 0)
            l = lps[l - 1];
        else
            lps[state++] = 0;
    }
    return lps;
}
int kmf(const char *src, const char *key, int len)
{
    int *lps = dfa(key, len);
    int state = 0;
    while (*src != '\0' && state < len)
    {
        if (*src == key[state])
        {
            state++;
            src++;
        }
        else if (state > 0)
            state = lps[state - 1];
        else
            src++;
    }
    free(lps);
    return state == len ? 1 : 0;
}
void printsubstring(const char *src, int len)
{
    for (int i = 0; i < len; i++)
    {
        putchar(src[i]);
    }
    putchar('\n');
}
int main(void)
{
    char buf1[200];
    char buf2[200];
    char *src;
    char *key;
    scanf("%s %s", buf1, buf2);
    if (strlen(buf1) > strlen(buf2))
    {
        key = buf1;
        src = buf2;
    }
    else
    {
        src = buf1;
        key = buf2;
    }
    int sh_len = strlen(src);
    int lo_len = strlen(key);
    for (int i = sh_len; i >= 0; i--)
    {
        for (int j = 0; j <= sh_len - i; j++)
        {
            if (kmf(key, src + j, i))
            {
                printsubstring(src + j, i);
                return 0;
            }
        }
    }
    return 0;
}