#include<stdio.h>
float radical(float a)
{
		float i,j,k,l,m;
		for(i=0;i*i<=a;i++)
		{
				j=i;
		}
		for(j=i-1;j*j<=a;j+=0.1)
		{
				k=j;
		}
		for(k=j-0.1;k*k<=a;k+=0.01)
		{
				l=k;
		}
		for(l=k-0.01;l*l<=a;l+=0.001)
		{
				m=l;
		}
		return m;
}
int adjust(int score)
{
		int adj;
		adj=radical(score)*10;
		return adj;
}
int main()
{
		float n;
		while(scanf("%f",&n))
		{
				int i,score[100];
				float sum=0,pass=0,high,low;
				for(i=0;i<n;i++)
				{
						scanf("%d",&score[i]);
						if(score[i]>100)
						{
								i--;
								continue;
						}
						if(i==0)
						{
								high=score[i];
								low=score[i];
						}
						sum+=score[i];
						if(score[i]>=60) pass+=1;
						if(score[i]>high) high=score[i];
						if(score[i]<low) low=score[i];
				}
				float avg=sum/n;
				float std,dsum=0;
				for(i=0;i<n;i++)
				{
						dsum+=(score[i]-avg)*(score[i]-avg);
				}
				std=radical(dsum/(n-1));
				printf("Average: %.2f\n",avg);
				printf("Passed: %.0f\n",pass);
				printf("Max: %.0f\n",high);
				printf("Min: %.0f\n",low);
				printf("Standard Deviation: %.2f\n",std);
				printf("Adjust Grade:\n");
				for(i=0;i<n;i++)
				{
						printf("%d\n",adjust(score[i]));
				}
		}
}
