#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int buffer = 0;
sem_t prod;
sem_t lugar;
pthread_mutex_t exc;
void *productor(){
	while (1){
		usleep(50);
		sem_wait(&lugar);
		pthread_mutex_lock(&exc);
		buffer = buffer + 1;
		pthread_mutex_unlock(&exc);
		printf ("Prod: el buffer es: %d \n", buffer);
		sem_post(&prod);
	}
	pthread_exit(NULL);
}	

void *consumidor(){
	while (1){
		sem_wait(&prod);
		pthread_mutex_lock(&exc);
		buffer = buffer - 1;
		pthread_mutex_unlock(&exc);
		printf ("Cons: el buffer es: %d \n", buffer);
		sem_post(&lugar);
	}
	pthread_exit(NULL);
}	
int main (){
	pthread_t tid1, tid2;
	pthread_mutex_init(&exc,NULL);
	sem_init(&prod,0,0); //valor inicial 0
	sem_init(&lugar,0,6); //valor inicial 6
	pthread_create(&tid1,NULL,productor,NULL );
	pthread_create(&tid2,NULL,consumidor,NULL );
	pthread_join(tid1,NULL); //primer problema de serializ
	pthread_join(tid2,NULL); //primer problema de serializ
	printf ("terminaron los hilos\n");
	return 0;
}
