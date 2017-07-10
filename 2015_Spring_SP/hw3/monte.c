#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<signal.h>
#include<termios.h>
#include<sys/wait.h>
#include<sys/types.h>

int SIGU = 0;

void donothing(int SIG) {}

void getsig(int SIG) {
	SIGU = SIG;
}

int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}

int main(int argc, char **argv) {

	int opt = 0, times = 0;
	long long dots = 0, jobs = sysconf(_SC_NPROCESSORS_ONLN);

	while( (opt = getopt(argc, argv, "n:j:t")) != -1 ) {
		switch(opt) {
			case 'n':
				dots = atoll(optarg);
				break;
			case 'j':
				jobs = atoll(optarg);
				break;
			case 't':
				times = 1;
				break;
			default:
				fprintf(stderr,"Usage: %s [-n dots] [-j jobs] [-t]\n",argv[0]);
				exit(0);
		}
	}
	
	pid_t pid, *childs;
	childs = malloc( jobs * sizeof(pid_t));
	FILE *tmp = tmpfile();

	int i = 0;
	for(i = 0; i < jobs; ++i) {
		if( (pid = fork()) == 0 ) {
			double x, y;
			long long in = 0, out = 0, j = 0;

			signal(SIGUSR1, getsig);
			
			srand(i);
			for(j = 0; j < dots / jobs; ++j) {
				x = rand() / ((double)RAND_MAX + 1);
				y = rand() / ((double)RAND_MAX + 1);
				if( x*x + y*y < 1 )
					++in;
				else
					++out;
				if( SIGU == SIGUSR1 )
					break;
			}
			while( waitpid(childs[i],NULL,WNOHANG) == 0 );
			fseek(tmp,0,SEEK_END);
			fprintf(tmp,"%lld %lld\n", in, out);
			exit(0);
		}
		else
			childs[i] = pid;
	}

	signal(SIGUSR1, donothing);

	for(i = 0; i < jobs; ++i) {
		while( waitpid(childs[i],NULL,WNOHANG) == 0 ) {
			if( kbhit() ) {
				kill(getpid()*-1,SIGUSR1);
			}
			sleep(1);
		}
	}

	fseek(tmp,0,SEEK_SET);

	long long tin, tout, sumin = 0, sumout = 0;
	while( fscanf(tmp,"%lld %lld", &tin, &tout) != EOF ) {
		sumin += tin;
		sumout += tout;
	}

	printf("\rpi: %f\n", (double)(sumin) * 4 / (double)(sumin+sumout));
	exit(0);
}
