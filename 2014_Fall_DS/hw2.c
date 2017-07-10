#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#define Map "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
void error(void);
void usage(void);
int compare(const void *, const void *);
int s_compare(const void *, const void *);
float bubbleTime(int [],int );
float selectTime(int [],int );
float insertTime(int [],int );
float quickTime(int [],int );
float mergeTime(int [],int );
float s_bubbleTime(char *[],int );
float s_selectTime(char *[],int );
float s_insertTime(char *[],int );
float s_quickTime(char *[],int );
float s_mergeTime(char *[],int );
float startTime,endTime,Duration;
int main(int argc,char *argv[]){
		int i,sLength=-1;
		bool sMode=false;
		if(argc==1 || argc>5){error(); usage(); return 0;}
		else if(strcmp(argv[1],"man")==0){usage(); return 0;}
		for(i=1;i<argc;i++){
				if(strcmp("-t",argv[i])==0){
						if(++i==argc){error(); usage(); return 0;}
						switch(argv[i][0]){
								case 's': sMode=true; break;
								case 'n': sMode=false; break;
								default: error(); usage(); return 0;
						}
						continue;
				}
				if(strcmp("-l",argv[i])==0){
						if(++i==argc){error(); usage(); return 0;}
						sLength=atoi(argv[i]);
						while(*argv[i]!='\0'){
								if(isdigit(*argv[i]++)) continue;
								error(); usage(); return 0;
						}
						continue;
				}
				error(); usage(); return 0;
		}
		if((!sMode && sLength!=-1)||(sMode && sLength==-1)){error(); usage(); return 0;}
		srand(time(NULL));
		int dataSize[]={10,100,1000,10000,100000,1000000,0};
		if(!sMode){
				int *dataCase;
				printf("¢z-------------------¢s-------------------¢s-------------------¢s-------------------¢s-------------------¢s-------------------¢{\n");
				printf("|%20s|%20s|%20s|%20s|%20s|%20s|\n","Datasize","Bubble","Select","Insert","Quick","Merge");
				printf("¢u-------------------¢q-------------------¢q-------------------¢q-------------------¢q-------------------¢q-------------------¢t\n");
				for(i=0;dataSize[i]!=0;i++){
						dataCase=(int *)malloc(sizeof(int)*dataSize[i]);
						int j;
						for(j=0;j<dataSize[i];j++) dataCase[j]=rand();
						printf("|%20d",dataSize[i]); fflush(stdout);
						printf("|%20f",bubbleTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",selectTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",insertTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",quickTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f|\n",mergeTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
				}
				printf("¢|-------------------¢r-------------------¢r-------------------¢r-------------------¢r-------------------¢r-------------------¢}\n");
		}
		if(sMode){
				char **dataCase;						
				printf("¢z-------------------¢s-------------------¢s-------------------¢s-------------------¢s-------------------¢s-------------------¢{\n");
				printf("|%20s|%20s|%20s|%20s|%20s|%20s|\n","Datasize","Bubble","Select","Insert","Quick","Merge");
				printf("¢u-------------------¢q-------------------¢q-------------------¢q-------------------¢q-------------------¢q-------------------¢t\n");
				for(i=0;dataSize[i]!=0;i++){
						dataCase=(char **)malloc(sizeof(char *)*dataSize[i]);
						int j;
						for(j=0;j<dataSize[i];j++){
								dataCase[j]=(char *)malloc(sizeof(char)*sLength+1);
								int k;
								for(k=0;k<sLength;k++){
										dataCase[j][k]=Map[rand()%61];
								}
								dataCase[j][k]='\0';
						}
						printf("|%20d",dataSize[i]); fflush(stdout);
						printf("|%20f",s_bubbleTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",s_selectTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",s_insertTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f",s_quickTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
						printf("|%20f|\n",s_mergeTime(dataCase,dataSize[i])/CLOCKS_PER_SEC); fflush(stdout);
				}
				printf("¢|-------------------¢r-------------------¢r-------------------¢r-------------------¢r-------------------¢r-------------------¢}\n");
		}
		return 0;
}
void error(void){
		printf("\033[33mInput Error !\033[m\n"); 
}
void usage(void){
		printf("\nUsage:\n");
		printf("Name:\tsortcomp\n");
		printf("Description:\t\033[31msortcomp -l length -t [s|n]\033[m\n");
		printf("\n\033[32msortcomp -t n\033[m means your data type is number.\n");
		printf("\033[32msortcomp -l n -t s\033[m means your data type is string, and length is n.\n\n");
}
int compare(const void * a, const void * b){
		  return ( *(int*)a - *(int*)b );
}

int s_compare(const void * a, const void * b){
		  return ( strcmp(*(char **)a,*(char **)b) );
}
float bubbleTime(int Case[],int size){
		if(size>100000) return 0;
		int i,j,temp;
		startTime=clock();
		for(i=0;i<size;i++) for(j=0;j<size-1-i;j++)
				if(Case[j]>Case[j+1]){
						temp=Case[j];
						Case[j]=Case[j+1];
						Case[j+1]=temp;
				}
		endTime=clock();
		return endTime-startTime;
}
float selectTime(int Case[],int size){
		if(size>100000) return 0;
		int i,j,max,temp;
		startTime=clock();
		for(i=0;i<size;i++){
				max=i;
				for(j=i+1;j<size-i;j++){
						if(Case[j]>Case[max]) max=j;
				}
				temp=Case[i];
				Case[i]=Case[max];
				Case[max]=temp;
		}
		endTime=clock();
		return endTime-startTime;
}		
float insertTime(int Case[],int size){
		if(size>100000) return 0;
		int i,j,temp;
		startTime=clock();
		for (i=1;i<size;i++){
				temp=Case[i];
				for(j=i-1;j>=0 && Case[j]>temp;j--){
						Case[j+1]=Case[j];
				}
				Case[j+1]=temp;
		}
		endTime=clock();
		return endTime-startTime;
}
float quickTime(int Case[],int size){
		startTime=clock();
		qsort(Case,size,sizeof(int),compare);
		endTime=clock();
		return endTime-startTime;
}
float mergeTime(int Case[],int size){
		startTime=clock();
		mergesort(Case,size,sizeof(int),compare);
		endTime=clock();
		return endTime-startTime;
}
float s_bubbleTime(char *Case[],int size){
		if(size>100000) return 0;
		int i,j;
		char *temp;
		startTime=clock();
		for(i=0;i<size;i++) for(j=0;j<size-1-i;j++)
				if(strcmp(Case[j],Case[j+1])>0){
						temp=Case[j];
						Case[j]=Case[j+1];
						Case[j+1]=temp;
				}
		endTime=clock();
		return endTime-startTime;
}
float s_selectTime(char *Case[],int size){
		if(size>100000) return 0;
		int i,j,max;
		char *temp;
		startTime=clock();
		for(i=0;i<size;i++){
				max=i;
				for(j=i+1;j<size-i;j++){
						if(strcmp(Case[j],Case[max])>0) max=j;
				}
				temp=Case[i];
				Case[i]=Case[max];
				Case[max]=temp;
		}
		endTime=clock();
		return endTime-startTime;
}		
float s_insertTime(char *Case[],int size){
		if(size>100000) return 0;
		int i,j;
		char *temp;
		startTime=clock();
		for (i=1;i<size;i++){
				temp=Case[i];
				for(j=i-1;j>=0 && strcmp(Case[j],temp)>0;j--){
						Case[j+1]=Case[j];
				}
				Case[j+1]=temp;
		}
		endTime=clock();
		return endTime-startTime;
}
float s_quickTime(char *Case[],int size){
		startTime=clock();
		qsort(Case,size,sizeof(char *),s_compare);
		endTime=clock();
		return endTime-startTime;
}
float s_mergeTime(char *Case[],int size){
		startTime=clock();
		mergesort(Case,size,sizeof(char *),compare);
		endTime=clock();
		return endTime-startTime;
}
