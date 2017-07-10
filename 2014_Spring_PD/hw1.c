#include<stdio.h>
#include<string.h>
int checknumber(char word[],int s)
{
		int i,c,n=strlen(word);
		switch(s){
				case 0:
						for(i=0;i<n;i++){
								c=word[i];
								if(c<'0'||c>'9'){
										printf("There are some numbers undefined in Decimal.\n");
										return 1;
								}
						}
						return 0;
				case 1:
						for(i=0;i<n;i++){
								c=word[i];
								if(c<'0'||c>'1'){
										printf("There are some numbers undefined in Binary.\n");
										return 1;
								}
						}
						return 0;
				case 2:
						for(i=0;i<n;i++){
								c=word[i];
								if(c<'0'||(c>'9'&&c<'A')||c>'F'){
										printf("There are some numbers undefined in Hexadecimal.\n");
										return 1;
								}
						}
						return 0;
		}
}
int convert(char s[],int sys)
{
		int sum=0;
		int i,c,n=strlen(s);
		switch(sys){
				case 0: return atoi(s);
				case 1:
						for(i=0;i<n;i++){
								sum+=((s[i]-'0')<<(n-i-1));
						}
						return sum;
				case 2:
						for(i=0;i<n;i++){
								if(s[i]>='0'&&s[i]<='9'){
										sum+=((s[i]-'0')<<(4*(n-i-1)));
								}
								else{
										sum+=((s[i]-'A'+10)<<(4*(n-i-1)));
								}
						}
						return sum;
		}
}
int compute(int s,int t,int u,int *v)
{
		switch(u){
				int sum=0;
				case 0:
				case 1:
						sum=s+t;
						return sum;
				case 2:
						sum=s-t;
						return sum;
				case 3:
						sum=s*t;
						return sum;
				case 4:
						if(t==0){
								printf("The denominator must not be zero.\n");
								*v=0;
								break;
						}
						else{
								sum=s/t;
								return sum;
						}
		}
}
int main(int argc,char *argv[])
{
		if(argc<3 || argc>5){
				printf("The number of parameter is wrong.\n");
				return 0;
		}
		int i=0,n=0;
		int operator=0; /* 0,1,2,3,4表加、加、減、乘、除 */
		int system=0; /* 0,1,2表十進位、二進位、十六進位 */
		char num1[20],num2[20];
		for(i=1;i<argc;i++){
				if(argv[i][0]=='-'){
						if(strlen(argv[i])>2){
								printf("There are some parameters undefined.\n");
								return 0;
						}
						if(operator!=0){
								switch(argv[i][1]){
										case 'a':
										case 'm':
										case 'd':
										case 'n':
										printf("The parameters conflict.\n");
										return 0;
										default:break;
								}
						}
						if(system!=0){
								switch(argv[i][1]){
										case 'b':
										case 'h':
										printf("The parameters conflict.\n");
										return 0;
										default:break;
								}
						}
						switch(argv[i][1]){
								case 'a':operator=1;break;
								case 'm':operator=2;break;
								case 'd':operator=3;break;
								case 'n':operator=4;break;
								case 'b':system=1;break;
								case 'h':system=2;break;
								default:printf("There are some parameters undefined.\n");
								return 0;
						}
				}
				else if(n<2 && argc-i<=2){
						if(n==0){
								strcpy(num1,argv[i]),n++;
						}
						else{
								strcpy(num2,argv[i]),n++;
						}
				}
				else{
						printf("The number of parameter or the sort of parameters is wrong.\n");
						return 0;
				}
		}
		if(n!=2){
				printf("There must be 2 numbers.\n");
				return 0;
		}
		if(checknumber(num1,system)) return 0;
		if(checknumber(num2,system)) return 0;
		int n1=0,n2=0,state=1,ans=0;
		n1=convert(num1,system);
		n2=convert(num2,system);
		ans=compute(n1,n2,operator,&state);
		if(state){
				printf("Result:%d\n",ans);
		}
		return 0;
}
