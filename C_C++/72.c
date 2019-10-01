#include<stdio.h>
#include<string.h>
int main()
{
    int i,az[26]={0},max=0,j=0,k,s[26]={0},o=0;
    char cha[100],c[26];
    scanf("%[^\t\n]s",cha);
    //printf("%d",strlen(cha));
    for(i=0;i<strlen(cha);i++)
    {
        if(cha[i]>='a'&&cha[i]<='z')   {az[cha[i]-'a']++;}
        if(cha[i]>='A'&&cha[i]<='Z')   {az[cha[i]-'A']++;}
    }
    for(i=0;i<26;i++)
    {
        if(max<az[i]) {max=az[i];j=0;c[j]='a'+i;}
        else if(max==az[i]&&max!=0) {j++;c[j]='a'+i;}
    }
    printf("Most Character = ");
    for(i=0;i<strlen(cha);i++)
    {
        for(k=0;k<=j;k++)
        {
            if(c[k]==cha[i]&&s[k]==0)
            {
                printf("%c",c[k]);
                s[k]++;o++;
                if(o<=j) printf(" , ");
            }
        }
    }
    printf("\nCharacter count = %d",max);
    return 0;
}