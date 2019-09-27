#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
int saldo = 100;
sem_t ocupado;
 void *deposita() {
	 int i;
	 for ( i=0; i<10000;i++){
		 sem_wait(&ocupado);
	 	saldo = saldo + 1;
		 sem_post(&ocupado);
	}
	pthread_exit(NULL);
 }
 void *retira() {
	 int i;
	 for ( i=0; i<10000;i++){
		 sem_wait(&ocupado);
	 	saldo = saldo - 1;
		 sem_post(&ocupado);
	}
	pthread_exit(NULL);
 }
int main(){
	sem_init (&ocupado, 0, 1);
	pthread_t tid[2];
	pthread_create( &tid[0], NULL , deposita, NULL);
	pthread_create( &tid[1], NULL , retira, NULL);
	pthread_join(tid[0] ,NULL);
	pthread_join(tid[1] ,NULL);
	printf ("terminaron todos los hilos, el saldo es %d \n",saldo);
	return 0;
}
