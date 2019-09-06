#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int saldo = 100;
 void *deposita() {
	 int i;
	 for ( i=0; i<10000;i++){
	 	saldo = saldo + 1;
	}
	pthread_exit(NULL);
 }
 void *retira() {
	 int i;
	 for ( i=0; i<10000;i++){
	 	saldo = saldo - 1;
	}
	pthread_exit(NULL);
 }
int main(){
	pthread_t tid[2];
	pthread_create( &tid[0], NULL , deposita, NULL);
	pthread_create( &tid[1], NULL , retira, NULL);
	pthread_join(tid[0] ,NULL);
	pthread_join(tid[1] ,NULL);
	printf ("terminaron todos los hilos, el saldo es %d \n",saldo);
	return 0;
}
