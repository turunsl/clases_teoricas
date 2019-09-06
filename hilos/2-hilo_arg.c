#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
 void *rutina(void * dato) {
	printf ("soy el hilo rutina del proc %d \n", getpid() );
	printf ("el argumento que me pasaste es %ld\n", (long)dato );
	sleep(2);
	pthread_exit(NULL);
 }

int main(){
	pthread_t tid;
	int retorno;
	long dato = 5;
	printf ("soy el  proceso %d \n", getpid() );
	retorno = pthread_create( &tid, NULL , rutina , (void *)dato);
	if ( retorno != 0 ){
		printf ("dio error \n");
		return -1;
	}
	pthread_join( tid , NULL );
	printf ("terminaron todos los hilos\n");	
	return 0;
}
