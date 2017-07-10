#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/types.h>

int SIG = 0;

void sigusrhandle() {
	return;
}

void siginthandle() {
	++SIG;
	kill(getpid()*-1, SIGUSR1);
}

int main(int argc, char **argv) {
	int i=0;
	pid_t pid, childs[4];
	for(i=0; i<4; ++i) {
		if( (pid = fork()) == 0 ) {
			signal(SIGINT, SIG_IGN);
			execv("xy.out", argv);
		} else {
			childs[i] = pid;
		}
	}

	signal(SIGUSR1, sigusrhandle);
	signal(SIGUSR2, sigusrhandle);

	while( SIG == 0 ) {
		signal(SIGINT, siginthandle);
	}

	sleep(1);

	long long in = 0, out = 0, a, b;
	FILE *tmp;

	tmp = fopen("4xy.tmp0","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp1","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp2","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp3","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	printf("\rans: %f\n", 2 * (double)in / (double)(in + out));

	for(i=0; i<4; ++i) {
		while( waitpid(childs[i],NULL,WNOHANG) == 0 ) {
			signal(SIGINT, siginthandle);
		}
	}

	tmp = fopen("4xy.tmp0","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp1","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp2","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	tmp = fopen("4xy.tmp3","r");
	fscanf(tmp, "%lld %lld", &a, &b);
	in += a;
	out += b;
	fclose(tmp);

	printf("\rans: %f\n", 2 * (double)in / (double)(in + out));
	exit(0);
}
