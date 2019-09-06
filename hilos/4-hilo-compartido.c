#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
int valor = 100;
 void *rutina0() {
	 valor = valor + 10;
	pthread_exit(NULL);
 }
 void *rutina1() {
	 printf("valor final = %d \n", valor );
	pthread_exit(NULL);
 }
int main(){
	pthread_t tid[2];
	pthread_create( &tid[0], NULL , rutina0, NULL);
	pthread_join(tid[0] ,NULL);
	pthread_create( &tid[1], NULL , rutina1, NULL);
	pthread_join(tid[1] ,NULL);
	printf ("ya terminaron todos los hilos \n");
	return 0;
}
