#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Maxline 1024
struct tree{
		char name[Maxline];
		int count;
		struct tree *left;
		struct tree *right;
};
int getword(char *,FILE *);
void csort(struct tree *[],int );
void printtree(struct tree *);
struct tree *makenode(struct tree *,char []);
int main(int argc,char *argv[])
{
		FILE *fp;
		int nofw=0;
		char word[Maxline];
		struct tree *ptr=NULL,*root=NULL,*forsort[Maxline];
		fp=fopen(argv[2],"r");
		while(getword(word,fp)){
				if(strlen(word)<=1) continue;
				if(nofw==0){
						forsort[nofw++]=ptr=root=makenode(root,word); continue;
				}
				while(ptr!=NULL){
						if(strcmp(ptr->name,word)==0){
								ptr->count++; break;
						}
						else if(strcmp(ptr->name,word)>0){
								if(ptr->left==NULL){
										forsort[nofw++]=ptr->left=makenode(ptr->left,word); break;
								}
								ptr=ptr->left;
						}
						else if(strcmp(ptr->name,word)<0){	
								if(ptr->right==NULL){
										forsort[nofw++]=ptr->right=makenode(ptr->right,word); break;
								}
								ptr=ptr->right;
						}
				}	
				ptr=root;
		}
		if(argv[1][1]=='c'){
				csort(forsort,nofw);
				while(nofw--) printf("'%s'\t%d\n",forsort[nofw]->name,forsort[nofw]->count);
		}
		if(argv[1][1]=='n') printtree(root);
}
int getword(char *w,FILE *f)
{
		int i,c;
		while((c=fgetc(f))!=EOF){
				memset(w,'\0',Maxline);
				if(isalpha(c)){
						*w++=c;
						while((c=fgetc(f))=='.'||isalpha(c)) *w++=c;
						return 1;
				}
				if((c>>4)==14){
						*w++=c;
						for(i=0;i<2;i++){
								c=fgetc(f);
								if((c>>6)==2) *w++=c;
								else continue;
						}
						return 1;
				}
		}
		return 0;
}
void csort(struct tree *ptr[], int size)
{
		int i;
		for(i=0;i<size-1;i++){
				int j,max=i;
				struct tree *temp;
				for(j=i+1;j<size;j++){
						if(ptr[j]->count<ptr[max]->count) max=j;
				}
				temp=ptr[i];
				ptr[i]=ptr[max];
				ptr[max]=temp;
		}
}
void printtree(struct tree *ptr)
{
		if(ptr!=NULL){
				printtree(ptr->left);
				printf("'%s' %d\n",ptr->name,ptr->count);
				printtree(ptr->right);
		}
}
struct tree *makenode(struct tree *next,char name[])
{
		next=(struct tree *)malloc(sizeof(struct tree)*Maxline);
		strcpy(next->name,name); next->count=1; return next;
}
