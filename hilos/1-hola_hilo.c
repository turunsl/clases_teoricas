#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
 void *rutina() {
	printf ("soy el hilo rutina del proc %d \n", getpid() );
	sleep(2);
	pthread_exit(NULL);
 }

int main(){
	pthread_t tid;
	int retorno;
	printf ("soy el  proceso %d \n", getpid() );
	retorno = pthread_create( &tid, NULL , rutina , NULL);
	if ( retorno != 0 ){
		printf ("dio error \n");
		return -1;
	}
	//sleep (1); //esperarmos para que el planif corra el hilo rutina
	//pthread_exit(NULL); //espera que Tooooodos los hilos terminen
	pthread_join( tid , NULL );
	printf ("terminaron todos los hilos\n");	
	return 0;
}
