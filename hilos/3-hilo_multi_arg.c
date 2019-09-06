#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
 void *rutina(void * dato) {
	printf ("el argumento que me pasaste es %ld\n", (long)dato );
	pthread_exit(NULL);
 }

int main(){
	pthread_t tid[6];
	long dato;
	printf ("soy el  proceso %d \n", getpid() );
	for (dato=1;dato<6;dato++){
		pthread_create( &tid[dato], NULL , rutina , (void *)dato);
	}
	for(dato=1;dato<6;dato++){
		pthread_join(tid[dato] ,NULL);
	}
	printf ("ya terminaron todos los hilos \n");
	pthread_exit(NULL);
	return 0;
}
