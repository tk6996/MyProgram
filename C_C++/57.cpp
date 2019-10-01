#include<stdio.h>
int main()
{
    int i,I,J,n,j=0,k=0,a[1000],odd[1000],even[1000],temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2==1||a[i]%2==-1) {odd[j]=a[i];j++;}
        else {even[k]=a[i];k++;}
    }
    // odd
    for(i=0;i<j-1;i++)
    {
        for(I=0;I<j-1;I++)
        if(odd[I]>odd[I+1])
            {temp=odd[I]; odd[I]=odd[I+1];odd[I+1]=temp;}
    }
    for(i=0;i<k-1;i++)
    {
    for(J=0;J<k-1;J++)
        if(even[J]>even[J+1])
     {temp=even[J]; even[J]=even[J+1];even[J+1]=temp;}}

    printf("Even number :");
    if(k==0) printf(" -"); else for(i=0;i<k;i++) printf(" %d",even[i]);
    printf("\n");
        printf("Odd number :");
    if(j==0) printf(" -"); else for(i=0;i<j;i++) printf(" %d",odd[i]);
}
