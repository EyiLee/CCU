#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<sys/types.h>

int SIG = 0;

void sigusr1() {
	++SIG;
}

void sigusr2() {
	SIG = 3;
}

int main() {
	signal(SIGUSR1,sigusr1);
	signal(SIGUSR2,sigusr2);

	double x, y;
	long long in = 0, out = 0;
	srand((int)getpid());
	while(1) {
		x = (double)rand() / ((double)RAND_MAX + 1);
		y = 2 * (double)rand() / ((double)RAND_MAX + 1);
		if( y <= ( x * x + x * x * x ) ) {
			++in;
		} else {
			++out;
		}
		if( SIG == 1 ) {
			FILE *tmp;
			int p = (int)getpid() % 4;
			char tmpname[9];
			sprintf(tmpname, "4xy.tmp%d", p);
			tmp = fopen(tmpname, "w");
			fseek(tmp,0,SEEK_SET);
			fprintf(tmp,"%lld %lld\n",in ,out);
			++SIG;
			fclose(tmp);
		} else if ( SIG == 3 ) {
			FILE *tmp;
			int p = (int)getpid() % 4;
			char tmpname[9];
			sprintf(tmpname, "4xy.tmp%d", p);
			tmp = fopen(tmpname, "w");
			fseek(tmp,0,SEEK_SET);
			fprintf(tmp,"%lld %lld\n",in ,out);
			++SIG;
			fclose(tmp);
			break;
		}
	}

	exit(0);
}
