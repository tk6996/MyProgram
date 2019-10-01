#include <stdio.h>

int main()
{
	int arr[3][3],i,j;
    char a,b,c,d;
    int x,y;
   	/*for (j=1;j<=9;j++)
    {
    	//printf ("i %d\n",i);
    	if(j%2!=0)
    	{
    		a = 'O';
    		scanf ("%d %d",&x,&y);
    		arr[x][y] = a;
    		//printf ("arr %d\n",arr[x][y]);
    		for (i=0;i<3;i++)
			{
				if (arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
				{
					printf ("%c",arr[i][0]);
					//check=0;
					goto end;
				}
				else if (arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
				{
					printf ("%c",arr[0][i]);
					//check=0;
					goto end;
				}
				else if ((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]))
				{
					printf ("%c",arr[1][1]);
					//check=0;
					goto end;
				}
			}
		}
		else
		{
			a = 'X';
			scanf ("%d %d",&x,&y);
			arr[x][y] = a;
			//printf ("arr %d\n",arr[x][y]);
			for (i=0;i<3;i++)
			{
				if (arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
				{
					printf ("%c",arr[i][0]);
					//check=0;
					goto end;
				}
				else if (arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
				{
					printf ("%c",arr[0][i]);
					//check=0;
					goto end;
				}
				else if ((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]))
				{
					printf ("%c",arr[1][1]);
					//check=0;
					goto end;
				}
			}
		}
	}*/
    for (i=0;i<3;i++)
    {
    	scanf("%c%c%c%c",&a,&b,&c,&d);
    	if (a!='\0'&&b!='\0'&&c!='\0')
    	{
    		arr[i][0] = a;
    		arr[i][1] = b;
    		arr[i][2] = c;
    		//printf ("%c%c%c",arr[i][0],arr[i][1],arr[i][2]);
		}
		else
		{
			arr[i][0] = b;
    		arr[i][1] = c;
    		arr[i][2] = d;
    		//printf ("%c%c%c",arr[i][0],arr[i][1],arr[i][2]);
		}
	}
	for (i=0;i<3;i++)
	{
		if (arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])
		{
			printf ("%c",arr[i][0]);
			//check=0;
			goto end;
		}
		else if (arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])
		{
			printf ("%c",arr[0][i]);
			//check=0;
			goto end;
		}
		else if ((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]))
		{
			printf ("%c",arr[1][1]);
			//check=0;
			goto end;
		}
	}
	printf("-");
	end:/*printf("\n");
	for (i=0;i<3;i++)
	{
		for (x=0;x<3;x++)
		{
			printf("%c",arr[i][x]);
		}
		printf("\n");
	}*/
	return 0;
}
