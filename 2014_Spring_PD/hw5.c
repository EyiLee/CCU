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
int EorR();
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
		int state=1;
		while(state){
				printf("Main menu\n");
				printf("a)list\n");
				printf("b)find (coming soon...\n");
				printf("c)insert (coming soon...\n");
				printf("d)delete (coming soon...\n");
				printf("e)exit\n");
				printf("Please input command...\nCommand->");
				fscanf(stdin,"%s",&line);
				switch(line[0]){
						case 'a': list(head); state=EorR(); break;
						case 'b': /*find();*/ state=EorR(); break;
						case 'c': /*insert();*/ state=EorR(); break;
						case 'd': /*delete();*/ state=EorR(); break;
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
}
void list(struct text *ptr)
{
		while(ptr->next!=NULL){
				printf("Name:%s\tPhone:%s\tAddr:%s\tAge:%s\n",ptr->name,ptr->phone,ptr->addr,ptr->age);
				ptr=ptr->next;
		}
}
int EorR()
{
		int state;
		char ER[1];
		while(1){
				printf("Exit or return to main menu?(E/R)\n");
				fscanf(stdin,"%s",&ER);
				switch(ER[0]){
						case 'E': state=0; return 0;
						case 'R': state=1; return 1;
						default: printf("\033[0;32;31mPlease check your command whether it is available...\033[m\n"); break;
				}
		}
		return state;
}
