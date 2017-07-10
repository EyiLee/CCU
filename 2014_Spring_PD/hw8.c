#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"mydictionary.h"
#define Maxline 2047
void makelist(int *);
int getdict(char *,FILE *);
int getword(char *,char *,FILE *);
int main(int argc,char *argv[])
{
		FILE *fdinput,*fdoutput;
		int list[30];
		char line[Maxline],last[Maxline],outfile[Maxline];
		if(argc>3){
				printf("Input Error!\n"); return 0;
		}
		argc==2 ? (fdinput=fopen(argv[1],"r")) : (fdinput=fopen(argv[2],"r"));
		if(fdinput==NULL){
				printf("File not found!\n"); return 0;
		}
		argc==2 ? (sprintf(outfile,"%s.dc",argv[1])) : (sprintf(outfile,"%s.ex",argv[2]));
		fdoutput=fopen(outfile,"w");
		makelist(list);
		int len;
		if(strcmp(argv[1],"-d")==0){
				while(len=getdict(line,fdinput)){
						if(len==2){
								int num=0,dc1=line[0],dc2=line[1];
								num+=(dc1&127)<<8;
								if(dc2<0) dc2+=256;
								num+=dc2;
								if(dictionary[num]!=NULL){
										fprintf(fdoutput,"%s",dictionary[num]);	continue;
								}
						}
						fprintf(fdoutput,"%s",line);
				}
				fclose(fdinput);
				fclose(fdoutput);
				return 0;
		}
		else{
				while(getword(line,last,fdinput)){
						if(strlen(line)<=1){
								fprintf(fdoutput,"%s%s",line,last);	continue;
						}
						int from,to,i;
						char dc1,dc2;
						from=list[line[0]-'a'];
						to=list[line[0]-'a'+1];
						for(i=from;i<to;i++){
								if(strcmp(line,dictionary[i])==0){
										dc1=((i>>8)|128);
										dc2=i&255;
										fprintf(fdoutput,"%c%c%s",dc1,dc2,last);
										break;
								}
						}
						if(i==to) fprintf(fdoutput,"%s%s",line,last);
				}
				fclose(fdinput);
				fclose(fdoutput);
				return 0;
		}
}
int getdict(char *s,FILE *f)
{
		int c;
		while((c=fgetc(f))!=EOF){
				memset(s,'\0',Maxline);
				if(c&128){
						*s++=c;
						*s=fgetc(f);
						return 2;
				}
				*s=c;
				return 1;
		}
		return 0;
}
int getword(char *s,char *t,FILE *f)
{
		int c;
		while((c=fgetc(f))!=EOF){
				memset(s,'\0',Maxline);
				memset(t,'\0',Maxline);
				if(isalpha(c)){
						*s++=c;
						while((c=fgetc(f))!=EOF && isalpha(c)) *s++=c;
						*t=c;
						return 1;
				}
				*s=c;
				return 1;
		}
		return 0;
}
void makelist(int *list)
{
		int i=0,j=0;
		while(dictionary[i]!=NULL){
				if(dictionary[i][0]-'a'==j){
						list[j]=i; j++;
				}
				i++;
		}
		list[j]=--i;
}
