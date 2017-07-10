#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxline 1024
#define NONE "\033[m"
#define RED "\033[0;32;31m"
struct text{
		char name[Maxline];
		char phone[Maxline];
		char addr[Maxline];
		char age[Maxline];
		struct text *next;
};
void taketext(char *,char *,char []);
void list(struct text *);
void find(struct text *);
void insert(struct text *);
void delete(struct text *);
void update(struct text *,char []);
void EorR(int *);
int stricmp(char *,char *);
int main(int argc,char *argv[])
{
		FILE *fop;
		fop=fopen(argv[1],"r");
		struct text *book,*head;
		book=(struct text *)malloc(sizeof(struct text)*Maxline);head=book;
		char line[Maxline];
		while(fgets(line,Maxline,fop)!=NULL){
				taketext(line,book->name,"Name:");
				taketext(line,book->phone,"Phone:");
				taketext(line,book->addr,"Addr:");
				taketext(line,book->age,"Age:");
				book->next=(struct text *)malloc(sizeof(struct text)*Maxline);
				book=book->next;
		}
		fclose(fop);
		int state=1;
		while(state){
				printf("Main menu\n");
				printf("a)list\n");
				printf("b)find\n");
				printf("c)insert\n");
				printf("d)delete\n");
				printf("e)exit\n");
				printf("Please input command...\nCommand->");
				fscanf(stdin,"%s",&line);
				switch(line[0]){
						case 'a': list(head); EorR(&state); break;
						case 'b': find(head); EorR(&state); break;
						case 'c': insert(book); book=book->next; update(head,argv[1]); EorR(&state); break;
						case 'd': delete(head); update(head,argv[1]); EorR(&state); break;
						case 'e': state=0; break;
						default: printf("\033[0;32;31mPlease check your command whether it is available...\033[m\n");
				}
		}
		return 0;
}
void taketext(char *line,char *key,char pat[])
{
		line=strstr(line,pat);
		line+=strlen(pat);
		while(*line!='\t'&&*line!='\n'&&*line!=' '&&*line!=EOF){
				*key++=*line++;
		}
		*key='\0';
}
void list(struct text *ptr)
{
		while(ptr->next!=NULL){
				printf("Name:%s\tPhone:%s\tAddr:%s\tAge:%s\n",ptr->name,ptr->phone,ptr->addr,ptr->age);
				ptr=ptr->next;
		}
}
void find(struct text *ptr)
{
		char pat[Maxline];
		printf("Please enter the keywords which you want to find.\n");
		fscanf(stdin,"%s",&pat);
		while(ptr->next!=NULL){
				if(strcmp(pat,ptr->name)==0||strcmp(pat,ptr->phone)==0||strcmp(pat,ptr->addr)==0||strcmp(pat,ptr->age)==0)
						printf("Name:%s\tPhone:%s\tAddr:%s\tAge:%s\n",ptr->name,ptr->phone,ptr->addr,ptr->age);
				ptr=ptr->next;
		}
}
void insert(struct text *ptr)
{
		char pat[Maxline];
		printf("Please enter the Name.\n");fscanf(stdin,"%s",&pat);strcpy(ptr->name,pat);
		printf("Please enter the Phone.\n");fscanf(stdin,"%s",&pat);strcpy(ptr->phone,pat);
		printf("Please enter the Addr.\n");fscanf(stdin,"%s",&pat);strcpy(ptr->addr,pat);
		printf("Please enter the Age.\n");fscanf(stdin,"%s",&pat);strcpy(ptr->age,pat);
		ptr->next=(struct text *)malloc(sizeof(struct text)*Maxline);
}
void delete(struct text *ptr)
{
		char pat[Maxline];
		struct text *front=NULL;
		printf("Please enter the keywords which you want to delete.\n");
		fscanf(stdin,"%s",&pat);
		while(stricmp(pat,ptr->name)!=0){
				front=ptr;
				ptr=ptr->next;
		}
		if(ptr->next==NULL){
				free(ptr);
		}
		else if(front==NULL){
			front=ptr->next;
			*ptr=*ptr->next;
			free(front);
		}
		else{
				front->next=ptr->next;
				free(ptr);
		}
		
}
void update(struct text *ptr,char argv[])
{
		FILE *fop;
		fop=fopen(argv,"w");
		while(ptr->next!=NULL){
				fprintf(fop,"Name:%s\tPhone:%s\tAddr:%s\tAge:%s\n",ptr->name,ptr->phone,ptr->addr,ptr->age);
				ptr=ptr->next;
		}
		fclose(fop);
}
void EorR(int *state)
{
		int open=1;
		char ER[1];
		while(open){
				printf("Exit or return to main menu?(E/R)\n");
				fscanf(stdin,"%s",&ER);
				switch(ER[0]){
						case 'E':  *state=0; open=0; break;
						case 'R':  *state=1; open=0; break;
						default: printf("\033[0;32;31mPlease check your command whether it is available...\033[m\n"); open=1; break;
				}
		}
}
int stricmp(char *s,char *t){
		while(*s-*t==0||*s-*t=='A'-'a'||*s-*t=='a'-'A'){
				*s++;*t++;
				if(*s=='\0') return 0;
		}
		return 1;
}
