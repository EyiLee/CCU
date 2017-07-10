#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define MAXLINE 1024

int value[20], second[20];
void *MultiSorting(void **args);
void *MergeSorting(void **args);

int main(int argc, char *argv[])
{

/* initialize sorting arrays */
	int i;
	for(i=0 ;i<20 ;i++) {
		value[i] = 0, second[i] = 0;
	}

/* read line from stdio */
	char line[MAXLINE];
	if( !fgets(line ,MAXLINE ,stdin) || ferror(stdin) || feof(stdin) ) {
		return 0;
	}

/* take numbers up to 20 */
	int n = 0;
	char *p;
	p = strtok(line," \n");
	value[n++] = atoi(p);
	while((p = strtok(NULL," \n")) != NULL) {
		value[n++] = atoi(p);
	}
	if(n > 20 || n < 2) {
		fprintf(stderr,"Please input 2~20 numbers\n");
		return;
	}

/* initialize args */
	void *args1[4];
	int from1 = 0, to1 = n/2-1;
	args1[0] = value ,args1[1] = second ,args1[2] = (void *)&from1 ,args1[3] = (void *)&to1;

	void *args2[4];
	int from2 = n/2, to2 = n-1;
	args2[0] = value ,args2[1] = second ,args2[2] = (void *)&from2 ,args2[3] = (void *)&to2;

/* create two MultiSoring thread */
	pthread_t pid,tid[2];
	if(pthread_create(&tid[0] ,pthread_attr_default ,(void *)MultiSorting ,args1)) {
		fprintf(stderr,"can't build a new thread!\n");
	}

	if(pthread_create(&tid[1] ,pthread_attr_default ,(void *)MultiSorting ,args2)) {
		fprintf(stderr,"can't build a new thread!\n");
	}
	pthread_join(tid[0] ,NULL);
	pthread_join(tid[1] ,NULL);

/* print two MultiSorting thread result */
	printf("\nSorting Thread 0:\n-->");
	for(i=0 ;i<n/2 ;i++) {
		printf("%d ",second[i]);
	}
	printf("\nSorting Thread 1:\n-->");
	for(i=n/2 ;i<n ;i++) {
		printf("%d ",second[i]);
	}
	printf("\n");

/* initialize args */
	void *args3[3];
	args3[0] = value ,args3[1] = second ,args3[2] = (void *)&n;

/* merge two MultiSorting thread */
	if(pthread_create(&pid ,pthread_attr_default ,(void *)MergeSorting ,args3)) {
		fprintf(stderr,"can't build a new thread!\n");
	}
	pthread_join(pid ,NULL);

/* print Sorted List */
	printf("\nSorted List:\n-->");
	for(i=0 ;i<n ;i++) {
		printf("%d ",value[i]);
	}
	printf("\n");

	return 0;
}

void *MultiSorting(void **args) {
	int *main = (int *)args[0];
	int *sub = (int *)args[1];
	int *from = (int *)args[2];
	int *to = (int *)args[3];

	int i ,j ,temp;
	for(i=0 ;i<*to-*from+1 ;i++) {
		for(j=*from ;j<*to-i ;j++) {
			if(main[j] > main[j+1]) {
				temp = main[j];
				main[j] = main[j+1];
				main[j+1] = temp;
			}
		}
	}

	for(i=*from ;i<=*to ;i++) {
		sub[i] = main[i];
	}

	pthread_exit(0);
}

void *MergeSorting(void **args) {
	int *main = (int *)args[0];
	int *sub = (int *)args[1];
	int *num = (int *)args[2];
	int n1 = *num/2-1 ,n2 = *num-1;
	int i = 0 ,j = *num/2;
	int k = 0;

	while(i <= n1 && j <= n2) {
		if(sub[i] < sub[j]) {
			main[k++] = sub[i++];
		}
		else {
			main[k++] = sub[j++];
		}
	}

	while(i <= n1) {
		main[k++] = sub[i++];
	}

	while(j <= n2) {
		main[k++] = sub[j++];
	}

	pthread_exit(0);
}
