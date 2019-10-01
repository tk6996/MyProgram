#include <stdio.h>
int main(int argc, char const *argv[])
{
    int amount=100,price=100;
    for(int i=1;(5*i)<amount && i<price; i++)
    {
        for(int j=1;j+(5*i)<amount && (j*15)+i<price;j++)
        {
            if(j+(5*i)==(j*15)+i)
            {
                if(amount-(j+(5*i))!=0)
                    printf("shimp = %d , chicken = %d , squid = %d\n",i,amount-(j+(5*i)),j);
            }
        }
    }
    return 0;
}