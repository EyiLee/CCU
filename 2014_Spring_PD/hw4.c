#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Maxline 1024
struct key{
		char name[Maxline];
		int count;
		struct key *next;
};
int getword(char *,FILE *);
void csort(struct key *ptr[],int size);
void nsort(struct key *ptr[],int size);
int main(int argc,char *argv[])
{
		FILE *fp;
		int i=0,nofw=0,state=1;
		char word[Maxline];
		struct key *keytab,*keyptr[Maxline],*head;
		keytab=(struct key *)malloc(sizeof(struct key)*Maxline);
		fp=fopen(argv[2],"rw");
		while(getword(word,fp)){
				if(strlen(word)<=1) continue;
				for(i=0;i<nofw;i++){
						if(strcmp(keytab->name,word)==0){
								keytab->count++;
								state=0;break;
						}
						if(i==nofw-1)	keytab->next=(struct key *)malloc(sizeof(struct key)*Maxline);
						keytab=keytab->next;
				}
				if(state){
						strcpy(keytab->name,word);
						keytab->count=1;
						keyptr[nofw]=(struct key *)malloc(sizeof(struct key)*Maxline);
						nofw++;
				}
				if(nofw==1) head=keytab;
				state=1;
				keytab=head;
		}
		for(i=0;i<nofw;i++){
				keyptr[i]=keytab;
				keytab=keytab->next;
		}
		if(argv[1][1]=='n') nsort(keyptr,nofw);
		if(argv[1][1]=='c') csort(keyptr,nofw);
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
void csort(struct key *ptr[], int size)
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
void nsort(struct key *ptr[], int size)
{
		int i;
		for(i=0;i<size-1;i++){
				int c,j,k,max;
				struct key *temp;
				max=i;
				for(j=i+1;j<size;j++){
						c=(strlen(ptr[j]->name)>strlen(ptr[max]->name) ? strlen(ptr[j]->name):strlen(ptr[max]->name));
						for(k=0;k<c;k++){
								if(ptr[j]->name[k]==ptr[max]->name[k]) continue;
								if(ptr[j]->name[k]<ptr[max]->name[k]) max=j;
								break;
						}
				}
				temp=ptr[i];
				ptr[i]=ptr[max];
				ptr[max]=temp;
		}
}
