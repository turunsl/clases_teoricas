#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
sem_t s1;
sem_t s2;
sem_t s3;
void *h1(){
	printf ("esperando por h2 y h3.... \n");
	sem_post(&s1);
	sem_post(&s1);
	sem_wait(&s2);
	sem_wait(&s3);
	printf ("ya termino la espera de h1 .... \n");
	pthread_exit(NULL);
}	

void *h2(){
	printf ("esperando por h1 y h3.... \n");
	sem_post(&s2);
	sem_post(&s2);
	sem_wait(&s1);
	sem_wait(&s3);
	printf ("ya termino la espera de h2 .... \n");
	pthread_exit(NULL);
}	
void *h3(){
	sleep(3);
	printf ("esperando por h1 y h2.... \n");
	sem_post(&s3);
	sem_post(&s3);
	sem_wait(&s1);
	sem_wait(&s2);
	printf ("ya termino la espera de h3 .... \n");
	pthread_exit(NULL);
}	
int main (){
	pthread_t tid1, tid2, tid3;
	sem_init(&s1,0,0); //valor inicial 0
	sem_init(&s2,0,0); //valor inicial 0
	sem_init(&s3,0,0); //valor inicial 0
	pthread_create(&tid1,NULL,h1,NULL );
	pthread_create(&tid2,NULL,h2,NULL );
	pthread_create(&tid3,NULL,h3,NULL );
	pthread_join(tid1,NULL); //primer problema de serializ
	pthread_join(tid2,NULL); //primer problema de serializ
	pthread_join(tid3,NULL); //primer problema de serializ
	printf ("Terminaron los hilos ... \n");
	return 0;
}
