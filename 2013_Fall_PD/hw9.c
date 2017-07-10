#include<stdio.h>
#include<string.h>
#define Maxline 1024
int sindex(char *s,char *t)
{
		int i,j,k;
		for(i=0;*(s+i)!='\0';i++){
				for(j=i,k=0;*(t+k)!='\0'&&*(s+j)==*(t+k);j++,k++);
				if(k>0&&*(t+k)=='\0') return i;
		}
		return -1;
}
void scat(char *s,char *t)
{
		int i=slen(s);
		for(s+=i;*t!='\0';*s++=*t++);
}
int slen(char *s)
{
		int i=0;
		while(*s++!='\0') i++;
		return i;
}
int palindrome(char *s)
{
		int i=slen(s);
		int j=0;
		char *ss=s,*st=s+i-1;
		while(*ss++==*st--){
				j++;
				if(j>i/2) return 1;
		}
		return 0;
}
void converse(char *s)
{
		int i=slen(s),j;
		char *ss=s+i-1,step;
		for(j=0;j<i/2;j++){
				step=*s;
				*s++=*ss;
				*ss--=step;
		}
}
int main()
{
		char line1[Maxline],line2[Maxline];
		memset(line1,'\0',Maxline);
		memset(line2,'\0',Maxline);
		while(scanf("%s\n%s",&line1,&line2))
		{
				if(palindrome(line1)){
						printf("%s為Palindrome\n(程式結束)\n",line1);
						break;
				}
				else if(palindrome(line2)){
						printf("%s為Palindrome\n(程式結束)\n",line2);
						break;
				}
				else if(sindex(line1,line2)!=-1){
						printf("%s為%s子字串\n(程式結束)\n",line2,line1);
						break;
				}
				else if(sindex(line2,line1)!=-1){
						printf("%s為%s子字串\n(程式結束)\n",line1,line2);
						break;
				}
				else{
						scat(line1,line2);
						printf("Result of　strcat(A,B)：%s\n",line1);
						converse(line1);
						printf("Result of converse(strcat(A,B))：%s\n",line1);
				}				
				memset(line1,'\0',Maxline);
				memset(line2,'\0',Maxline);
		}
		return 0;
}
