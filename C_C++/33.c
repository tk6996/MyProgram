#include<stdio.h>
int main(){
    double m,kg,bmi;
    scanf("%lf %lf",&m,&kg);
    bmi=kg/(m*m);
    printf("%.1lf",bmi);
}
