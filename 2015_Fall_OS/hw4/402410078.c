#include<stdio.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>

int run = 1;
int chopsticks[5] = {0 ,0 ,0 ,0 ,0};

pthread_mutex_t mutex ,mutexc;
pthread_cond_t cond[5];

void roundtime() {
	sleep(30);
	pthread_mutex_lock(&mutex);
	run = 0;
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

void philosophers(int *id) {
	int i = *id;
	while(run) {
		int t = rand() % 3 + 1;
		printf("Philosophers %d is thinking!\n" ,i ,t);
		sleep(t);
        
        pthread_mutex_lock(&mutex);
        if(chopsticks[i] == 0 && chopsticks[(i + 1) % 5] == 0) {
            pthread_mutex_lock(&mutex);
            chopsticks[i] = 1;
            chopsticks[(i + 1) % 5] = 1;
            pthread_mutex_unlock(&mutex);
        } else {
            while(chopsticks[i] == 1) {
                pthread_cond_wait(&cond[i] ,&mutex);
                pthread_mutex_lock(&mutex);
                if(chopsticks[i] == 0) {
                    chopsticks[i] = 1;
                }
                pthread_mutex_unlock(&mutex);
                break;
            }
            while(chopsticks[(i + 1) % 5] == 1) {
                pthread_cond_wait(&cond[(i + 1) % 5] ,&mutex);
                pthread_mutex_lock(&mutex);
                if(chopsticks[(i + 1) % 5] == 0) {
                    chopsticks[(i + 1) % 5] = 1;
                }
                pthread_mutex_unlock(&mutex);
                break;
            }
        }
		pthread_mutex_unlock(&mutex);

		t = rand() % 3 + 1;
		printf("\tPhilosophers %d is eating! %d sec\n",i ,t);
		sleep(t);
        printf("\t\tPhilosophers %d has eaten!\n" ,i);
        
		pthread_mutex_lock(&mutex);
        chopsticks[i] = 0;
        chopsticks[(i + 1) % 5] = 0;
        pthread_cond_signal(&cond[i]);
        pthread_cond_signal(&cond[(i + 1) % 5]);
        pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}

int main(int argc ,char **argv) {

	int i;
	pthread_mutex_init(&mutex ,NULL);
    pthread_mutex_init(&mutexc ,NULL);
	for(i = 0 ;i < 5 ;++i) {
		pthread_cond_init(&cond[i] ,NULL);
	}

	int id[5] = {0 ,1 ,2 ,3 ,4};
	pthread_t time ,phi[5];
	pthread_create(&time ,pthread_attr_default ,(void *)&roundtime ,NULL);

    
	for(i = 0 ;i < 5 ;i++) {
		pthread_create(&phi[i] ,pthread_attr_default ,(void *)&philosophers ,&id[i]);
	}
    
	pthread_join(time ,NULL);

	return 0;
}
