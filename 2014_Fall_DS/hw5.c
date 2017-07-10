#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<stdbool.h>

struct txt{
		int LineNum;
		char Line[256];
		struct txt *prev;
		struct txt *next;
};

struct txt *gettxt(FILE *tp,struct txt *fp,int *ttl){
		char temp[256];
		while(fgets(temp,256,tp)!=NULL){
				strcpy(fp->Line,temp);
				fp->next=(struct txt *)malloc(sizeof(struct txt));
				fp->next->prev=fp;
				fp=fp->next;
				*ttl+=1;
		}
		fp=fp->prev;
		free(fp->next);
		fp->next=NULL;
		return fp;
}

char getarg(char *oprs){
		printf("usr >");
		char opt;
		char *temp;
		temp=(char *)malloc(sizeof(char)*256);
		fgets(temp,256,stdin);
		opt=*temp++;
		strcpy(oprs,temp);
		free(temp);
		return opt;
}

char *getpart(char *oprs,char div,char *temp){
		if(*oprs=='\0' || *oprs==EOF) return NULL;
		memset(temp,'\0',256);
		while(isspace(*oprs) || *oprs==div){
				*oprs++;
		}
		while(!isspace(*oprs) && *oprs!=div && *oprs!='\0'){
				*temp++=*oprs++;
		}
		*temp='\0';
		return oprs;
}

char *getinclude(char *oprs,char div,char *temp){
		if(*oprs=='\0' || *oprs==EOF) return NULL;
		memset(temp,'\0',256);
		while(*oprs!=div){
				*oprs++;
		}
		*oprs++;
		while(*oprs!=div){
				*temp++=*oprs++;
		}
		*temp++='\n';
		*temp='\0';
		return oprs;
}

void runl(struct txt *fp,int fm,int to){
		int i,j;
		for(i=1;i<fm;i++){
				fp=fp->next;
		}
		for(i=1,j=to;j>=10;i++){
				j%=10;
		}
		for(j=fm;j<=to;j++){
				printf("\033[33m%*d\033[m %s",i,j,fp->Line);
				if(fp->next==NULL) break;
				fp=fp->next;
		}
}

struct txt *rund(struct txt *fp,int fm,int to){
		int i;
		struct txt *head,*prev,*next,*tmp;
		head=fp;
		for(i=1;i<fm;i++){
				fp=fp->next;
		}
		prev=fp->prev;
		next=fp;
		printf("deleted:\n");
		for(i=fm;i<=to;i++){
				printf("%s",fp->Line);
				tmp=fp->next;
				fp->next=NULL;
				free(fp);
				fp=tmp;
				if(fp==NULL) break;
		}
		if(fp==NULL){
				next=(struct txt *)malloc(sizeof(struct txt));
				next->next=NULL;
				strcpy(next->Line,"\n\0");
				return next;
		}
		else{
				*next=*fp;
				if(prev!=NULL) prev->next=next;
				next->prev=prev;
				return fp;
		}
}

void runs(struct txt *fp,char *pat1,char *pat2){
		int i,l=strlen(pat1);
		char *tmp,*cat;
		cat=(char *)malloc(sizeof(char)*256);
		tmp=fp->Line;
		while((tmp=strstr(fp->Line,pat1))!=NULL){
				strcpy(cat,tmp+l);
				strcpy(tmp,pat2);
				strcat(tmp,cat);
				tmp+=l;
		}
		free(cat);
}

void runR(struct txt *fp,FILE *tp,int *ttl){
		struct txt *fh,*fl;
		fh=(struct txt *)malloc(sizeof(struct txt));
		fl=gettxt(tp,fh,ttl);
		fh->prev=fp;
		fl->next=fp->next;
		fp->next->prev=fl;
		fp->next=fh;
}

struct txt *rung(struct txt *fp,int cur){
		int i;
		for(i=1;i<cur;i++){
				fp=fp->next;
		}
		return fp;
}

int main(int argc,char **argv){

		FILE *tp;
		tp=fopen(argv[1],"r");
		if(!tp){
				puts("Error: File Not Found.");
				return 0;
		}
		
		int ttl=0,cur=1;																	// set linked list
		struct txt *fp,*fh,*fl;
		fh=(struct txt *)malloc(sizeof(struct txt));
		fl=gettxt(tp,fh,&ttl);
		fp=fh;
		if(tp) fclose(tp);

		int fm,to,num,cnt;																	// for l,d
		char *tmp,*reset;
		tmp=(char *)malloc(sizeof(char)*256);

		struct txt *ftmp;																	// for i

		char *pat1,*pat2,*pat3;																// for s
		pat1=(char *)malloc(sizeof(char)*256);
		pat2=(char *)malloc(sizeof(char)*256);
		pat3=(char *)malloc(sizeof(char)*2);

		char opt,*oprs;
		oprs=(char *)malloc(sizeof(char)*256);
		while((opt=getarg(oprs))!='\0'){
				switch(opt){
						case 'l':{
								num=0,cnt=0,fm=0,to=0;
								reset=oprs;
								while((oprs=getpart(oprs,',',tmp))!=NULL){ 					// l j,k mode
										if(tmp[0]=='.') num=cur;
										else if(tmp[0]=='$') num=ttl;
										else num=atoi(&tmp[0]);
										if(tmp[1]=='+') num+=atoi(&tmp[2]);
										else if(tmp[1]=='-') num-=atoi(&tmp[2]);
										if(fm==0 && to==0) fm=num;
										else if(fm!=0 && to==0) to=num;
										else break;
										cnt++;
								}
								oprs=reset;
								if(fm==0 && to==0){ 										// l only mode
										fm=cur;	to=cur;
								}
								else if(fm!=0 && to==0){									// l k mode
										to=cur+fm-1; fm=cur;
								}
								if(fm<1) fm=1;
								if(fm>ttl) fm=ttl;
								if(to<1) to=1;
								if(to>ttl) to=ttl;
								if(fm>to){
										num=fm; fm=to; to=num;
								}
								runl(fh,fm,to);
						} break;

						case 'i':{
								getinclude(oprs,'"',tmp); 									// tmp auto append '\n'
								ftmp=(struct txt *)malloc(sizeof(struct txt));
								strcpy(ftmp->Line,tmp);
								if(ttl==1){
										*fp=*ftmp;
										fh=fp;
										fp->next=NULL;
								}
								else{
										if(fp->next!=NULL){
												ftmp->next=fp->next;
												fp->next->prev=ftmp;
										}
										ftmp->prev=fp;
										fp->next=ftmp;
								}
								ttl++;
								printf("Accept: inserted below current line.\n");
						} break;

						case 'd':{
								num=0,cnt=0,fm=0,to=0;
								reset=oprs;
								while((oprs=getpart(oprs,',',tmp))!=NULL){ 					// d j,k mode
										if(tmp[0]=='.') num=cur;
										else if(tmp[0]=='$') num=ttl;
										else num=atoi(&tmp[0]);
										if(tmp[1]=='+') num+=atoi(&tmp[2]);
										else if(tmp[1]=='-') num-=atoi(&tmp[2]);
										if(fm==0 && to==0) fm=num;
										else if(fm!=0 && to==0) to=num;
										else break;
										cnt++;	
								}
								oprs=reset;
								if(fm==0 && to==0){ 										// d only mode
										fm=cur;	to=cur;
								}
								else if(fm!=0 && to==0){ 												// d k mode
										to=cur+fm-1; fm=cur;
								}
								if(fm<1) fm=1;
								if(fm>ttl) fm=ttl;
								if(to<1) to=1;
								if(to>ttl) to=ttl;
								if(fm>to){
										num=fm; fm=to; to=num;
								}
								fh=rund(fh,fm,to);
								ttl-=(to-fm+1);
								if(ttl<1) ttl=1;
								fp=rung(fh,cur);
						} break;

						case 'p':{
								if(fp->prev==NULL){
										puts("Error: No more previous line.");
										break;
								}
								printf("%s",fp->prev->Line);
						} break;

						case 'n':{
								if(fp->next==NULL){
										puts("Error: No more next line.");
										break;
								}
								printf("%s",fp->next->Line);
						} break;

						case 's':{
								cnt=0;
								reset=oprs;
								while((oprs=getpart(oprs,'/',tmp))!=NULL){
										if(cnt==0) strcpy(pat1,tmp);
										if(cnt==1) strcpy(pat2,tmp);
										if(cnt==2) strcpy(pat3,tmp);
										if(cnt>2) break;
										cnt++;
								}
								oprs=reset;
								if(*pat3=='g'){
										fp=fh;
										while(fp!=NULL){
												runs(fp,pat1,pat2);
												fp=fp->next;
										}
										fp=rung(fh,cur);
								}
								else runs(fp,pat1,pat2);
								fp=rung(fh,cur);
						} break;

						case 'R':{
								getpart(oprs,',',tmp);
								tp=fopen(tmp,"r");
								if(!tp){
										puts("Error: File Not Found.");
										return 0;
								}
								runR(fp,tp,&ttl);
								fclose(tp);
						} break;

						case 'w':{
								if(*oprs=='!'){
										strcpy(tmp,argv[1]);
								}
								else{
										getpart(oprs,',',tmp);
								}
								if(tmp[0]=='\n' || tmp[0]=='\0'){
										printf("Unvaliable file name.\n");
										break;
								}
								fp=fh;
								tp=fopen(tmp,"w");
								while(fp!=NULL){
										fprintf(tp,"%s",fp->Line);
										fp=fp->next;
								}
								if(tp) fclose(tp);
								fp=rung(fh,cur);
								printf("File: \"%s\" written.\n",tmp);
						} break;

						case 'q':{
								puts("Good Bye!");
								puts("(exit program)");
								return 0;
						}
						case 'f':{
								getinclude(oprs,'"',tmp);
								num=0;
								while(fp!=NULL){
										if(strstr(fp->Line,tmp)){
												printf("\033[33m%d\033[m %s",cur+num,fp->Line);
												break;
										}
										fp=fp->next;
										num++;
								}
								fp=rung(fh,cur);
						} break;

						case 'g':{
								getpart(oprs,',',tmp);
								if(tmp[0]=='$') cur=ttl;
								else cur=atoi(tmp);
								fp=rung(fh,cur);
						} break;

						case 'u':{
								puts("I can't do it.");
						} break;
						
						case ' ':
						case '\n':
						case '\t':{
						} break;

						default:{
								puts("Error: Undefined operator.");
						} break;
				}
		}
}
