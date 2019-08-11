#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int retorna;
	retorna = fork(); //para que sirve lo que retorna fork ?
	printf("soy el proceso %d, y mi padre es %d y fork retorna %d \n",getpid(),getppid(), retorna);
	if (retorna == 0){ //codigo del hijo
		sleep(1);
		printf("soy tu hijo\n");
		return 0; //termina el codigo del hijo ... no el del padre
	}
	printf("soy tu padre\n");
	wait(NULL); //espera hasta que el hijo termine
return 0; 
}
