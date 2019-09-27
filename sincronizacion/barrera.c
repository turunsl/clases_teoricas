#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
pthread_barrier_t barrera;
void *h1(){
	sleep(3);
	printf ("esperando por h2 h3 y h4. \n");
	pthread_barrier_wait(&barrera);
	printf ("ya termino la espera de h1 .... \n");
	pthread_exit(NULL);
}	

void *h2(){
	printf ("esperando por h1 h3 y h4. \n");
	pthread_barrier_wait(&barrera);
	printf ("ya termino la espera de h2 .... \n");
	pthread_exit(NULL);
}	
void *h3(){
	printf ("esperando por h1 , h2 y h4\n");
	pthread_barrier_wait(&barrera);
	printf ("ya termino la espera de h3 .... \n");
	pthread_exit(NULL);
}	
void *h4(){
	printf ("esperando por h1 h2 y h3. \n");
	pthread_barrier_wait(&barrera);
	printf ("ya termino la espera de h4 .... \n");
	pthread_exit(NULL);
}	
int main (){
	pthread_t tid1, tid2, tid3, tid4;
	pthread_barrier_init(&barrera,NULL, 4);
	pthread_create(&tid1,NULL,h1,NULL );
	pthread_create(&tid2,NULL,h2,NULL );
	pthread_create(&tid3,NULL,h3,NULL );
	pthread_create(&tid4,NULL,h4,NULL );
	pthread_join(tid1,NULL); //primer problema de serializ
	pthread_join(tid2,NULL); //primer problema de serializ
	pthread_join(tid3,NULL); //primer problema de serializ
	pthread_join(tid4,NULL); //primer problema de serializ
	printf ("Terminaron los hilos ... \n");
	return 0;
}
