#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxline 1024
void Separate(char *,char *,char *);
int Checkpat(char *,char *);
int Compare(const void *,const void *);
int main(int argc,char *argv[])
{
		FILE *fp;
		if(strcmp(argv[1],"-r")==0){
				char pat1[Maxline],pat2[Maxline];
				Separate(argv[2],pat1,pat2);
				while(Checkpat(pat1,pat2)!=0){
						printf("The length of patterns are different, please re-enter the pattern:\n");
						printf("Enter the pattern1:\n"); scanf("%s",&pat1);
						printf("Enter the pattern2:\n"); scanf("%s",&pat2);
				}
				fp=fopen(argv[3],"r+");
				if(fp==NULL){
						printf("File not found.\n"); return 0;
				}
				int sum=0;
				char *line,*head,*ptr;
				line=(char *)malloc(sizeof(char)*Maxline);
				while(fgets(line,Maxline,fp)){
						head=line;
						while(ptr=strstr(line,pat1)){
								fseek(fp,(ptr-head)+sum,SEEK_SET);
								fputs(pat2,fp);
								line=ptr+strlen(pat1);
						}
						sum+=strlen(line);
						fseek(fp,sum,SEEK_SET);
				}
		}
		else if(strcmp(argv[1],"-s")==0){
				fp=fopen(argv[2],"r+");
				if(fp==NULL){
						printf("File not found.\n"); return 0;
				}
				int nofl=0;
				char line[Maxline],*list[Maxline];
				while(fgets(line,Maxline,fp)){
						list[nofl]=(char *)malloc(sizeof(char)*Maxline);
						strcpy(list[nofl++],line);
				}
				qsort((void *)list,nofl,sizeof(char *),Compare);
				fseek(fp,0,SEEK_SET);
				while(nofl--) fputs(list[nofl],fp);
		}
		else{
				printf("Input error.\n"); return 0;
		}
		return 0;
}
void Separate(char *pat,char *pat1,char *pat2){
		while(*pat!=',') *pat1++=*pat++;
		pat++;
		while(*pat!=' ') *pat2++=*pat++;
}
int Checkpat(char *pat1,char *pat2){
		return (strlen(pat1)-strlen(pat2));
}
int Compare(const void *a,const void *b){
		return (-1)*(strcmp(*(char **)a,*(char **)b));
}
