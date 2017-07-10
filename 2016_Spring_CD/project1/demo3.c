#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Maxline 1024
struct key{
		char name[Maxline];
		int count;
};
int getword(char *,FILE *);
void ssort(struct key  *ptr[],int size);
int main(int argc,char *argv[])
{
		FILE *fp;
		int i=0,nofw=0,state=1;
		char word[Maxline];
		struct key keytab[Maxline],*keyptr[Maxline];
		fp=fopen(argv[1],"r");
		while(getword(word,fp)){
				if(strlen(word)<=1) continue;
				for(i=0;i<nofw;i++){
						if(strcmp(keytab[i].name,word)==0){
								keytab[i].count++;
								state=0;break;
						}
				}
				if(state){
						strcpy(keytab[nofw].name,word);
						keytab[nofw].count=1;
						keyptr[nofw]=(struct key *)malloc(sizeof(struct key)*Maxline);
						nofw++;
				}
				state=1;
		}
		for(i=0;i<nofw;i++) *keyptr[i]=keytab[i];
		ssort(keyptr,nofw);
		for(i=0;i<nofw;i++)	printf("%s %d\n",keyptr[i]->name,keyptr[i]->count);
}
int getword(char *w,FILE *f)
{
		int c;
		while((c=fgetc(f))!=EOF){
				memset(w,'\0',Maxline);
				if(isalpha(c)){
						*w++=c;
						while((c=fgetc(f))=='.'||isalpha(c)) *w++=c;
						return 1;
				}
		}
		return 0;
}
void ssort(struct key  *ptr[], int size)
{
		int i;
		for(i=0;i<size-1;i++){
				int j,max;
				struct key *temp;
				max=i;
				for(j=i+1;j<size;j++){
						if(ptr[j]->count>ptr[max]->count) max=j;
				}
				temp=ptr[i];
				ptr[i]=ptr[max];
				ptr[max]=temp;
		}
}
