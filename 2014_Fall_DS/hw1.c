#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define Maxline 128
struct AddrBook{
			char Name[Maxline];
			char Birthday[Maxline];
			char PhoneNumber[Maxline];
			char Email[Maxline];
			struct AddrBook *next;
};
int getdata(char *,char *);
int fgetdata(char *,FILE *);
int dataAnalysis(char *);
void printList(struct AddrBook *);
void findList(struct AddrBook *,char *);
void sortList(struct AddrBook *[],int);
int addList(struct AddrBook *,char *);
int main(int argc,char *argv[])
{
		struct AddrBook *myAddrBook,*myhead;
		myAddrBook=(struct AddrBook *)malloc(sizeof(char)*Maxline*4+sizeof(struct AddrBook *));
		myhead=myAddrBook; //set root
		FILE *fp;
		char fileName[Maxline],actName,actContent[Maxline];
		memset(fileName,'\0',Maxline);
		memset(actContent,'\0',Maxline);
		if(argc>=3 && argc<=4){
				fp=fopen(argv[argc-1],"r");
				actName=argv[1][1];
				strcpy(actContent,argv[2]);
				strcpy(fileName,argv[argc-1]);
		}
		else{
				printf("Please follow the input format: \033[31m./ [-l -f -s -a] [Content] [File]\033[m\n"); return 0;
		}
		if(fp==NULL){
				printf("File not found.\n"); return 0;
		}
		int dataType,addrNum=0; // Name,Birthday,PhoneNumber,Email -> 0,1,2,3
		char buffer[Maxline];
		while(fgetdata(buffer,fp)){
				if(!strlen(buffer)) continue;
				dataType=dataAnalysis(buffer);
				switch(dataType){
						case 0:	if(addrNum==0){
										strcpy(myAddrBook->Name,buffer); addrNum++; break;
								}
								myAddrBook->next=(struct AddrBook *)malloc(sizeof(char)*Maxline*4+sizeof(struct AddrBook *));
								myAddrBook=myAddrBook->next;
								strcpy(myAddrBook->Name,buffer);
								addrNum++; break;
						case 1:	strcpy(myAddrBook->Birthday,buffer); break;
						case 2:	strcpy(myAddrBook->PhoneNumber,buffer);	break;
						case 3:	strcpy(myAddrBook->Email,buffer); break;
				}
		}
		fclose(fp);
		int i,type;
		struct AddrBook *addrSort[1024];
		switch(actName){
				case 'l': printList(myhead); break;
				case 'f': findList(myhead,actContent); break;
				case 's': myAddrBook=myhead;
						  for(i=0;i<addrNum;i++){
						  		addrSort[i]=(struct AddrBook *)malloc(sizeof(char)*Maxline*4+sizeof(struct AddrBook *));
						  		addrSort[i]=myAddrBook;
						  		myAddrBook=myAddrBook->next;
						  }
						  fp=fopen(fileName,"w");
						  type=(strcmp(actContent,"-d")==0 ? 1:0);
						  printf("%d\n",type);
						  sortList(addrSort,addrNum);
						  if(!type){
						  		for(i=0;i<addrNum;i++){
						  		  fprintf(fp,"%s\t%s\t%s\t%s\n",addrSort[i]->Name,addrSort[i]->Birthday,addrSort[i]->PhoneNumber,addrSort[i]->Email);
					  	  		}
						  }
					  	  else{
					  	  		for(i=addrNum-1;i>=0;i--){
						  		  fprintf(fp,"%s\t%s\t%s\t%s\n",addrSort[i]->Name,addrSort[i]->Birthday,addrSort[i]->PhoneNumber,addrSort[i]->Email);
					  	  		}
						  }
						  fclose(fp); break;
				case 'a': if(addList(myAddrBook,actContent)){
					  			fp=fopen(fileName,"w");
								while(myhead!=NULL){
										fprintf(fp,"%s\t%s\t%s\t%s\n",myhead->Name,myhead->Birthday,myhead->PhoneNumber,myhead->Email);
										myhead=myhead->next;
								}
								fclose(fp);
						  }
  						  break;
  				default:  printf("Please follow the input format: \033[31m./ [-l -f -s -a] [Content] [File]\033[m\n"); return 0;
		}
		return 0;
}
int getdata(char *buffer,char *cp){
		char c;
		memset(buffer,'\0',Maxline);
		while((c=*cp++)!='\t' && c!=' ' && c!='\n' && c!='\0' && c!=EOF) *buffer++=c;
		if(c=='\0') return 0; 
		return 1;
}
int fgetdata(char *buffer,FILE *fp){
		char c;
		memset(buffer,'\0',Maxline);
		while((c=fgetc(fp))!='\t' && c!=' ' && c!='\n' && c!='\0' && c!=EOF) *buffer++=c;
		if(c==EOF) return 0;
		return 1;
}
int dataAnalysis(char *buffer){
		int num=0;
		while(*buffer!='\t' && *buffer!=' ' && *buffer!='\n' && *buffer!='\0' && *buffer!=EOF){
				if(*buffer=='@') return 3;
				if(*buffer=='/') return 1;
				if(isdigit(*buffer)) num++;
				*buffer++;
		}
		if(num%10==0 && num!=0) return 2;
		return 0;
}
void printList(struct AddrBook *myhead){
		while(myhead!=NULL){
				printf("%-20s\t%-20s\t%-30s\t%-20s\n",myhead->Name,myhead->Birthday,myhead->PhoneNumber,myhead->Email);
				myhead=myhead->next;
		}
}
void findList(struct AddrBook *myhead,char *ptn){
		char buffer[Maxline];
		while(myhead!=NULL){
				memset(buffer,'\0',Maxline);
				strcat(buffer,myhead->Name);
				strcat(buffer,myhead->Birthday);
				strcat(buffer,myhead->PhoneNumber);
				strcat(buffer,myhead->Email);
				if(strstr(buffer,ptn)!=NULL) printf("%s\t%s\t%s\t%s\n",myhead->Name,myhead->Birthday,myhead->PhoneNumber,myhead->Email);
				myhead=myhead->next;
		}
}
void sortList(struct AddrBook *myhead[],int size){
		int i;
		for(i=0;i<size-1;i++){
				int c,j,k,max;
				struct AddrBook *temp;
				max=i;
				for(j=i+1;j<size;j++){
						c=(strlen(myhead[j]->Name)>strlen(myhead[max]->Name) ? strlen(myhead[j]->Name):strlen(myhead[max]->Name));
						for(k=0;k<c;k++){
								if(myhead[j]->Name[k]==myhead[max]->Name[k]) continue;
								if(myhead[j]->Name[k]<myhead[max]->Name[k]) max=j;
								break;
						}
				}
				temp=myhead[i];
				myhead[i]=myhead[max];
				myhead[max]=temp;
		}
}
int addList(struct AddrBook *myAddrBook,char *newRecord){
	int dataType,Datastate=1,Namestate=0,Phonestate=0;
	char buffer[Maxline];
	myAddrBook->next=(struct AddrBook *)malloc(sizeof(char)*Maxline*4+sizeof(struct AddrBook *)); myAddrBook=myAddrBook->next;
	while(Datastate){
			Datastate=getdata(buffer,newRecord);
			newRecord+=strlen(buffer)+Datastate;
			dataType=dataAnalysis(buffer);
			switch(dataType){
					case 0:	strcpy(myAddrBook->Name,buffer); Namestate=1; break;
					case 1:	strcpy(myAddrBook->Birthday,buffer); break;
					case 2:	strcpy(myAddrBook->PhoneNumber,buffer); Phonestate=1; break;
					case 3:	strcpy(myAddrBook->Email,buffer); break;
			}
	}
	if(Namestate && Phonestate) return 1;
	printf("It's required that the Name and Phone fields exist.\n"); return 0;
}
