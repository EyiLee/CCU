#include<stdio.h>
int mul[10][10];
void multiplication(int num)
{
		printf("乘法表:\n ");
		int i,j;
		for(i=1;i<=num;i++) printf("%*d",'\t',i);
		printf("\n");
		for(i=1;i<=num;i++)
		{
				printf("%d",i);
				for(j=1;j<=num;j++)
				{
						printf("%*d",'\t',mul[i][j]);
				}
				printf("\n");
		}
		printf("\n");
}
void triangle(int num)
{
		printf("三角形:\n");
		int i,j;
		for(i=num;i>0;i--)
		{
				for(j=0;j<i-1;j++)
				{
						printf(" ");
				}
				for(j=num-j;j>0;j--)
				{
						printf("%d",num);
				}
				printf("\n");
		}
		printf("\n");
}
void diamond(int num)
{
		printf("菱形:\n");
		char row[10][10];
		int i,j,k,l;
		for(i=1;i<=num;i++)
		{
				for(j=1;j<=num;j++)
				{
						row[i][j]=' ';
				}
		}
		for(i=(num/2+1),j=(num/2+1),k=1;k<=num;k++)
		{
				for(l=i;l<=j;l++)
				{
						row[k][l]=num+48;
				}
				if(k>num/2)
				{
						i++;j--;
				}
				else
				{
						i--;j++;
				}
		}
		for(i=1;i<=num;i++)
		{
				for(j=1;j<=num;j++)
				{
						printf("%c",row[i][j]);
				}
				printf("\n");
		}
		printf("\n");

}
int main()
{
		int i,j;
		for(i=1;i<=9;i++)
		{
				for(j=1;j<=9;j++)
				{
						mul[i][j]=i*j;
				}
		}
		int num;
		while(printf("input an odd number x:"),scanf("%d",&num))
		{
				switch(num)
				{
						case 0:
								return 0; break;

						case 5: case 7: case 9:
								printf("\n");
								multiplication(num); triangle(num); diamond(num); break;

						default: continue;
				}
		}
}
