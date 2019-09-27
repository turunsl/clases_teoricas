#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int saldo = 100;
pthread_mutex_t ocupado;
 void *deposita() {
	 int i;
	 for ( i=0; i<10000;i++){
		pthread_mutex_lock(&ocupado);
	 	saldo = saldo + 1;
		pthread_mutex_unlock(&ocupado);
	}
	pthread_exit(NULL);
 }
 void *retira() {
	 int i;
	 for ( i=0; i<10000;i++){
		pthread_mutex_lock(&ocupado);
	        saldo = saldo - 1;
		pthread_mutex_unlock(&ocupado);
	}
	pthread_exit(NULL);
 }
int main(){
	pthread_mutex_init(&ocupado, NULL);
	pthread_t tid[2];
	pthread_create( &tid[0], NULL , deposita, NULL);
	pthread_create( &tid[1], NULL , retira, NULL);
	pthread_join(tid[0] ,NULL);
	pthread_join(tid[1] ,NULL);
	printf ("terminaron todos los hilos, el saldo es %d \n",saldo);
	return 0;
}
