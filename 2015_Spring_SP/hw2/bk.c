#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void usage() {
	printf("Type ./bk [-r] [source file/directory] [target file/directory] to backup files.\n");
}

void rbackup(char *src, char *tar) {
	
	int sd,td;
	sd = open(src,O_RDONLY | O_DIRECTORY);
	if( sd != -1 ) {
		if( (td = open(tar,O_RDONLY | O_DIRECTORY)) == -1 ) {
			struct stat st;
			if( fstat(sd,&st) == -1 ) {
				fprintf(stderr,"Can't get the infomation of directory.\n");
				return;
			}
			if( mkdir(tar,st.st_mode) == -1 ) {
				fprintf(stderr,"Can't build the directory.\n");
				return;
			}
		}
		DIR *dp;
		struct dirent *dd;
		dp = fdopendir(sd);
		while( (dd = readdir(dp)) != NULL ) {
			if( strcmp(dd->d_name,".") == 0 ) continue;
			if( strcmp(dd->d_name,"..") == 0 ) continue;
			char newsrc[1024],newtar[1024];
			memset(newsrc,'\0',1024);
			strcpy(newsrc,src);
			strcat(newsrc,"/");
			strcat(newsrc,dd->d_name);
			memset(newtar,'\0',1024);
			strcpy(newtar,tar);
			strcat(newtar,"/");
			strcat(newtar,dd->d_name);
			puts(newtar);
			rbackup(newsrc,newtar);
		}
		close(sd);
		close(td);
		return;
	}
	
	ssize_t len;
	char buf[4096];

	if( (len = readlink(src,buf,sizeof(buf)-1)) != -1 ) {
		buf[len] = '\0';
		if( symlink(buf,tar) == -1 ) {
			fprintf(stderr,"Can't build the symbolic link.\n");
			return;
		}
		return;
	}

	struct stat st;

	if( (sd = open(src,O_RDONLY)) == -1 ) {
		fprintf(stderr,"Can't copy the file to the target.\n");
		return;
	}
	if( fstat(sd,&st) == -1 ) {
		fprintf(stderr,"Can't get the infomation of directory.\n");
		return;
	}
	if( (td = open(tar,O_RDONLY | O_DIRECTORY)) != -1 ) {
		char name[1024];
		memset(name,'\0',1024);
		int a = strlen(src) - 1;
		int i,j=0;
		for(i=a; i>0; --i) {
			if(src[i] == '/') {
				break;
			}
		}
		if(i!=0)++i;
		while(i<=a){
			name[j++]=src[i++];
		}
		strcpy(tar,name);
		puts(name);
		if( (td = openat(td,tar,O_CREAT | O_WRONLY | O_TRUNC,st.st_mode)) == -1 ) {
			fprintf(stderr,"Can't copy the file to the target.\n");
			return;
		}
	}
	else if( (td = open(tar,O_CREAT | O_WRONLY | O_TRUNC,st.st_mode)) == -1 ) {
		fprintf(stderr,"Can't copy the file to the target.\n");
		return;
	}
	if( fchown(td,st.st_uid,st.st_gid) == -1 ) {
		fprintf(stderr,"Can't chown the file to the target.\n");
		return;
	}

	while( (len = read(sd,buf,sizeof(buf)-1)) > 0 ) {
		if( write(td,buf,(size_t)len) == -1 ) {
			fprintf(stderr,"Can't copy the file to the target.\n");
			return;
		}
	}

	close(sd);
	close(td);
}

int main(int argc, char **argv) {

	if( argc == 3 && (argv[1] == NULL || argv[2] == NULL) ) {
		usage();
		return;
	}
	
	char src[1024],tar[1024];
	strcpy(src,argv[1]);
	strcpy(tar,argv[2]);
	rbackup(src,tar);

	return 0;
}
