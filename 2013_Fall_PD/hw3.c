#include<stdio.h>

float radical(float a)
{
		float i,j,k;
		for(i=0;i*i<=a;i++)
		{
				j=i;
		}
		for(j=i-1;j*j<=a;j+=0.1)
		{
				k=j;
		}
		return k;
}

unsigned int logarithmic(unsigned int b)
{
		unsigned int l,m=0;
		for(l=1;b>=2;b/=2)
		{
				m++;
		}
		return m;
}

int prime(float c)
{
		int n,o;
		for(n=c-1;n>0;n--)
		{
				if(n==1)
				{
						return 1;
				}
				for(o=n-1;o>0;o--)
				{
						if(o==1)
						{
								return n;
						}
						else if(n%o==0)
						{
								break;
						}
				}
		}
}

int main()
{
		float x;
		while(scanf("%f",&x))
		{
				if(x==0)
				{
						break;
				}
				if(x<=3)
				{
				}
				else
				{
						printf("¿é¤J¼Æ¦r:%.0f\n",x);
						printf("square root of X:%.1f\n",radical(x));
						printf("log base 2 of X:%d\n",logarithmic(x));
						printf("nearest prime number:%d\n",prime(x));
				}
		}
}
