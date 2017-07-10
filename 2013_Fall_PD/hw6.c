#include<stdio.h>
int bitreverse(int data)
{
		int i,rev=0;
		for(i=0;i<32;i++)
		{
				rev|=setbit(data,i);
		}
		return rev;
}
int getbit(int data,int pos)
{
		int i=1,result;
		result=data&(i<<pos);
		return result!=0 ? 1:0;
}
int setbit(int data,int pos)
{
		int i=1,result;
		result=data&(i<<pos);
		return result!=0 ? i<<(31-pos):0;
}
int main()
{
		char bit[33]; bit[32]='\0';
		char rev[33]; rev[32]='\0';
		int n;
		while(scanf("%d",&n))
		{
				int i;
				if(n==0) break;
				for(i=0;i<32;i++)
				{
						bit[31-i]=(getbit(n,i)+48);
						rev[31-i]=(getbit(bitreverse(n),i)+48);
				}
				printf("%s\n",bit);
				printf("%s\n",rev);
		}
}
