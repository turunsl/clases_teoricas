#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("soy tu padre\n");
	fork(); //para que sirve lo que retorna fork ?
	printf("soy el proceso %d, y mi padre es %d \n",getpid(),getppid())
	sleep(10);
return 0; 
}
