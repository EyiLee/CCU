#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<stdbool.h>

char *getarg(char *f,char *opr){
		if(*f=='\0' || *f==EOF) return NULL;
		if(isblank(*f)){
				while(isblank(*f)) *f++;
		}
		if(isalnum(*f)){
				while(isalnum(*f)) *opr++=*f++;
				*opr='\0';
				return f;
		}
		if(ispunct(*f)){
				*opr++=*f++;
				*opr='\0';
				return f;
		}
		return NULL;
}

bool cmpopr(char now,char fnt){
		int c1,c2;
		switch(now){
				case '(': c1=-1; break;
				case '+': c1=0; break;
				case '-': c1=0; break;
				case '*': c1=1; break;
				case '/': c1=1; break;
		}
		switch(fnt){
				case '(': c2=-1; break;
				case '+': c2=0; break;
				case '-': c2=0; break;
				case '*': c2=1; break;
				case '/': c2=1; break;
		}
		if(c1 <= c2) return true;
		return false;
}

bool transpost(char *tmp,char *Postfix,bool Mode_t){
		int i=0,j=0,k=0;
		char opr[10],sta[100];
		memset(opr,'\0',10);
		memset(sta,'\0',100);
		while((tmp=getarg(tmp,opr))!=NULL){
				if(ispunct(*opr)){
						if(*opr=='('){
								sta[j++]=*opr;
								k++;
								continue;
						}
						if(*opr==')'){
								if(k==0) return false;
								while(sta[j-1]!='('){
										strncat(Postfix,&sta[j-1],1);
										strcat(Postfix," ");
										j--;
								}
								j--;
								k--;
								continue;
						}
						if(j > 0 && cmpopr(*opr,sta[j-1])){
								strncat(Postfix,&sta[j-1],1);
								strcat(Postfix," ");
								sta[j-1]=*opr;
								i--;
								while(j > 1 && cmpopr(sta[j-1],sta[j-2])){
										strncat(Postfix,&sta[j-2],1);
										strcat(Postfix," ");
										sta[j-2]=sta[j-1];
										j--;
								}
						}
						else{
								sta[j++]=*opr;
								i--;
						}
				}
				else if(isdigit(*opr)){
						strcat(Postfix,opr);
						strcat(Postfix," ");
						i++;
				}
				else if(isalpha(*opr) && Mode_t){
						strcat(Postfix,opr);
						strcat(Postfix," ");
						i++;
				}
				else{
						return false;
				}
		}
		if(i < 0 || i > 1){
				return false;
		}
		if(k!=0){
				return false;
		}
		for(;j > 0;j--){
				strncat(Postfix,&sta[j-1],1);
				strcat(Postfix," ");
		}
		return true;
}

bool calcpost(char *tmp,int *que){
		int i=0;
		char opr[10];
		memset(opr,'\0',10);
		while((tmp=getarg(tmp,opr))!=NULL){
				if(isdigit(*opr)){
						que[i++]=atoi(opr);
				}
				else if(ispunct(*opr) && i >= 2){
						switch (*opr){
								case '+':
										que[i-2]+=que[i-1];
										i--; break;
								case '-':
										que[i-2]-=que[i-1];
										i--; break;
								case '*':
										que[i-2]*=que[i-1];
										i--; break;
								case '/':
										if(que[i-1]==0) return false;
										que[i-2]/=que[i-1];
										i--; break;
								default:
										return false;
						}
				}
				else{
						return false;
				}
		}
		if(i!=1){
				return false;
		}
		return true;
}

int main(int argc,char **argv){
		bool Mode_e=false,Mode_t=false;
		char Formula[100],Postfix[100],opt,opr[10];
		memset(Formula,'\0',100);
		memset(Postfix,'\0',100);
		while((opt=getopt(argc,argv,"e:t:"))!=-1){
				switch(opt){
						case 'e':
								strcpy(Formula,optarg);
								Mode_e=true;
								break;
						case 't':
								strcpy(Formula,optarg);
								Mode_t=true;
								break;
				}
		}
		int que[100];
		char *tmp=Formula;

		/* trans to Postfix*/
		bool check;
		check = transpost(tmp,Postfix,Mode_t);
		if(check){
				if(Mode_t){
						puts(Postfix);
						return 0;
				}
				if(Mode_e){
						tmp=Postfix;
				}
		}
		if(!check){
				if(Mode_t){
						puts("format error");
						return 0;
				}
				if(Mode_e){
						tmp=Formula;
				}
		}

		/* calc the Formula */
		check = calcpost(tmp,&que[0]);
		if(check){
				printf("%d\n",que[0]);
				return 0;
		}
		if(!check){
				puts("format error");
				return 0;
		}

		return 0;
}
