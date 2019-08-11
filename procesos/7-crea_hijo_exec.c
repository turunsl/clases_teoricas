#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int retorna;
	printf("soy el proceso %d, y mi padre es %d \n",getpid(),getppid());
	retorna = fork(); //para que sirve lo que retorna fork ?
	if (retorna == 0){ //codigo del hijo
		sleep(1);
		printf("soy tu hijo .. proceso %d .... y ahora hare otra cosa\n", getpid());
		execlp("ps", "ps", "-fea", NULL);
		printf("hijo terminando..."); //y esto donde sale ?
		return 0; //termina el codigo del hijo ... no el del padre
	}
	printf("soy tu padre\n");
	wait(NULL); //espera hasta que el hijo termine
return 0; 
}
