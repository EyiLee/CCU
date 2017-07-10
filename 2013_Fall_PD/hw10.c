#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxline 1024
int mystrcmp(char *s,char *t){
		while(*s++==*t++){
				if(*s=='\0') return 1;
		}
		return 0;
}
int mystrncmp(char *s,char *t,int n){
		int i=0;
		for(;i<n;i++){
				if(*s++!=*t++) return 0;
		}
		return 1;
}
int mystrstr(char *s,char *t){
		int i,len;
		len=strlen(t);
		for(i=0;*s!='\0';i++){
				if(mystrncmp(s,t,len)) return i;
				s++;
		}
		return -1;
}
int main(){
		char line[Maxline],longest[Maxline];
		char pattern[6]="apple";
		char *words[Maxline];
		int nofline=0,max=0;
		while(fgets(line,Maxline,stdin)){
				int at,sum=0;
				char *set;
				set=line;
				words[nofline]=(char *)malloc(Maxline);
				while((at=mystrstr(set,pattern))!=-1){
						strncat(words[nofline],set,at);
						words[nofline]+=at;
						strcat(words[nofline],"<<apple>>");				
						words[nofline]+=9;
						set+=(at+5);
						sum+=(at+9);
				}
				strcat(words[nofline],set);
				words[nofline]-=sum;
				int i=0,state=0;
				for(;i<nofline;i++){
						if(mystrcmp(words[i],words[nofline])){
								state=1;
								break;
						}
				}
				if(state==0){
						printf("%s",words[nofline]);
				}
				if(strlen(line)>max){
						memset(longest,'\0',Maxline);
						strcpy(longest,line);
						max=strlen(line);
				}
				else if(strlen(line)==max&&mystrstr(longest,line)){
						strcat(longest,"Long line :");
						strcat(longest,line);
				}
				nofline++;
		}
		printf("Long line :%s",longest);
		return 0;
}
