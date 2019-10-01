#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
    float x,y,b,c,d,s,u,v,a,t,t1,t2;
    printf("Distance            :s     Enter 1\n");
    printf("Speed Start         :u     Enter 2\n");
    printf("Speed at that moment:v     Enter 3\n");
    printf("Accelerate          :a     Enter 4\n");
    printf("Time                :t     Enter 5\n\n");
    do{
    printf("Do you want :");
    scanf("%f",&x);
    if(x<1||x>5)
        printf("Error\n");
    }while(x<1||x>5);
    do{
    printf("Don't you want :");
    scanf("%f",&y);
    if(y==x||y<1||y>5)
        printf("Error\n");
    }while(y==x||y<1||y>5);

    b=pow(10,x);
    c=pow(10,y);
    d=b+c;
    if(d==110)
    {
        printf("Enter v=");
        scanf("%f",&v);
        printf("Enter a=");
        scanf("%f",&a);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==1010)
    {
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter a=");
        scanf("%f",&a);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==10010)
    {
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter v=");
        scanf("%f",&v);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==100010)
    {
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter v=");
        scanf("%f",&v);
        printf("Enter a=");
        scanf("%f",&a);
    }
    if(d==1100)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter a=");
        scanf("%f",&a);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==10100)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter v=");
        scanf("%f",&v);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==100100)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter v=");
        scanf("%f",&v);
        printf("Enter a=");
        scanf("%f",&a);
    }
    if(d==11000)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter t=");
        scanf("%f",&t);
    }
    if(d==101000)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter a=");
        scanf("%f",&a);
    }
    if(d==110000)
    {
        printf("Enter s=");
        scanf("%f",&s);
        printf("Enter u=");
        scanf("%f",&u);
        printf("Enter v=");
        scanf("%f",&v);
    }
    if(x==1)//s
    {
        if(d==110)
        {
            s=(v*t)-(0.5*a*t*t);
            printf("Answer s=%f",s);
        }
        if(d==1010)
        {
            s=(u*t)+(0.5*a*t*t);
            printf("Answer s=%f",s);
        }
        if(d==10010)
        {
            s=((v+u)*0.5)*t;
            printf("Answer s=%f",s);
        }
        if(d==100010)
        {
            s=((v-u)*(v+u))/(2*a);
            printf("Answer s=%f",s);
        }
    }
    if(x==2)//u
    {
        if(d==110)
        {
            u=v-(a*t);
            printf("Answer u=%f",u);
        }
        if(d==1100)
        {
            u=(s-(0.5*a*t*t))/t;
            printf("Answer u=%f",u);
        }
        if(d==10100)
        {
            u=(2*s/t)-v;
            printf("Answer u=%f",u);
        }
        if(d==100100)
        {
            u=pow(v*v-(2*a*s),0.5);
            printf("Answer u=%f",u);
        }
    }
    if(x==3)//v
    {
        if(d==1010)
        {
            v=u+(a*t);
            printf("Answer v=%f",v);
        }
        if(d==1100)
        {
            v=(s/t)+(0.5*a*t);
            printf("Answer v=%f",v);
        }
        if(d==11000)
        {
            v=(2*s/t)-u;
            printf("Answer v=%f",v);
        }
        if(d==101000)
        {
            v=pow((u*u)+(2*a*s),0.5);
            printf("Answer v=%f",v);
        }
    }
    if(x==4)//a
    {
        if(d==10010)
        {
            a=(v-u)/t;
            printf("Answer a=%f",a);
        }
        if(d==10100)
        {
            a=2*((v*t)-s)/t/t;
            printf("Answer a=%f",a);
        }
        if(d==11000)
        {
            a=2*(s-(u*t))/t/t;
            printf("Answer a=%f",a);
        }
        if(d==110000)
        {
            a=(v-u)*(v+u)/2/s;
            printf("Answer a=%f",a);
        }
    }
    if(x==5)//t
    {
        if(d==100010)
        {
            t=(v-u)/a;
            printf("Answer t=%f",t);
        }
        if(d==100100)
        {
            t1=((v+pow((v*v)-2*a*s,0.5)))/a;
            t2=((v-pow((v*v)-2*a*s,0.5)))/a;
            printf("Answer t=%f,%f",t1,t2);
        }
        if(d==101000)
        {
            t1=((-u+pow((u*u)+2*a*s,0.5)))/a;
            t2=((-u-pow((u*u)+2*a*s,0.5)))/a;
            printf("Answer t=%f,%f",t1,t2);
        }
        if(d==110000)
        {
            t=2*s/(u+v);
            printf("Answer t=%f",t);
        }
    }
    getch();
    return 0;
}
