#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxline 1024
int main(int argc,char *argv[])
{
		FILE *fp;
		int operator[5]={1,0,0,0,0}; /* 0,1,2,3,4 as normal,-i,-n,-c,-v */
		char pattern[Maxline];
		int i=0,n=0;
		for(i=1;i<argc;i++){
				if(argv[i][0]=='-'){
						if(strlen(argv[i])>2){
								printf("There are some parameters undefined.\n");return 0;
						}
						switch(argv[i][1]){
								case 'i':operator[1]=1;break;
								case 'n':operator[2]=1;break;
								case 'c':operator[3]=1;break;
								case 'v':operator[4]=1;break;
								default:printf("There are some parameters undefined.\n");return 0;
						}
				}
				else if(n<2){
						if(n==0){
								strcpy(pattern,argv[i]);n++;
						}
						else{
								if(fp=fopen(argv[i],"r")) n++;
								else{
										printf("The file can't be found.\n");return 0;
								}
						}
				}
				else{
						printf("The number of parameter or the sort of parameters is wrong.\n");return 0;
				}
		}
		if(n==0){
				printf("The number of parameter is wrong.\n");return 0;
		}
		if(operator[2]||operator[3]) operator[0]=0; /* unnormal */
		if(operator[2]&&operator[3]){ /* -i -c conflict */
				printf("The parameters conflict.\n");return 0;
		}
		char word[Maxline]; /* store the line using */
		char *line[Maxline]; /* store lines for output */
		int nofline=0,nofmatched=0,match[Maxline];
		if(operator[1]){ /* -i */
				int k=0,l=strlen(pattern);
				char c;
				for(k=0;k<l;k++){
						c=tolower(pattern[k]);
						pattern[k]=c;
				}
		}
		while(fgets(word,Maxline,n==1 ? stdin:fp)!=NULL){
				line[nofline]=(char *)malloc(Maxline);
				strcpy(line[nofline],word);
				if(operator[1]){ /* -i */
						int k=0,l=strlen(word);
						char c;
						for(k=0;k<l;k++){
								c=tolower(word[k]);
								word[k]=c;
						}
				}
				if(strstr(word,pattern)>0){
						match[nofline]=1;
						nofmatched++;
				}
				else{
						match[nofline]=0;
				}
				nofline++;
		}
		if(operator[2]){ /* -n */
				int k=0;
				for(k=0;k<nofline;k++){
						if(match[k]==(operator[4]==1 ? 0:1)){
								printf("%d %s",k+1,line[k]);
						}
				}
		}
		if(operator[3]){ /* -c */
				printf("Number of matched lines:%d\n",operator[4]==1 ? nofline-nofmatched:nofmatched);
		}
		if(operator[0]){ /* normal */
				int k=0;
				for(k=0;k<nofline;k++){
						if(match[k]==(operator[4]==1 ? 0:1)){
								printf("%s",line[k]);
						}
				}
		}
		return 0;
}
