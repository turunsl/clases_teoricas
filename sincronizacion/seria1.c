#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int cantidad = 0;
sem_t sema;
void *productor(){
	cantidad = cantidad + 10;
	printf ("Prod: la cantidad es: %d \n", cantidad);
	sleep(2);
	sem_post(&sema);
	pthread_exit(NULL);
}	

void *consumidor(){
	//sleep(1);//segunda serializ
	sem_wait(&sema);
	cantidad = cantidad - 5;
	printf ("Cons: la cantidad es: %d \n", cantidad);
	pthread_exit(NULL);
}	
int main (){
	pthread_t tid1, tid2;
	sem_init(&sema,0,0); //valor inicial 0
	pthread_create(&tid1,NULL,productor,NULL );
	pthread_create(&tid2,NULL,consumidor,NULL );
	pthread_join(tid1,NULL); //primer problema de serializ
	pthread_join(tid2,NULL); //primer problema de serializ
	printf ("la cantidad final es: %d \n", cantidad);
	return 0;
}
