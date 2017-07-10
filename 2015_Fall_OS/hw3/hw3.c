#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int run = 1;
int TAavailble = 1;
int STUavailble[8] = {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1};
int meeting = 0;
int chair[3] = {0 ,0 ,0};

pthread_mutex_t mutex;

void *roundtime() {
	sleep(30);
	pthread_mutex_lock(&mutex);
	run = 0;
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

void *TAthread() {
	int time;
	while(run) {
		if(!TAavailble) {
			pthread_mutex_lock(&mutex);
			if(chair[0] != 0) {
				meeting = chair[0];
				chair[0] = chair[1];
				chair[1] = chair[2];
				chair[2] = 0;
				time = rand() % 7;
				printf("TA is helping student: %d for %d seconds\n" ,meeting ,time);
			}
			else {
				time = rand() % 7;
				printf("TA is helping student: %d for %d seconds\n" ,meeting ,time);
				TAavailble = 1;
			}
			pthread_mutex_unlock(&mutex);
			if(chair[0]) {
				printf("student %d is sitting on chair %d\n" ,chair[0] ,1);
			}
			if(chair[1]) {
				printf("student %d is sitting on chair %d\n" ,chair[1] ,2);
			}
			if(chair[2]) {
				printf("student %d is sitting on chair %d\n" ,chair[2] ,3);
			}
		}
		else {
			printf("TA is sleeping\n");
		}
		if(meeting) {
			pthread_mutex_lock(&mutex);
			STUavailble[meeting] = 1;
			pthread_mutex_unlock(&mutex);
		}
		else {
			time = 3;
		}
		sleep(time);
	}
	pthread_exit(0);
}

void *STUthread(int *id) {
	int act = 0;
	while(run) {
		if(STUavailble[*id]) {
			act = rand(NULL) % 6;
			if(act == 0) {
				pthread_mutex_lock(&mutex);
				if(TAavailble) {
					TAavailble = 0;
					STUavailble[*id] = 0;
					meeting = *id;
				}
				else {
					if(chair[0] == 0) {
						chair[0] = *id;
						STUavailble[*id] = 0;
					}
					else if(chair[1] == 0) {
						chair[1] = *id;
						STUavailble[*id] = 0;
					}
					else if(chair[2] == 0) {
						chair[2] = *id;
						STUavailble[*id] = 0;
					}
				}
				pthread_mutex_unlock(&mutex);
			}
		}
	}
	pthread_exit(0);
}

int main(int argc ,char **argv) {

	pthread_mutex_init(&mutex,NULL);

	int i;
	int id[8] = {1,2,3,4,5,6,7,8};
	pthread_t time,ta,stu[8];
	pthread_create(&time ,pthread_attr_default ,(void *)roundtime ,NULL);
	pthread_create(&ta ,pthread_attr_default ,(void *)TAthread ,NULL);
	for(i = 0 ;i < 8 ;i++) {
		pthread_create(&stu[i] ,pthread_attr_default ,(void *)STUthread ,&id[i]);
	}
	pthread_join(time ,NULL);

	return 0;
}
