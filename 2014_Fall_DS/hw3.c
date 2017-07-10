#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<dirent.h>
#include<sys/types.h>
#include<time.h>
#define Maxline 1024

//finished i,v,n,l,h,w,x,c,m,b,R
struct options{
	bool oi;
	bool ov;
	bool on;
	bool ol;
	bool oh;
	bool ow;
	bool ox;
	bool oc;
	bool om;
	bool ob;
	bool op;
	bool oA;
	bool oB;
	bool oR;
	int NUM_m;
	int NUM_A;
	int NUM_B;
};

struct context{
	char **buffer;
	char file[Maxline];
	int *prefix;
	int *length;
	int pos;
};

int usage();
void trans(char *);
void simplegrep(char *,struct options ,char *,char *(const char *,const char *));
bool s_isdigit(char *);
bool findpat(char *,struct options ,char *,int *,char *(const char *,const char *));
void printA(struct context *,int ,int ,struct options);
char *mystrstr(const char *,const char *);

int main(int argc,char **argv){
	//initialize cmd
	struct options cmd;
	cmd.oi=false;
	cmd.ov=false;
	cmd.on=false;
	cmd.ol=false;
	cmd.oh=false;
	cmd.ow=false;
	cmd.ox=false;
	cmd.oc=false;
	cmd.om=false;
	cmd.ob=false;
	cmd.op=false;
	cmd.oA=false;
	cmd.oB=false;
	cmd.oR=false;
	
	int i=1;
	char pattern[Maxline];
	
	//compute parameters
	if(argc<4) return usage();
	for(i=1;i<argc;i++){
		if(argv[i][0]=='-'){
			switch (argv[i][1]){
				case 'i':
					cmd.oi=true; break;
				case 'v':
					cmd.ov=true; break;
				case 'n':
					cmd.on=true; break;
				case 'l':
					cmd.ol=true; break;
				case 'h':
					cmd.oh=true; break;
				case 'w':
					cmd.ow=true; break;
				case 'x':
					cmd.ox=true; break;
				case 'c':
					cmd.oc=true; break;
				case 'm':
					cmd.om=true;
					if(!s_isdigit(argv[i+1]))
						return usage();
					cmd.NUM_m=atoi(argv[++i]);
					break; 
				case 'b':
					cmd.ob=true; break;
				case 'p':
					cmd.op=true; break;
				case 'A':
					cmd.oA=true;
					if(!s_isdigit(argv[i+1]))
						return usage();
					cmd.NUM_A=atoi(argv[++i]);
					cmd.NUM_A++;
					break;
				case 'B':
					cmd.oB=true;
					if(!s_isdigit(argv[i+1]))
						return usage();
					cmd.NUM_B=atoi(argv[++i]);
					cmd.NUM_B;
					break;
				case 'R':
					cmd.oR=true; break;
				default:
					return usage();
			}
		}
		else if(i==1)
			return usage();
		else{
			strcpy(pattern,argv[i++]);
			break;
		}
	}
	if(cmd.oi)
		trans(pattern);
	float start,end;
	float mytime=0,time=0;
	for(;i<argc;i++){
		if(cmd.op){
			start=clock();
			simplegrep(argv[i],cmd,pattern,strstr);
			end=clock();
			time+=(end-start);
		}
		start=clock();
		simplegrep(argv[i],cmd,pattern,mystrstr);
		end=clock();
		mytime+=(end-start);
	}
	if(cmd.op){
			printf("strstr: %f sec\n",time/CLOCKS_PER_SEC);
			printf("mystrstr: %f sec\n",mytime/CLOCKS_PER_SEC);
	}
	return 0;
}

//print the manual
int usage(){
	printf("\n\033[31mInput Error!\033[m\n");
	printf("Usage:\nName:\tsimplegrep\nDescription:\tsimplegrep [option] [pattern] [file...]\n");
	printf("Option:\n");
	printf("\033[32m-i\033[m\tcase insensitive\n");
	printf("\033[32m-v\033[m\tinvert the sense of matching, to select non-matching lines\n");
	printf("\033[32m-n\033[m\toutput prefixed by line number\n");
	printf("\033[32m-l\033[m\toutput those filenames containing matches\n");
	printf("\033[32m-h\033[m\tsuppress the prefixing of filenames on output when multiple files are searched\n");
	printf("\033[32m-w\033[m\toutput those lines containing matches	that form whole words\n");
	printf("\033[32m-x\033[m\toutput those matches that exactly match the whole line\n");
	printf("\033[32m-c\033[m\toutput number of matches for every file\n");
	printf("\033[32m-m NUM\033[m\tstop reading a file after NUM matching lines.\n");
	printf("\033[32m-b\033[m\toutput the byte offset of the first character of matching lines\n");
	printf("\033[32m-p\033[m\tcompare the execute time between strstr and mystrstr\n");
	printf("\033[32m-A NUM\033[m\toutput NUM lines above the matching line\n");
	printf("\033[32m-B NUM\033[m\toutput NUM lines below the matching line\n");
	printf("\033[32m-R\033[m\tread all files under each directory, recursively\n\n");
	return 0;
}

//translate string to lower
void trans(char *line){
	while(*line!='\0'){
		*line=tolower(*line);
		line++;
	}
}

//recursively find files and output results
void simplegrep(char *file,struct options cmd, char *pattern,char *mystr(const char *,const char *)){
	struct dirent *d_file;
	FILE *fp;
	fp=fopen(file,"r");
	if(fp==NULL)
		printf("'\033[32m%s\033[m' \033[31mFile Not Found!\033[m\n",file);
	if(cmd.oR){
		DIR *dp;
		dp=opendir(file);
		if(dp){
			while((d_file=readdir(dp))!=NULL){
				if(strcmp(d_file->d_name,".")==0)
					continue;
				if(strcmp(d_file->d_name,"..")==0)
					continue;
				char newfile[Maxline];
				memset(newfile,'\0',Maxline);
				strcpy(newfile,file);
				strcat(newfile,"/");
				strcat(newfile,d_file->d_name);
				simplegrep(newfile,cmd,pattern,mystr);
			}
		}
		if(dp)
			closedir(dp);
	}
	int prefix=0,match=0,length=0,below=0,pos;
	bool state=false;
	char buffer[Maxline],buffer2[Maxline],**bufferA;
	struct context contextA,contextB;
	if(cmd.oA){
		contextA.buffer=(char **)malloc(sizeof(char *)*cmd.NUM_A);
		contextA.prefix=(int *)malloc(sizeof(int)*cmd.NUM_A);
		contextA.length=(int *)malloc(sizeof(int)*cmd.NUM_A);
		int i;
		for(i=0;i<cmd.NUM_A;i++)
			contextA.buffer[i]=(char *)malloc(sizeof(char)*Maxline);
	}
	if(fp){
		strcpy(contextA.file,file);
		while(fgets(buffer,Maxline,fp)){
			int len=strlen(buffer);
			if(buffer[len-1]=='\n')
				buffer[len-1]='\0';
			if(cmd.oA){
				strcpy(contextA.buffer[prefix%cmd.NUM_A],buffer);
				contextA.prefix[prefix%cmd.NUM_A]=prefix;
				contextA.length[prefix%cmd.NUM_A]=length;
			}
			if(cmd.oi){
				strcpy(buffer2,buffer);
				trans(buffer);
			}
			state=findpat(buffer,cmd,pattern,&pos,mystr);
			if(state==cmd.ov && cmd.oB){
				if(below){
					if(cmd.oi)
						strcpy(buffer,buffer2);
					if(cmd.oA)
						printA(&contextA,cmd.NUM_A,prefix,cmd);
					if(!cmd.oh)
						printf("%s:",file);
					if(cmd.on)
						printf("%d:",prefix);
					if(cmd.ob)
						printf("%d:",length+pos);
					printf("%s\n",buffer);
					below--;
				}
			}
			if(state!=cmd.ov && cmd.ol)
				break;
			if(state!=cmd.ov && !(cmd.ol))
				match++;
			if(state!=cmd.ov && !(cmd.ol) && !(cmd.oc)){
				if(cmd.oB)
					below=cmd.NUM_B;
				if(cmd.om)
					if(match>cmd.NUM_m)
						break;
				if(cmd.oi)
					strcpy(buffer,buffer2);
				if(cmd.oA)
					printA(&contextA,cmd.NUM_A,prefix,cmd);
				if(!cmd.oh)
					printf("%s:",file);
				if(cmd.on)
					printf("%d:",prefix);
				if(cmd.ob)
					printf("%d:",length+pos);
				printf("%s\n",buffer);
			}
			length+=len;
			prefix++;
			memset(buffer,'\0',Maxline);
		}
	}
	if(state!=cmd.ov && cmd.ol)
		printf("%s\n",file);
	else if(cmd.oc)
		printf("%s:%d\n",file,match);
	if(fp)
		fclose(fp);
}

//check for digits in the string
bool s_isdigit(char *line){
	while(*line!='\0')
		if(!isdigit(*line++))
			return false;
	return true;
}

//find matching lines
bool findpat(char *buffer,struct options cmd,char *pattern,int *pos,char *mystr(const char *,const char *)){
	char *tmp;
	if(cmd.ow){
		char c;
		while((tmp=mystr(buffer,pattern))!=NULL){
			bool m=true,n=false;
			*pos=tmp-buffer;
			if(tmp-buffer){
				c=*(tmp-1);
				if(isalpha(c))
					m=false;
			}
			c=*(tmp+strlen(pattern));
			if(!isalpha(c))
				n=true;
			if(n && m) return true;
			buffer=tmp+strlen(pattern);
		}
		return false;
	}
	if(cmd.ox){
		if(strcmp(buffer,pattern)==0){
			*pos=0;
			return true;
		}
		return false;
	}
	if((tmp=mystr(buffer,pattern))!=NULL){
		*pos=tmp-buffer;
		return true;
	}
	return false;
}

void printA(struct context *context,int n,int prefix,struct options cmd){
		int j;
		j=0;
		if(prefix-context->pos<=n) j=n-prefix+context->pos;
		for(;j<n-1;j++){
				if(!(context->buffer[(prefix+j+1)%n])) continue;
				if(!cmd.oh)
					printf("%s:",context->file);
				if(cmd.on)
					printf("%d:",context->prefix[(prefix+j+1)%n]);
				if(cmd.ob)
					printf("%d:",context->length[(prefix+j+1)%n]);
				printf("%s\n",context->buffer[(prefix+j+1)%n]);
		}
		context->pos=prefix;
}

char *mystrstr(const char *line,const char *pattern){
	int i;
	int shift[256];
	for(i=0;i<256;i++)
		shift[i]=-1;
	const char *ptr=pattern;
	int head=0,tail=strlen(pattern),len=strlen(line);
	while(*ptr!='\0' && *ptr!=EOF){
		i=*ptr++;
		shift[i]=tail-head-1;
		head++;
	}
	for(i=0;i<len;){
		if(shift[(unsigned char)line[i+tail-1]]==0){
			if(strncmp(&line[i],pattern,tail)==0){
				return (char *)&line[i];
			}
			i++;
		}
		else if(shift[(unsigned char)line[i+tail-1]]==-1)
			i+=tail;
		else
			i+=shift[(unsigned char)line[i+tail-1]];
	}
	return NULL;
}
