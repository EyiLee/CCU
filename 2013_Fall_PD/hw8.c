#include<stdio.h>
#include<string.h>
#define Maxline 1024
int sindex(char s[],char pat[])
{
		int c,i,j;
		for(i=0,j=0;j<5;i++){
				c=s[i];
				if(c=='\0') return -1;
				if(lower(c)==pat[j]) j++;
				else j=0;
		}
		return i-5;
}
int lower(int n)
{
		if(n>='A'&&n<='Z') n+=32;
		return n;
}
int getsize(char s[])
{
		int i;
		for(i=0;s[i]!='\0';i++);
		return i;
}
int getline(char s[])
{
		int i;
		for(i=0;s[i]!='\0';i++)
				if(s[i]=='\n') return 1;
		return 0;
}
int scmp(char s[])
{
		int i;
		char pat[6]={"apple"};
		for(i=0;s[i]==pat[i];i++)
				if(s[i]=='\0') return 1;
		return 0;
}
int getword(char s[],char t[],int time)
{
		int c,i,j=0,k=0;
		for(i=0;i<time;i++){
				for(;(c=s[j])!=' '&&c!='\t'&&c!='\n'&&c!='\0';j++);
				for(;(c=s[j])==' '||c=='\t'||c=='\n';j++);
		}
		for(;(c=s[j])!=' '&&c!='\t'&&c!='\n'&&c!='\0';j++)
				t[k++]=s[j];
		if(c=='\0') return 0;
}
void output(int start,char s[])
{
		int i;
		for(i=0;i<start;i++) printf("%c",s[i]);
		printf("<>");
		for(;i<start+5;i++) printf("%c",s[i]);
		printf("<>");
		for(;s[i]!='\0';i++) printf("%c",s[i]);
}
int main()
{
		char pattern[6]={"apple"};
		char line[Maxline];
		int size=0,nofline=0,nofmatch=0,nofpat=0;
		while(fgets(line,Maxline,stdin))
		{
				size+=getsize(line);
				if(getline(line))nofline+=1;
				int at;
				at=sindex(line,pattern);
				if(at!=-1){
						output(at,line);
						nofmatch+=1;
				}
				char word[Maxline];
				memset(word,'\0',Maxline);
				int t=0;
				while(getword(line,word,t)){
						nofpat+=scmp(word);
						t++;
						memset(word,'\0',Maxline);
				}
				memset(line,'\0',Maxline);
		}
		printf("filesize:%d\n",size);
		printf("# of lines:%d\n",nofline);
		printf("# of matched lines:%d\n",nofmatch);
		printf("# of pattern in the text:%d\n",nofpat);
}
