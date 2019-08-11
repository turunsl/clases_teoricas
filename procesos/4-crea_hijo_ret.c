#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int retorna;
	printf("soy tu padre\n");
	retorna = fork(); //para que sirve lo que retorna fork ?
	printf("soy el proceso %d, y mi padre es %d y fork retorna %d \n",getpid(),getppid(), retorna);
	sleep(10);
return 0; 
}
