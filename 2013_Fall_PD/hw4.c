#include<stdio.h>
#include<string.h>
#define MaxWord 1000
char word[MaxWord];
int getword(char numbers[MaxWord],int max)
{
		int c;
		while((c=getchar())!=EOF) /*取得字元的值*/
		{
				memset(word,'\0',MaxWord); /*重設word陣列的值*/
				if(c!='\t'&&c!='\n'&&c!=' ')
				{
						int n; /*紀錄字串長度*/
						word[0]=c;
						for(n=1;n<MaxWord-1;n++)
						{
								if((c=getchar())!=EOF&&c!='\t'&&c!='\n'&&c!=' ')
								{
										word[n]=c; /*紀錄非空白字串*/
								}
								else break; /*停止紀錄字串*/
						}
						int d=word[0]; /*判斷字首是否為數字*/
						if(d>='0'&&d<='9')
						{
								return 1;
						}
				}
}
}

int main()
{
		int sum=0,num=0;
		int max,min;
		while(getword(word,MaxWord)>0)
		{
				char step[MaxWord];
				memset(step,'\0',MaxWord);
				int i,n=0;
				num+=1;
				for(i=0;i<MaxWord-1;i++)
				{
						int c=word[i];
						if(c>='0'&&c<='9')
						{
								step[n]=word[i]; /*取出含數字部份*/
								n++; /*取出數字的長度*/
						}
						else break; /*停止紀錄非數字字元*/
				}
				if(num==1)
				{
						max=atoi(step);
						min=atoi(step);
				}
				sum+=atoi(step);
				if(atoi(step)>max)
				{
						max=atoi(step);
				}
				if(atoi(step)<min)
				{
						min=atoi(step);
				}
		}
		printf("# of numbers: %d\n",num);
		printf("sum of numbers: %d\n",sum);
		printf("min number: %d\n",min);
		printf("max number: %d\n",max);
}
