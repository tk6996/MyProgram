#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
uint8_t checkPalindrome(const char *str, int len)
{
    int i;
    for (i = 0; i < len / 2; i++)
    {
        if(tolower(str[i]) != tolower(str[len - 1 - i]))
            break;
    }
    if (i == len / 2)
        return 1;
    else
        return 0;
}
int main()
{
    char str[201];
    gets(str);
    uint8_t bit = checkPalindrome(str, strlen(str));
    if (bit)
    {
        bit += checkPalindrome(str, strlen(str) / 2);
    }
    switch (bit)
    {
    case 0b10:
        puts("Double"
             " "
             "Palindrome");
        break;
    case 0b1:
        puts("Palindrome");
        break;
    case 0b0:
        puts("No");
        break;
    default:
        break;
    }
    return 0;
}