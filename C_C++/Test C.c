#include<stdio.h>
int main()
{
    int score;
    printf("Enter Your Score for Show Grade\n");
    scanf("%d",&score);
    if(score>100||score<0)
        printf("Error your score");
    else
    if(score>=80)
        printf("Your grade is A");
    else
    if(score>=70)
        printf("Your grade is B");
    else
    if(score>=60)
        printf("Your grade is C");
    else
    if(score>=50)
        printf("Your grade is D");
    else
        printf("Your grade is F");
    return 0;
}
