#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/signal.h>
#define MAXLINE 80			// The maximum length command

struct history {
	char line[MAXLINE];
	struct history *next;
};

void print_history(struct history *ptr ,int n) {
	if( ptr->next != NULL ) {
		print_history(ptr->next,n+1);
	}
	if( ptr->line != NULL && strlen(ptr->line) > 0 ) {
		printf("%d: %s\n",n,ptr->line);
	}
}

struct history* get_history(struct history *ptr ,int n) {
	while( ptr->next != NULL && n) {
		ptr = ptr->next;
		--n;
	}
	return ptr;
}

void sig_fork() {
	waitpid(-1,NULL,WNOHANG);
}

int main(int argc ,char **argv) {
	signal(SIGCHLD,sig_fork);
	struct history *history = malloc(sizeof(struct history)) ,*head ,*ptr ;
	history->next = NULL;

	char *args[MAXLINE]; 	// command line arguments
	int run = 1;			// flag to determine when to exit program
	while(run) {
		printf(">");
		fflush(stdout);

		char line[MAXLINE];
		if( !fgets(line,MAXLINE,stdin) || ferror(stdin) || feof(stdin) ) {
			return 0;
		}

		args[0] = strtok(line,"\n");						// Get command line
		if( args[0] == NULL || strlen(args[0]) <= 0 ) {
			continue;
		}

		head = malloc(sizeof(struct history));				// Store command into history
		strcpy(head->line,args[0]);
		head->next = history;
		history = head;

		int i = 1 ,j = 0 ,wpid = 1;
		args[0] = strtok(line," \n");						// Split command into args
		while( (args[i] = strtok(NULL," \n")) != NULL ) {
			++i;
		}
		args[i] = NULL;


		if( args[0] == NULL ) {
			ptr = head;
			head = head->next;
			history = head;
			free(ptr);
			continue;
		}

		if( strcmp(args[0],"exit") == 0 ) {
			return 0;
		}

		if( strcmp(args[0],"history") == 0 ) {
			if( args[1] == NULL ) {
				print_history(head->next,1);
				ptr = head;
				head = head->next;
				history = head;
				free(ptr);
				continue;
			}
			else if( strcmp(args[1],"!!") == 0 ) {
				strcpy(line,head->next->line);
				strcpy(head->line,head->next->line);

				i = 1;
				args[0] = strtok(line," \n");
				while( (args[i] = strtok(NULL," \n")) != NULL ) {
					++i;
				}
				args[i] = NULL;
			}
			else if( args[1][0] == '!' ) {
				int k = atoi(&args[1][1]);
				ptr = get_history(head,k);
				strcpy(line,ptr->line);
				strcpy(head->line,ptr->line);

				i = 1;
				args[0] = strtok(line," \n");
				while( (args[i] = strtok(NULL," \n")) != NULL ) {
					++i;
				}
				args[i] = NULL;
			}
		}

		/*	compute each command spilt by &	*/
		for(j = 0; j < i; ++j) {
			char *command = NULL ,*params[MAXLINE];

			int k = 0;
			if( command == NULL ) {
				command = args[j];
				params[k++] = args[j++];
			}

			while( args[j] != NULL && strcmp(args[j],"&") != 0 ) {
				params[k++] = args[j++];
			}

			if( args[j] != NULL && strcmp(args[j],"&") == 0 ) {
				wpid = 0;
			}

			params[k] = NULL;

			pid_t pid;
			if( (pid = fork()) == 0 ) {
				if( execvp(command,params) == -1 ) {
					fprintf(stderr,"undefined command\n");
				}
				return 0;
			}

			if(wpid) {
				wait(&pid);
			}
		}
	}
	return 0;
}
